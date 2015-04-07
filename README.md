# TimingIsEverything

This game is inspired by the mini game that's in Donkey Kong Country. The game has three barrels, each alternating between 4 different tokens. The player has to hit each barrel to make them stop at a certain token. If all three tokens match, the player will get that token as a reward.

#GLUT setup

Include your GLUT files in your project properties.
C/C++ -> General -> Additional Include Directories: add the folder where the GLUT include file is located.
Linkers -> General -> Additional Lirbary Directories: add the folder where the GLUT library file is located.
Linkers -> Input -> add the following:
opengl32.lib
glu32.lib
freeglut.lib
glut32.lib
