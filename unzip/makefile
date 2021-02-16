#####################################################################################
#  libSDLengine Makefile v0.07 for all (beta 2) 		                            #
#####################################################################################
#
# syntax make OS=<platform>[font_prefix=<font_prefix>]
#
# platforms supported = [linux|osx|freebsd|openbsd|netbsd|morphos|amigaos4]
#
######################################################################################

#os is case insensitive
ifndef $(OS)
OS=$(os)
endif


UNZIP_SRC= inflate.c unzip.c

SRC =  $(UNZIP_SRC)


UNZIP_OBJ= inflate.o unzip.o

OBJECT= $(UNZIP_OBJ)




#----------------------------------------------------------------------------------------------------------------------------------------#
# WIN32 #

ifeq ($(OS), win32)
TARGET= unzip.a

mingw=c:/devel/c-cpp/MinGW

ifndef prefix
    prefix=c:/programmi/sdlBasic
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf

CC= gcc
CPP=g++
RANLIB=		ranlib
RM=del

CFLAG= -Wall -mwindows  -g -O2 -I $(mingw)/include
LIBS= -lmingw32 -lSDLmain -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -lSDL_net -lsmpeg
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# LINUX #

ifeq ($(OS), linux)
TARGET= unzip.a

ifndef prefix
    prefix=/opt/sdlBasic
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf

CC= gcc
CPP=g++
RANLIB=		ranlib
RM=rm -f

CFLAG= -Wall -g -O2 -I/usr/include/SDL -D_REENTRAT -DPLAY_MOD -DUNIX -DLINUX
LIBS=-Wl,-rpath, -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lvorbisfile -lvorbis -logg -lsmpeg -lasound -lSDL -lpng -ltiff -lz -ljpeg -lpthread -lm -lfreetype -ldl
#LIBS=-Wl,-rpath, -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lvorbisfile -lvorbis -logg -lsmpeg -lpthread -lm -lfreetype -lSDL -lpng -ljpeg -ltiff -lz -lartsdsp -lasound -lartsdsp -ldl
#LIBS=-lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lsmpeg
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# GP2X #

ifeq ($(OS), gp2x)
TARGET= unzip.a

ifndef prefix
    prefix=/mnt/sd/sdlBasic
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf


CC= /usr/local/open2x/bin/open2x-gcc
CPP=/usr/local/open2x/bin/open2x-g++
RANLIB=/usr/local/open2x/bin/open2x-ranlib
RM=rm -f

CFLAG=-static -Wall -g -O2 -I/usr/local/open2x/open2x/include/SDL -D_REENTRAT -DPLAY_MOD -DUNIX -DLINUX
LIBS=-L/usr/local/open2x/open2x/lib -Wl,-rpath, -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lsmpeg -lSDL -lpng -ltiff -lz -ljpeg -lpthread -lm -lfreetype -ldl
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# MAC OSX #

ifeq ($(OS), osx)
TARGET= unzip.a

ifndef prefix
    prefix=/usr/local
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf

CC= gcc
CPP=g++
RANLIB=		ranlib
RM=rm -f

CFLAG= -g -O2 -I/usr/local/include/SDL -D_REENTRAT -DPLAY_MOD -DUNIX  -Wno-long-double
LIBS= -lobjc -framework Appkit -framework Carbon -framework IOKit `sdl-config --libs` -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lsmpeg -lfreetype -ljpeg -lpng -lz
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# FREEBSD #

ifeq ($(OS), freebsd)
TARGET= unzip.a

ifndef prefix
    prefix=/usr/local
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf

CC= gcc
CPP=g++
RANLIB=		ranlib
RM=rm -f

CFLAG= -Wall -g -O2 -I/usr/local/include/SDL11 -D_REENTRAT -DPLAY_MOD -DUNIX -DFBSD
LIBS=-lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lsmpeg -L/usr/local/lib \
-lpthread
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# OPENBSD #

ifeq ($(OS), openbsd)
TARGET= unzip.a

ifndef prefix
    prefix=/usr/local
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf


CC= gcc
CPP=g++
RANLIB=		ranlib
RM=rm -f

CFLAG= -Wall -g -O2 -I/usr/local/include/SDL -D_REENTRAT -DPLAY_MOD -DUNIX -DOPENBSD
LIBS=-L/usr/local/lib -L/usr/X11R6/lib -lX11 -lXext -lpthread -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lsmpeg
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# NETBSD #

ifeq ($(OS), netbsd)
TARGET= unzip.a

ifndef prefix
    prefix=/usr/local
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf

CC= gcc
CPP=g++
RANLIB=		ranlib
RM=rm -f

CFLAG= -Wall -g -O2 -L/usr/pkg/lib -I/usr/pkg/include/SDL -D_REENTRAT -DPLAY_MOD -DUNIX -DNETBSD
LIBS=-lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lsmpeg
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# MORPHOS #

ifeq ($(OS), morphos)
TARGET= unzip.a

ifndef prefix
    prefix=/usr/local
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf


CC= gcc -noixemul
CPP=g++
RANLIB=		ranlib
RM=rm -f

CFLAG= -Wall -g -O3 -fomit-frame-pointer -mmultiple -mstring -I/usr/include/SDL -D_REENTRAT -DPLAY_MOD -DUNIX -D__MORPHOS__
LIBS= -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_net -lsmpeg
COMPILE=$(CPP) $(CFLAG)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#
# AMIGAOS4 #

ifeq ($(OS), amigaos4)
TARGET= unzip.a

ifndef prefix
    prefix=/usr/local
endif
exec_prefix=$(prefix)/bin
font_prefix=$(prefix)/share/fonts/ttf


# on amiga can be: ppc-amigaos-strip --remove-section=.comment $(TARGET)
CC= ppc-amigaos-gcc
CPP= ppc-amigaos-g++
RANLIB=		ranlib
RM=rm -f

CFLAG= -Wall -ggdb -O3 -fomit-frame-pointer -mmultiple -mstring -D__USE_INLINE__ -D__USE_NETINET_IN_H -I/usr/local/amiga/ppc-amigaos/local/clib2/include/SDL/ -D_REENTRAT -DPLAY_MOD -DUNIX
LIBS= -lsmpeg -lSDL_mixer -lSDL_image -lSDL_ttf -lfreetype -lSDL_net -lSDL -lpng -lz -ljpeg -lvorbisfile -lvorbis -logg -lauto -lm -lnet -lunix
COMPILE=$(CPP) $(CFLAG) $(LIBS)
endif

#----------------------------------------------------------------------------------------------------------------------------------------#


all:		$(TARGET)


$(TARGET): 	$(OBJECT)
		$(RM) $@
		ar cq $@ $(OBJECT)
		$(RANLIB) $(TARGET)

$(OBJECT):	%.o: 	%.c
		$(CC) $(CFLAG) -c $< -o $@


clean:
	$(RM) *.o
	$(RM) $(TARGET)


