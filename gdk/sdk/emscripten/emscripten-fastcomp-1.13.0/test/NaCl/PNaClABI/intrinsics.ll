; RUN: pnacl-abicheck < %s | FileCheck %s
; RUN: pnacl-abicheck -pnaclabi-allow-debug-metadata < %s | \
; RUN:   FileCheck %s --check-prefix=DBG
; RUN: pnacl-abicheck -pnaclabi-allow-dev-intrinsics < %s | \
; RUN:   FileCheck %s --check-prefix=DEV

; Test that only white-listed intrinsics are allowed.

; ===================================
; Some "Dev" intrinsics which are disallowed by default.

; CHECK: Function llvm.nacl.target.arch is a disallowed LLVM intrinsic
; DEV-NOT: Function llvm.nacl.target.arch is a disallowed LLVM intrinsic
declare i32 @llvm.nacl.target.arch()


; ===================================
; Debug info intrinsics, which are disallowed by default.

; CHECK: Function llvm.dbg.value is a disallowed LLVM intrinsic
; DBG-NOT: Function llvm.dbg.value is a disallowed LLVM intrinsic
declare void @llvm.dbg.value(metadata, i64, metadata)
; CHECK: Function llvm.dbg.declare is a disallowed LLVM intrinsic
; DBG-NOT: Function llvm.dbg.declare is a disallowed LLVM intrinsic
declare void @llvm.dbg.declare(metadata, metadata)


; ===================================
; Always allowed intrinsics.

declare void @llvm.memcpy.p0i8.p0i8.i32(i8* %dest, i8* %src,
                                        i32 %len, i32 %align, i1 %isvolatile)
declare void @llvm.memmove.p0i8.p0i8.i32(i8* %dest, i8* %src,
                                         i32 %len, i32 %align, i1 %isvolatile)
declare void @llvm.memset.p0i8.i32(i8* %dest, i8 %val,
                                    i32 %len, i32 %align, i1 %isvolatile)

declare i8* @llvm.nacl.read.tp()

declare i8 @llvm.nacl.atomic.load.i8(i8*, i32)
declare i16 @llvm.nacl.atomic.load.i16(i16*, i32)
declare i32 @llvm.nacl.atomic.load.i32(i32*, i32)
declare i64 @llvm.nacl.atomic.load.i64(i64*, i32)
declare void @llvm.nacl.atomic.store.i8(i8, i8*, i32)
declare void @llvm.nacl.atomic.store.i16(i16, i16*, i32)
declare void @llvm.nacl.atomic.store.i32(i32, i32*, i32)
declare void @llvm.nacl.atomic.store.i64(i64, i64*, i32)
declare i8 @llvm.nacl.atomic.rmw.i8(i32, i8*, i8, i32)
declare i16 @llvm.nacl.atomic.rmw.i16(i32, i16*, i16, i32)
declare i32 @llvm.nacl.atomic.rmw.i32(i32, i32*, i32, i32)
declare i64 @llvm.nacl.atomic.rmw.i64(i32, i64*, i64, i32)
declare i8 @llvm.nacl.atomic.cmpxchg.i8(i8*, i8, i8, i32, i32)
declare i16 @llvm.nacl.atomic.cmpxchg.i16(i16*, i16, i16, i32, i32)
declare i32 @llvm.nacl.atomic.cmpxchg.i32(i32*, i32, i32, i32, i32)
declare i64 @llvm.nacl.atomic.cmpxchg.i64(i64*, i64, i64, i32, i32)
declare void @llvm.nacl.atomic.fence(i32)
declare void @llvm.nacl.atomic.fence.all()
declare i1 @llvm.nacl.atomic.is.lock.free(i32, i8*)

declare i16 @llvm.bswap.i16(i16)
declare i32 @llvm.bswap.i32(i32)
declare i64 @llvm.bswap.i64(i64)

declare i32 @llvm.cttz.i32(i32, i1)
declare i64 @llvm.cttz.i64(i64, i1)

declare i32 @llvm.ctlz.i32(i32, i1)
declare i64 @llvm.ctlz.i64(i64, i1)

declare i32 @llvm.ctpop.i32(i32)
declare i64 @llvm.ctpop.i64(i64)

declare void @llvm.trap()

declare float @llvm.sqrt.f32(float)
declare double @llvm.sqrt.f64(double)

declare i8* @llvm.stacksave()
declare void @llvm.stackrestore(i8*)

declare void @llvm.nacl.longjmp(i8*, i32)
declare i32 @llvm.nacl.setjmp(i8*)

; CHECK-NOT: disallowed

; ===================================
; Always disallowed intrinsics.

; CHECK: Function llvm.adjust.trampoline is a disallowed LLVM intrinsic
; DBG: Function llvm.adjust.trampoline is a disallowed LLVM intrinsic
; DEV: Function llvm.adjust.trampoline is a disallowed LLVM intrinsic
declare i8* @llvm.adjust.trampoline(i8*)

; CHECK: Function llvm.init.trampoline is a disallowed LLVM intrinsic
; DBG: Function llvm.init.trampoline is a disallowed LLVM intrinsic
; DEV: Function llvm.init.trampoline is a disallowed LLVM intrinsic
declare void @llvm.init.trampoline(i8*, i8*, i8*)

; CHECK: Function llvm.x86.aesni.aeskeygenassist is a disallowed LLVM intrinsic
; DBG: Function llvm.x86.aesni.aeskeygenassist is a disallowed LLVM intrinsic
; DEV: Function llvm.x86.aesni.aeskeygenassist is a disallowed LLVM intrinsic
declare <2 x i64> @llvm.x86.aesni.aeskeygenassist(<2 x i64>, i8)

; CHECK: Function llvm.va_copy is a disallowed LLVM intrinsic
; DBG: Function llvm.va_copy is a disallowed LLVM intrinsic
; DEV: Function llvm.va_copy is a disallowed LLVM intrinsic
declare void @llvm.va_copy(i8*, i8*)

; CHECK: Function llvm.bswap.i1 is a disallowed LLVM intrinsic
declare i1 @llvm.bswap.i1(i1)

; CHECK: Function llvm.bswap.i8 is a disallowed LLVM intrinsic
declare i8 @llvm.bswap.i8(i8)

; CHECK: Function llvm.ctlz.i16 is a disallowed LLVM intrinsic
declare i16 @llvm.ctlz.i16(i16, i1)

; CHECK: Function llvm.cttz.i16 is a disallowed LLVM intrinsic
declare i16 @llvm.cttz.i16(i16, i1)

; CHECK: Function llvm.ctpop.i16 is a disallowed LLVM intrinsic
declare i16 @llvm.ctpop.i16(i16)

; CHECK: Function llvm.lifetime.start is a disallowed LLVM intrinsic
declare void @llvm.lifetime.start(i64, i8* nocapture)

; CHECK: Function llvm.lifetime.end is a disallowed LLVM intrinsic
declare void @llvm.lifetime.end(i64, i8* nocapture)

; CHECK: Function llvm.frameaddress is a disallowed LLVM intrinsic
declare i8* @llvm.frameaddress(i32 %level)

; CHECK: Function llvm.returnaddress is a disallowed LLVM intrinsic
declare i8* @llvm.returnaddress(i32 %level)

; CHECK: Function llvm.sqrt.fp128 is a disallowed LLVM intrinsic
declare fp128 @llvm.sqrt.fp128(fp128)

; The variants with 64-bit %len arguments are disallowed.
; CHECK: Function llvm.memcpy.p0i8.p0i8.i64 is a disallowed LLVM intrinsic
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* %dest, i8* %src,
                                        i64 %len, i32 %align, i1 %isvolatile)
; CHECK: Function llvm.memmove.p0i8.p0i8.i64 is a disallowed LLVM intrinsic
declare void @llvm.memmove.p0i8.p0i8.i64(i8* %dest, i8* %src,
                                         i64 %len, i32 %align, i1 %isvolatile)
; CHECK: Function llvm.memset.p0i8.i64 is a disallowed LLVM intrinsic
declare void @llvm.memset.p0i8.i64(i8* %dest, i8 %val,
                                    i64 %len, i32 %align, i1 %isvolatile)

; Test that the ABI checker checks the full function name.
; CHECK: Function llvm.memset.foo is a disallowed LLVM intrinsic
declare void @llvm.memset.foo(i8* %dest, i8 %val,
                              i64 %len, i32 %align, i1 %isvolatile)
