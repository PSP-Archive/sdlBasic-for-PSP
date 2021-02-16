sdlBasic for PSP version 0.6
---------------------------------------

sdlBasic is a small, efficient multiplatform basic interpreter originally created by Roberto Viola in 2002.
Its core is based on wxBasic and syntax, inspired by AMOS, is easy to learn by beginners
http://www.sdlbasic.altervista.org contains the reference guides language overview, comand syntax, examples and
additional tools and resources, required for development.

Installation
---------------
The interpreter only works on custom PSP 3.XX firmwares.
Copy sdlBasic folder to ms:/PSP/GAME (or ms:/PSP/GAME3XX where XX is your custom firmware's subversion.

Using the interpreter
--------------------------
sdlBasic program(s) should be saved in [program_name].sdlbas file and placed in sdlBasic folder, together with EBOOT.PBP file and 
fonts directory. Of course, sdlBasic folder can be renamed, and EBOOT icon/background can be replaced with a number of tools.
If only one .sdlbas file is detected in the folder, the interpreter immediatelly runs it. Overwise the program selection screen is displayed.

PSP-spesific features & limitations
-----------------------------------
- setdisplay() dimensions are limited to 640x480, 320x240, 480x272 (and some derivatives)
- only some keyboard keys are mapped (arrows, enter, space, escape) and available through key() / inkey commands.
- all psp buttons can be quered with getButtonJoystick() call with button indexs from 0 to 13
- mouse calls are partially implemented via the analog pad and buttons mapped to [x],[o],[triangle],[square]
- isPSP=1 and os=PSP variables are added for platform detection.
- network, mpeg and cd-control calls as well as shell() are not implemented yet.
- mp3 playbeack is not supported. Ogg, wav and tracker formats should be used instead.

new in version 0.6
- bug fix: memory leak during loading images
