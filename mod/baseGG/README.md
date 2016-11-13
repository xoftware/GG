GoodGame
---------------------------------------------------------------

Excerpt from
 http://www.katsbits.com/smforum/index.php?topic=901.0


#| Methodology

Basically, I'm going to design a CGI-quality level, render it with ray-tracing, (i.e. V-Ray,) and generate assets with photogrammetry, (i.e. 123D Catch or PhotoScan.) This will, in theory, yield corresponding models and assets with unprecedented photo-realism, which may need some additional work to, but ultimately, that play in-game at amazing performance!

I don't know why or if nobody has thought of this idea yet, but it was only a matter of time. I came up with this idea months before I had find out about The Vanishing of Ethan Carter on the Unreal Engine and Star Wars Battlefront, which deserve ample credit for their beauty and creativity. These games, however, are not the same as this idea. Photogrammetry is a logical step up from the methodology of applying actual photographs to 3D models. Its main use-case is, famously and impressively, importing actual real-world objects and environments, which is what we've seen so far. This is also its limitation and/or drawback, since the lighting is set-in-stone, no pun intended. However, I believe the combination of technologies, ray-tracing and photogrammetry, sleeps at our doorstep like a workflow in a manger. Since photogrammetry requires a series of photographs taken at angles around the subject in order to stitch them together, (think Google Maps,) that works perfectly for virtual environments that can render them with precision and control.

Food for thought:
Also, I believe, in this manner particularly, it is possible to generate with each texture a light-map, for lack of a better term, that even allows support for any given angle of light. (For instance, a texture with red shadows for overhead light, blue for left-incoming light, green for right-incoming light, etc.) That might make its way into the project later on, after engine modifications eventually come into play.

Speaking of perfectly, here's how this map implementation is going to work. I'm actually going to use the original map, (except with all invisible textures,) as the underlying clip mask. The intention behind the HQ level is to show immaculate terrain, along with a splendid skybox and some atmospheric effects. However, I didn't want to affect the original structures of the map, since that has everything to do with the desired gameplay. So, I'm going to apply the photo-realistic level as "detail" over the top of the original map. See, perfect!

#| Thematics

Venturing out into space, men via macro-robotic ships continued the expansion of their civilization, yet again. This time they established an artificial ring around the planet, a space-station, a space-nation, sizable, luxurious, and hospitable for life. Breathing in oxygen supplied by onboard gardens, men throughout their days gazed through either giant encompassing walls of glass into the stars or the Earth below. This was life as they knew it, since generations ago.

When constructing the ring, rather than hauling up materials through the atmosphere, meteors were gathered and mined for their plethora of minerals, chiseled and mounted, the great slabs, into structures right in their justified domain. In doing so, magnificent arrays of rock, dust and gas formed, subsequently decorating the artificial ring just exactly as were the natural rings around our other planets.

This map is either a training arena or a sport arena caught in orbit outside of the ring. That would explain the hovering platforms, decked above the happy spectators inside, amidst the glorious trails of cosmic debris. The sport would be played one-versus-one in the robotic suits, equipped with hand-held laser guns and thrusters. The laser guns not only disengaged their opponent's suit, resetting their position, in order to gain a point on the scoreboard, but also had the ability to blast-off of surfaces, especially when hyper-activated by specially-designed launch-pads. This explains the guns and launch-pads, while the thrusters explain the gravity and ability to move directions whilst already in motion. You see, the thrusters ran a program to simulate gravity, in order to compliment better man's natural athleticism, and could be controlled for additional axial movement in space.

The map is somewhat of a luxurious destination, akin to a beach house or an island getaway, but rather than oceans and waves, we have space and stars, and rather than rocks and sand, we have meteorite rock and dust. Clouds and seaweed, gas and ice. Instead of palm trees, well, I suppose we have teleporters. :) And then, of course, we have... the sun and the moon.



#| Story

Now I can share the prequel for this map, for fun! Just like the idea to apply photogrammetry and photorealism together, I'd been kicking around some fantasies about a cinematic story with characters, setting, and all that. It wasn't until I was inspired by QuakeJS that I had the thought to put all of this together!

Since you're a level guru, I might as well outline some of the fun details right here, which I have to do anyway.

So, the story goes that in future, society has decided to re-zone. (Up until this point, in the current day, civilization was developed on a first-come first-serve basis, as land were explored, and then on an as-needed basis, once lands were established.) There was never an initial blueprint, which means it's not possible that the roads and cities just happened to be laid out in the most optimal manner.

Our modern buildings would be left as the "legacy layer," while other layers were built upwards. A work layer, a residence layer, a vacation layer... transportation between hospitals, schools, manufacturing and everything was now as efficient as possible. A collective campus, worthy of an advanced society.

In order to take on such an undertaking, they put to use the technology of manned-robots. These robots were in the shape of men, but on much grander scales, so as to have the most intuitive interface possible. Instead of lugging around materials and constructing with big Cat machinery, pulling levers and wheels, men operated stronger mechanical versions of themselves, quite naturally at that. When they wanted to place a beam, they just picked it up and placed it.

At first, the technology was intended for construction, but soon found its use in many cases, such as military. Robots could be of any size, controlled via exoskeleton suit or virtually, within or remotely, and eventually revolutionized the concept of the vehicle. Before long, everybody had one, of some sort. It became integral. Everything was more intuitive as a human, a superhuman that is. Then came the ability to launch into space, and began the new space age. =)))

(Dotted all throughout here is plenty of room for more backstory development.)


#| Conclusion

I'm actually making a single-player RPG out of this, as the map will be one of many destinations of its kind. The game engine is sufficient for platforming the ideas I have in mind, like bots as instructor characters that follow a preset path with guide trails, training your skills with various exercises and tutorials. I don't know if you caught this, but the laser-gun game I was mentioning is actually the classic InstaUnlagged! :) That's why surface clipping has to be in-tact as close to the original as possible. And the joke about why in the Quake physics, we can move around freely in the air. Hopefully, the final result will be, first and fore-most, a fun gameplay, with some updated graphics, that can run in the web browser or at least on about every platform, including mobile.

I think this approach is a modestly good way to revamp a game engine like this, without overhauling it, because at that point, I'd rather start from scratch and go all out with ideas. :)

Anyway, even if you didn't read all this, I hope you enjoyed it about as much as I did! And if you want to say anything pertaining to this approach or anything, just fire away! Let me know what you think!

Thanks!