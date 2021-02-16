TARGET = sdlbrt
PSPSDK=$(shell psp-config --pspsdk-path)
PSPBIN = $(PSPSDK)/../bin
SDL_CONFIG = $(PSPBIN)/sdl-config

#PSP_EBOOT_SND0 = SND0.AT3
PSP_EBOOT_ICON = ICON0.PNG
PSP_EBOOT_PIC1 = PIC1.PNG


BUILD_PRX=1
PSP_FW_VERSION = 371

//OBJS =   array.o    const.o  eval.o     node.o    stack.o   var.o builtin.o  data.o   keyword.o   symbol.o   class.o    error.o  lexer.o    shared.o  trace.o  sdlBrt.o BASengine/datafunction.o  BASengine/file.o  BASengine/membank.o BASengine/dir.o           BASengine/math.o  BASengine/strings.o SDLengine/SDL_extension.o       SDLengine/keyboard.o SDLengine/SDLengine.o           SDLengine/mouse.o SDLengine/blitting.o            SDLengine/print_screen.o SDLengine/bob_system.o          SDLengine/screen.o SDLengine/cd_support.o           SDLengine/common.o              SDLengine/sound.o SDLengine/file_io.o             SDLengine/sprite_system.o SDLengine/graphics.o            SDLengine/text_draw.o SDLengine/image_manipulation.o  SDLengine/time.o SDLengine/joystick.o            SDLengine/video_mpeg.o  SDLengine/socket.o

OBJS =  y_tab.o array.o    const.o  eval.o     node.o    stack.o   var.o builtin.o  data.o   keyword.o   symbol.o   class.o    error.o  lexer.o    shared.o  trace.o  sdlBrt.o BASengine/datafunction.o  BASengine/file.o  BASengine/membank.o BASengine/dir.o           BASengine/math.o  BASengine/strings.o SDLengine/SDL_extension.o       SDLengine/keyboard.o SDLengine/SDLengine.o           SDLengine/mouse.o SDLengine/blitting.o            SDLengine/print_screen.o SDLengine/bob_system.o          SDLengine/screen.o SDLengine/cd_support.o           SDLengine/common.o              SDLengine/sound.o SDLengine/file_io.o             SDLengine/sprite_system.o SDLengine/graphics.o            SDLengine/text_draw.o SDLengine/image_manipulation.o  SDLengine/time.o SDLengine/joystick.o            SDLengine/video_mpeg.o unzip/inflate.o unzip/unzip.o

INCDIR =
#CFLAGS = -O2 -g  -G0 -Wall  $(shell $(SDL_CONFIG) --cflags) -DUNIX   -Wall  -ffast-math  -Dfont_prefix=\"fonts\" -D__DEBUG_TRACE__ 
CFLAGS = -O3  -G0 -Wall  $(shell $(SDL_CONFIG) --cflags) -DUNIX   -Wall  -ffast-math  -Dfont_prefix=\"fonts\"   -fno-exceptions  -fsingle-precision-constant -mno-check-zero-division  -funsafe-math-optimizations -fpeel-loops 


#CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti -fsingle-precision-constant -mno-check-zero-division -ffast-math

LIBDIR =
LDFLAGS =
LIBS = -lstdc++  -lSDL_mixer  -lvorbisidec -lSDL_ttf -lfreetype -lSDL_image -lpng -lz -ljpeg  -lSDL_gfx -lm $(shell $(SDL_CONFIG) --libs) -lpsprtc  -lpspvfpu  -lpsppower

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = sdlbrt

include $(PSPSDK)/lib/build.mak
