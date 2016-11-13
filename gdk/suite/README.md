#| Map Design/Rendering Notes

Complex Shapes /  Curve Patches
 https://icculus.org/gtkradiant/documentation/q3radiant_manual/ch06/pg6_1.htm
 http://ingar.satgnu.net/gtkradiant/tutorial-brush-cylinders.html

 First off, create a triangular brush (I used a 256:224 ratio for the base and its height)
 Use this brush to create a hexagon shape, shown below (1)
 Then make patch caps, and place them like shown at (2)
 Copy and scale the bunch (3)
 Flip surface and move verticle of the patches, and create new brushwork to fit (4) 
 
 * Create square brush
 * With brush selected, Curve > Cylinder
 * With cylinder patch selected, Curve > Thicken
 * Type in thicken value, OK 
 
 1. Make your two cylinders (for the inner and outer ring). You can make them bigger/smaller by dragging outside the edge.
 2. Make a brush, then (with it selected) go to your patch menu and choose "simple patch mesh". This will make a flat, square, patch mesh.
 3. Hit "V" to turn on vertex mode, and then move the vertexes to be similar to the ones shown in obsidian's post to get a quarter-circle that fits inside the two cylinders you made. Dupe this and rotate as necessary to make the rest of the "O" shape (both sides). Use Curve-->Invert Matrix as necessary to "flip" the textured side of the patches.
 
 make it in gmax/blender then import it in as md3 with spawnflags 6 for solidity and lightmapping, unless it's bigger than 1024^3
 or make it in hammer then open the map file in notepad and chop some of the values off the ends of the lines and import it as a prefab
 or build it out of brushes and apply a phong shader to the 'curved' surfaces
 
 
High Poly
 r_lodbias -2
 r_lodCurveError 10000
 r_subdivisions 1
 vid_restart