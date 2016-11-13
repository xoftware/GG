//===-- pnacl-llc.cpp - PNaCl-specific llc: pexe ---> nexe  ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// pnacl-llc: the core of the PNaCl translator, compiling a pexe into a nexe.
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Triple.h"
#include "llvm/Analysis/NaCl.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/Assembly/PrintModulePass.h"
#include "llvm/Bitcode/NaCl/NaClReaderWriter.h"
#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/CodeGen/LinkAllAsmWriterComponents.h"
#include "llvm/CodeGen/LinkAllCodegenComponents.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/MC/SubtargetFeature.h"
#include "llvm/Pass.h"
#include "llvm/PassManager.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Target/TargetLibraryInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/NaCl.h"
#include <memory>


using namespace llvm;

// NOTE: When __native_client__ is defined it means pnacl-llc is built as a
// sandboxed translator (from pnacl-llc.pexe to pnacl-llc.nexe). In this mode
// it uses SRPC operations instead of direct OS intefaces.
#if defined(__native_client__)
int srpc_main(int argc, char **argv);
int getObjectFileFD();
DataStreamer *getNaClBitcodeStreamer();
fatal_error_handler_t getSRPCErrorHandler();
#endif

cl::opt<NaClFileFormat>
InputFileFormat(
    "bitcode-format",
    cl::desc("Define format of input file:"),
    cl::values(
        clEnumValN(LLVMFormat, "llvm", "LLVM file (default)"),
        clEnumValN(PNaClFormat, "pnacl", "PNaCl bitcode file"),
        clEnumValEnd),
    cl::init(LLVMFormat));

// General options for llc.  Other pass-specific options are specified
// within the corresponding llc passes, and target-specific options
// and back-end code generation options are specified with the target machine.
//
static cl::opt<std::string>
InputFilename(cl::Positional, cl::desc("<input bitcode>"), cl::init("-"));

static cl::opt<std::string>
OutputFilename("o", cl::desc("Output filename"), cl::value_desc("filename"));

// Using bitcode streaming has a couple of ramifications. Primarily it means
// that the module in the file will be compiled one function at a time rather
// than the whole module. This allows earlier functions to be compiled before
// later functions are read from the bitcode but of course means no whole-module
// optimizations. For now, streaming is only supported for files and stdin.
static cl::opt<bool>
LazyBitcode("streaming-bitcode",
  cl::desc("Use lazy bitcode streaming for file inputs"),
  cl::init(false));

// The option below overlaps very much with bitcode streaming.
// We keep it separate because it is still experimental and we want
// to use it without changing the outside behavior which is especially
// relevant for the sandboxed case.
static cl::opt<bool>
ReduceMemoryFootprint("reduce-memory-footprint",
  cl::desc("Aggressively reduce memory used by pnacl-llc"),
  cl::init(false));

static cl::opt<bool>
PNaClABIVerify("pnaclabi-verify",
  cl::desc("Verify PNaCl bitcode ABI before translating"),
  cl::init(false));
static cl::opt<bool>
PNaClABIVerifyFatalErrors("pnaclabi-verify-fatal-errors",
  cl::desc("PNaCl ABI verification errors are fatal"),
  cl::init(false));

// Determine optimization level.
static cl::opt<char>
OptLevel("O",
         cl::desc("Optimization level. [-O0, -O1, -O2, or -O3] "
                  "(default = '-O2')"),
         cl::Prefix,
         cl::ZeroOrMore,
         cl::init(' '));

static cl::opt<std::string>
UserDefinedTriple("mtriple", cl::desc("Set target triple"));

cl::opt<bool> NoVerify("disable-verify", cl::Hidden,
                       cl::desc("Do not verify input module"));

cl::opt<bool>
DisableSimplifyLibCalls("disable-simplify-libcalls",
                        cl::desc("Disable simplify-libcalls"),
                        cl::init(false));

/// Compile the module provided to pnacl-llc. The file name for reading the
/// module and other options are taken from globals populated by command-line
/// option parsing.
static int compileModule(StringRef ProgramName, LLVMContext &Context);

// GetFileNameRoot - Helper function to get the basename of a filename.
static std::string
GetFileNameRoot(StringRef InputFilename) {
  std::string IFN = InputFilename;
  std::string outputFilename;
  int Len = IFN.length();
  if ((Len > 2) &&
      IFN[Len-3] == '.' &&
      ((IFN[Len-2] == 'b' && IFN[Len-1] == 'c') ||
       (IFN[Len-2] == 'l' && IFN[Len-1] == 'l'))) {
    outputFilename = std::string(IFN.begin(), IFN.end()-3); // s/.bc/.s/
  } else {
    outputFilename = IFN;
  }
  return outputFilename;
}

static tool_output_file *GetOutputStream(const char *TargetName,
                                         Triple::OSType OS) {
  // If we don't yet have an output filename, make one.
  if (OutputFilename.empty()) {
    if (InputFilename == "-")
      OutputFilename = "-";
    else {
      OutputFilename = GetFileNameRoot(InputFilename);

      switch (FileType) {
      case TargetMachine::CGFT_AssemblyFile:
        if (TargetName[0] == 'c') {
          if (TargetName[1] == 0)
            OutputFilename += ".cbe.c";
          else if (TargetName[1] == 'p' && TargetName[2] == 'p')
            OutputFilename += ".cpp";
          else
            OutputFilename += ".s";
        } else
          OutputFilename += ".s";
        break;
      case TargetMachine::CGFT_ObjectFile:
        if (OS == Triple::Win32)
          OutputFilename += ".obj";
        else
          OutputFilename += ".o";
        break;
      case TargetMachine::CGFT_Null:
        OutputFilename += ".null";
        break;
      }
    }
  }

  // Decide if we need "binary" output.
  bool Binary = false;
  switch (FileType) {
  case TargetMachine::CGFT_AssemblyFile:
    break;
  case TargetMachine::CGFT_ObjectFile:
  case TargetMachine::CGFT_Null:
    Binary = true;
    break;
  }

  // Open the file.
  std::string error;
  unsigned OpenFlags = 0;
  if (Binary) OpenFlags |= raw_fd_ostream::F_Binary;
  OwningPtr<tool_output_file> FDOut(
      new tool_output_file(OutputFilename.c_str(), error, OpenFlags));
  if (!error.empty()) {
    errs() << error << '\n';
    return 0;
  }

  return FDOut.take();
}

// main - Entry point for the llc compiler.
//
int llc_main(int argc, char **argv) {
  sys::PrintStackTraceOnErrorSignal();
  PrettyStackTraceProgram X(argc, argv);

  // Enable debug stream buffering.
  EnableDebugBuffering = true;

  LLVMContext &Context = getGlobalContext();
  llvm_shutdown_obj Y;  // Call llvm_shutdown() on exit.

#if defined(__native_client__)
  install_fatal_error_handler(getSRPCErrorHandler(), NULL);
#endif

  // Initialize targets first, so that --version shows registered targets.
  InitializeAllTargets();
  InitializeAllTargetMCs();
  InitializeAllAsmPrinters();
#if !defined(__native_client__)
  // Prune asm parsing from sandboxed translator.
  // Do not prune "AsmPrinters" because that includes
  // the direct object emission.
  InitializeAllAsmParsers();
#endif

  // Initialize codegen and IR passes used by pnacl-llc so that the -print-after,
  // -print-before, and -stop-after options work.
  PassRegistry *Registry = PassRegistry::getPassRegistry();
  initializeCore(*Registry);
  initializeCodeGen(*Registry);
  initializeLoopStrengthReducePass(*Registry);
  initializeLowerIntrinsicsPass(*Registry);
  initializeUnreachableBlockElimPass(*Registry);

  // Register the target printer for --version.
  cl::AddExtraVersionPrinter(TargetRegistry::printRegisteredTargetsForVersion);

  // Enable the PNaCl ABI verifier by default in sandboxed mode.
#if defined(__native_client__)
  PNaClABIVerify = true;
  PNaClABIVerifyFatalErrors = true;
#endif

  cl::ParseCommandLineOptions(argc, argv, "pnacl-llc\n");

  return compileModule(argv[0], Context);
}

static void CheckABIVerifyErrors(PNaClABIErrorReporter &Reporter,
                                 const Twine &Name) {
  if (PNaClABIVerify && Reporter.getErrorCount() > 0) {
    std::string errors;
    raw_string_ostream os(errors);
    os << (PNaClABIVerifyFatalErrors ? "ERROR: " : "WARNING: ");
    os << Name << " is not valid PNaCl bitcode:\n";
    Reporter.printErrors(os);
    if (PNaClABIVerifyFatalErrors) {
      report_fatal_error(os.str());
    }
    errs() << os.str();
  }
  Reporter.reset();
}

static int compileModule(StringRef ProgramName, LLVMContext &Context) {
  // Load the module to be compiled...
  SMDiagnostic Err;
  std::auto_ptr<Module> M;
  Module *mod = 0;
  Triple TheTriple;

  PNaClABIErrorReporter ABIErrorReporter;

#if defined(__native_client__)
  if (LazyBitcode) {
    std::string StrError;
    std::string DisplayFilename("<PNaCl-translated pexe>");
    M.reset(getNaClStreamedBitcodeModule(
        DisplayFilename,
        getNaClBitcodeStreamer(), Context, &StrError));
    if (!StrError.empty())
      Err = SMDiagnostic(DisplayFilename, SourceMgr::DK_Error, StrError);
  } else {
    llvm_unreachable("native client SRPC only supports streaming");
  }
#else
  M.reset(NaClParseIRFile(InputFilename, InputFileFormat, Err, Context));
#endif // __native_client__

  mod = M.get();
  if (mod == 0) {
#if defined(__native_client__)
    report_fatal_error(Err.getMessage());
#else
    // Err.print is prettier, so use it for the non-sandboxed translator.
    Err.print(ProgramName.data(), errs());
    return 1;
#endif
  }

  if (PNaClABIVerify) {
    // Verify the module (but not the functions yet)
    ModulePass *VerifyPass = createPNaClABIVerifyModulePass(&ABIErrorReporter,
                                                            LazyBitcode);
    VerifyPass->runOnModule(*mod);
    CheckABIVerifyErrors(ABIErrorReporter, "Module");
  }

  // Add declarations for external functions required by PNaCl. The
  // ResolvePNaClIntrinsics function pass running during streaming
  // depends on these declarations being in the module.
  OwningPtr<ModulePass> AddPNaClExternalDeclsPass(
      createAddPNaClExternalDeclsPass());
  AddPNaClExternalDeclsPass->runOnModule(*mod);

  if (UserDefinedTriple.empty()) {
    report_fatal_error("-mtriple must be set to a target triple for pnacl-llc");
  } else {
    mod->setTargetTriple(Triple::normalize(UserDefinedTriple));
    TheTriple = Triple(mod->getTargetTriple());
  }

  // Get the target specific parser.
  std::string Error;
  const Target *TheTarget = TargetRegistry::lookupTarget(MArch, TheTriple,
                                                         Error);
  if (!TheTarget) {
    errs() << ProgramName << ": " << Error;
    return 1;
  }

  // Package up features to be passed to target/subtarget
  std::string FeaturesStr;
  if (MAttrs.size()) {
    SubtargetFeatures Features;
    for (unsigned i = 0; i != MAttrs.size(); ++i)
      Features.AddFeature(MAttrs[i]);
    FeaturesStr = Features.getString();
  }

  CodeGenOpt::Level OLvl = CodeGenOpt::Default;
  switch (OptLevel) {
  default:
    errs() << ProgramName << ": invalid optimization level.\n";
    return 1;
  case ' ': break;
  case '0': OLvl = CodeGenOpt::None; break;
  case '1': OLvl = CodeGenOpt::Less; break;
  case '2': OLvl = CodeGenOpt::Default; break;
  case '3': OLvl = CodeGenOpt::Aggressive; break;
  }

  TargetOptions Options;
  Options.LessPreciseFPMADOption = EnableFPMAD;
  Options.NoFramePointerElim = DisableFPElim;
  Options.NoFramePointerElimNonLeaf = DisableFPElimNonLeaf;
  Options.AllowFPOpFusion = FuseFPOps;
  Options.UnsafeFPMath = EnableUnsafeFPMath;
  Options.NoInfsFPMath = EnableNoInfsFPMath;
  Options.NoNaNsFPMath = EnableNoNaNsFPMath;
  Options.HonorSignDependentRoundingFPMathOption =
      EnableHonorSignDependentRoundingFPMath;
  Options.UseSoftFloat = GenerateSoftFloatCalls;
  if (FloatABIForCalls != FloatABI::Default)
    Options.FloatABIType = FloatABIForCalls;
  Options.NoZerosInBSS = DontPlaceZerosInBSS;
  Options.GuaranteedTailCallOpt = EnableGuaranteedTailCallOpt;
  Options.DisableTailCalls = DisableTailCalls;
  Options.StackAlignmentOverride = OverrideStackAlignment;
  Options.RealignStack = EnableRealignStack;
  Options.TrapFuncName = TrapFuncName;
  Options.PositionIndependentExecutable = EnablePIE;
  Options.EnableSegmentedStacks = SegmentedStacks;
  Options.UseInitArray = UseInitArray;
  Options.SSPBufferSize = SSPBufferSize;

  std::auto_ptr<TargetMachine>
    target(TheTarget->createTargetMachine(TheTriple.getTriple(),
                                          MCPU, FeaturesStr, Options,
                                          RelocModel, CMModel, OLvl));
  assert(target.get() && "Could not allocate target machine!");
  assert(mod && "Should have exited after outputting help!");
  TargetMachine &Target = *target.get();

  if (GenerateSoftFloatCalls)
    FloatABIForCalls = FloatABI::Soft;

#if !defined(__native_client__)
  // Figure out where we are going to send the output.
  OwningPtr<tool_output_file> Out
    (GetOutputStream(TheTarget->getName(), TheTriple.getOS()));
  if (!Out) return 1;
#endif

  // Build up all of the passes that we want to do to the module.
  OwningPtr<PassManagerBase> PM;
  if (LazyBitcode || ReduceMemoryFootprint)
    PM.reset(new FunctionPassManager(mod));
  else
    PM.reset(new PassManager());

  // For conformance with llc, we let the user disable LLVM IR verification with
  // -disable-verify. Unlike llc, when LLVM IR verification is enabled we only
  // run it once, before PNaCl ABI verification.
  if (!NoVerify) {
    PM->add(createVerifierPass());
  }

  // Add the ABI verifier pass before the analysis and code emission passes.
  if (PNaClABIVerify) {
    PM->add(createPNaClABIVerifyFunctionsPass(&ABIErrorReporter));
  }

  // Add the intrinsic resolution pass. It assumes ABI-conformant code.
  PM->add(createResolvePNaClIntrinsicsPass());

  // Add an appropriate TargetLibraryInfo pass for the module's triple.
  TargetLibraryInfo *TLI = new TargetLibraryInfo(TheTriple);
  if (DisableSimplifyLibCalls)
    TLI->disableAllFunctions();
  PM->add(TLI);

  // Add intenal analysis passes from the target machine.
  Target.addAnalysisPasses(*PM.get());

  // Add the target data from the target machine, if it exists, or the module.
  if (const DataLayout *TD = Target.getDataLayout())
    PM->add(new DataLayout(*TD));
  else
    PM->add(new DataLayout(mod));

  // Override default to generate verbose assembly.
  Target.setAsmVerbosityDefault(true);

  if (RelaxAll) {
    if (FileType != TargetMachine::CGFT_ObjectFile)
      errs() << ProgramName
             << ": warning: ignoring -mc-relax-all because filetype != obj";
    else
      Target.setMCRelaxAll(true);
  }

  {
#if defined(__native_client__)
    raw_fd_ostream ROS(getObjectFileFD(), true);
    ROS.SetBufferSize(1 << 20);
    formatted_raw_ostream FOS(ROS);
#else
    formatted_raw_ostream FOS(Out->os());
#endif // __native_client__

    // Ask the target to add backend passes as necessary. We explicitly ask it
    // not to add the verifier pass because we added it earlier.
    if (Target.addPassesToEmitFile(*PM, FOS, FileType,
                                   /* DisableVerify */ true)) {
      errs() << ProgramName
             << ": target does not support generation of this file type!\n";
      return 1;
    }

    if (LazyBitcode || ReduceMemoryFootprint) {
      FunctionPassManager* P = static_cast<FunctionPassManager*>(PM.get());
      P->doInitialization();
      for (Module::iterator I = mod->begin(), E = mod->end(); I != E; ++I) {
        P->run(*I);
        CheckABIVerifyErrors(ABIErrorReporter, "Function " + I->getName());
        if (ReduceMemoryFootprint) {
          I->Dematerialize();
        }
      }
      P->doFinalization();
    } else {
      static_cast<PassManager*>(PM.get())->run(*mod);
    }
#if defined(__native_client__)
    FOS.flush();
    ROS.flush();
#else
    // Declare success.
    Out->keep();
#endif // __native_client__
  }

  return 0;
}

int main(int argc, char **argv) {
#if defined(__native_client__)
  return srpc_main(argc, argv);
#else
  return llc_main(argc, argv);
#endif // __native_client__
}
