/*
    Name:       builtin.h
    Purpose:    builtin routines for wxBasic
    Author:     David Cuny
    Copyright:  (c) 2001 David Cuny <dcuny@lanset.com>
    Licence:    LGPL
*/

void notYet( char *name);

void basPrintStack(void);
void basConcat(void);
void basConvBase(void);
void basIndexes(void);
//_________________________________________________________________________________________________________________________
// Run time
void basArgument(void);
void basArgc(void);
void basArgv(void);
void basCommand(void);
void basSetEnv(void);
void basGetEnv(void);
void basRun(void);
void basShell(void);
void basStop(void);
//_________________________________________________________________________________________________________________________
// Array
void basLBound(void);
void basQuickSort(void);
void basUBound(void);
//_________________________________________________________________________________________________________________________
//Strings
void basAsc(void);
void basChr(void);
void basFormat(void);
void basInsert(void);
void basInstr(void);
void basLCase(void);
void basLeft(void);
void basLen(void);
void basLTrim(void);
void basMid(void);
void basReplace(void);
void basReplaceSubStr(void);
void basReverse(void);
void basRight(void);
void basRInstr(void);
void basRTrim(void);
void basSpace(void);
void basStr(void);
void basStrF(void);
void basString(void);
void basTrim(void);
void basTally(void);
void basTypeOf(void);
void basUCase(void);
void basVal(void);

//_________________________________________________________________________________________________________________________
//Maths
void basAbs(void);
void basACos(void);
void basASin(void);
void basATan(void);
void basBin(void);
void basCos(void);
void basExp(void);
void basFix(void);
void basFrac(void);
void basHex(void);
void basInt(void);
void basLog(void);
void basRandomize(void);
void basRnd(void);
void basRound(void);
void basSgn(void);
void basSin(void);
void basSqr(void);
void basTan(void);
void basMin(void);
void basMax(void);
void basBitwiseAnd(void);
void basBitwiseOr(void);
void basBitwiseXor(void);

//_________________________________________________________________________________________________________________________
//Files
void basEof(void);
void basFileExists(void);
void basFileCopy(void);
void basFileMove(void);
void basFileRename(void);
void basFreeFile(void);
void basKill(void);
void basLoc(void);
void basLof(void);
void basReadByte(void);
void basSeek(void);
void basWriteByte(void);

//_________________________________________________________________________________________________________________________
//Dirs
void basChDir(void);
void basDir(void);
void basDirExists(void);
void basDirFirst(void);
void basDirNext(void);
void basMkDir(void);
void basRmDir(void);

//_________________________________________________________________________________________________________________________
//Data function support
void basData(void);
void basRead(void);

//_________________________________________________________________________________________________________________________
//Date and time
void basDate(void);
void basTicks(void);
void basTime(void);

//_________________________________________________________________________________________________________________________
//Memory Bank

void basReserveBank(void);
void basBaseImage(void);
void basBaseImageCC(void);
void basBaseScreen(void);
void basBaseSound(void);

void basFreeBase(void);
void basFreeBank(void);

void basCopyBank(void);
void basLoadBank(void);
void basSaveBank(void);

void basSetBank(void);
void basSizeBank(void);

void basPoke(void);
void basDoke(void);
void basLoke(void);

void basPeek(void);
void basDeek(void);
void basLeek(void);

void basMemCopy(void);


//_________________________________________________________________________________________________________________________
//
//---- SDLengine --------------------------------------------------------------------------------------------------
//_________________________________________________________________________________________________________________________
// Screen
void basSetDefaults(void);
void basSetDisplay(void);
void basSetAlphaChannel(void);
void basSetCaption(void);
void basCaption(void);

void basDisplayMode(void);
void basDisplayWidth(void);
void basDisplayHeight(void);
void basDisplayBpp(void);

void basScreen(void);
void basScreenZ(void);
void basLastScreen(void);
void basDirectScreen(void);

void basScreenOpen(void);
void basScreenClose(void);
void basScreenClone(void);

void basScreenCopy(void);
void basScreenFade(void);
void basScreenFadein(void);
void basScreenCrossFade(void);
void basScreenAlpha(void);
void basScreenLock(void);
void basScreenUnlock(void);

void basScreenRect(void);
void basXScreenRect(void);
void basYScreenRect(void);
void basWScreenRect(void);
void basHScreenRect(void);
void basFlagScreenRect(void);

void basScreenWidth(void);
void basScreenHeight(void);

void basOffset(void);
void basXOffset(void);
void basYOffset(void);

void basCls(void);
void basScreenSwap(void);
void basAutoBack(void);
void basDualPlayfield(void);
void basWaitVbl(void);
void basFps(void);
//_________________________________________________________________________________________________________________________
// Graphics
void basRgb(void);
void basEnablePalette(void);
void basColor(void);
void basPalette(void);
void basColorCycling(void);
void basInk(void);

void basPoint(void);
void basDot(void);
void basPlot(void);
void basLine(void);
void basBox(void);
void basBar(void);
void basRectangle(void);
void basCircle(void);
void basFillCircle(void);
void basEllipse(void);
void basFillEllipse(void);
void basPaint(void);
void basTriangle(void);
void basPolyLine(void);
void basPolyGon(void);

//_________________________________________________________________________________________________________________________
// File graphics input output
void basLoadImage(void);
void basLoadZipImage(void);
void basSaveImage(void);
void basLoadSound(void);
void basLoadZipSound(void);
void basSaveSound(void);
void basLoadMusic(void);
void basLoadZipMusic(void);
//_________________________________________________________________________________________________________________________
// Image manipulation
void basHotSpot(void);
void basSetColorKey(void);
void basImageExists(void);
void basImageWidth(void);
void basImageHeight(void);
void basDeleteImage(void);
void basCopyImage(void);
void basSetAlpha(void);
void basZoomImage(void);
void basRotateImage(void);
void basRotozoomImage(void);
void basMirrorImage(void);
//_________________________________________________________________________________________________________________________
// Blitting
void basBlt(void);
void basPasteBob(void);
void basPasteIcon(void);
void basGrab(void);
//_________________________________________________________________________________________________________________________
// Sprite system
void basSpriteClip(void);
void basSprite(void);
void basDeleteSprite(void);
void basXSprite(void);
void basYSprite(void);
void basSpriteWidth(void);
void basSpriteHeight(void);
void basFrSprite(void);
void basLiveSprite(void);
void basSpriteHit(void);
void basSpriteZ(void);
void basLastSprite(void);
void basAutoUpdateSprite(void);
void basUpdateSprite(void);
//_________________________________________________________________________________________________________________________
// Bob system
void basSetBob(void);
void basBob(void);
void basDeleteBob(void);
void basXBob(void);
void basYBob(void);
void basBobWidth(void);
void basBobHeight(void);
void basFrBob(void);
void basLiveBob(void);
void basBobHit(void);
void basBobZ(void);
void basLastBob(void);
void basAutoUpdateBob(void);
void basUpdateBob(void);
//_________________________________________________________________________________________________________________________
//Text draw
void basText(void);
void basSetFont(void);
void basGetFont(void);
void basTextRender(void);
//_________________________________________________________________________________________________________________________
// Print screen
void basPen(void);
void basPaper(void);
void basfPrints(void);
void basPrints(void);
void basLocate(void);
void basAtx(void);
void basAty(void);
void basCursOn(void);
void basCursOff(void);
void basInputs(void);
void basZoneInputs(void);
//_________________________________________________________________________________________________________________________
// Sounds and music

void basIsEnabledSound(void);

void basSoundExists(void);
void basDeleteSound(void);
void basCopySound(void);

void basMusicExists(void);

void basPlaySound(void);
void basPlayFreqSound(void);
void basVolumeSound(void);
void basStopSound(void);
void basPauseSound(void);
void basResumeSound(void);
void basVuMeterSound(void);
void basPositionSound(void);
void basSoundChannels(void);

void basPlayMusic(void);
void basPositionMusic(void);
void basStopMusic(void);
void basPauseMusic(void);
void basResumeMusic(void);
void basRewindMusic(void);
void basFadeMusic(void);
void basVolumeMusic(void);
void basSpeedMusic(void);

//_________________________________________________________________________________________________________________________
// CD support

void basNumDrivesCD(void);
void basNameCD(void);
void basOpenCD(void);
void basInDriveCD(void);
void basTracksCD(void);
void basCurTrackCD(void);
void basCurFrameCD(void);
void basPlayCD(void);
void basPlayTracksCD(void);
void basPauseCD(void);
void basResumeCD(void);
void basStopCD(void);
void basEjectCD(void);
void basCloseCD(void);
void basTrackTypeCD(void);
void basTrackLengthCD(void);
void basTrackOffsetCD(void);

//________________________________________________________________________________________________________________________
// Video mpeg

void basLoadMpeg(void);
void basPlayMpeg(void);
void basStopMpeg(void);
void basDeleteMpeg(void);
void basPauseMpeg(void);
void basRewindMpeg(void);
void basSeekMpeg(void);
void basSkipMpeg(void);
void basStatusMpeg(void);

//_________________________________________________________________________________________________________________________
// Keyboard
void basKey(void);
void basInkey(void);
void basWaitKey(void);
//_________________________________________________________________________________________________________________________
// Mouse
void basXMouse(void);
void basYMouse(void);
void basXMouseScreen(void);
void basYMouseScreen(void);
void basBMouse(void);
void basChangeMouse(void);
void basLocateMouse(void);
void basMouseShow(void);
void basMouseHide(void);
void basMouseZone(void);
//_________________________________________________________________________________________________________________________
// Joystick
void basNumJoySticks(void);
void basNameJoyStick(void);
void basNumAxesJoyStick(void);
void basNumBallsJoyStick(void);
void basNumHatsJoyStick(void);
void basNumButtonsJoyStick(void);
void basGetAxisJoyStick(void);
void basGetHatJoyStick(void);
void basGetButtonJoyStick(void);
void basXGetBallJoyStick(void);
void basYGetBallJoyStick(void);
void basJoy(void);
void basBJoy(void);
void basWaitBJoy(void);

//_________________________________________________________________________________________________________________________
// SDLtime
void basWait(void);
void basTimer(void);
//_________________________________________________________________________________________________________________________
// Socket

void basIsEnabledSock(void);
void basGetFreeSock(void);
void basOpenSock(void);
void basAcceptSock(void);
void basIsServerReady(void);
void basConnectSock(void);
//void ConnectionReadySock(void);
void basIsClientReady(void);
void basCloseSock(void);
//void basPeekSock(void);
void basReadSock(void);
void basReadByteSock(void);
void basReadLineSock(void);
void basWriteSock(void);
void basWriteByteSock(void);
void basWriteLineSock(void);
void basGetRemoteIp(void);
void basGetRemotePort(void);
void basGetLocalIp(void);
//_________________________________________________________________________________________________________________
void addBuiltin( char *name, void (*routine)(void), int args, int optargs );
void initBuiltins(void);


static struct {     /* builtin routines */
    char    *name;
    void    (*routine)(void);
    int     args;
    int     optargs;
} builtin[] = {
    {"argument",        basArgument,        0,  1},
    {"argument$",       basArgument,        0,  1},
    {"printstack",      basPrintStack,      0,  0},
    {"convbase",        basConvBase,        2,  0},
    {"convbase$",       basConvBase,        2,  0},

//    Run time
    {"argc",            basArgc,            0,  0},
    {"argv",            basArgv,            1,  0},
    {"command",         basCommand,         0,  1},
    {"command$",        basCommand,         0,  1},
    {"setenv",          basSetEnv,          2,  0},
    {"getenv",          basGetEnv,          1,  0},
    {"run",             basRun,             1,  0},
    {"shell",           basShell,           1,  0},
    {"stop",            basStop,            0,  0},

//    Array
    {"indexes",         basIndexes,         1,  0},
    {"lbound",          basLBound,          2,  0},
    {"quicksort",       basQuickSort,       3,  0},
    {"ubound",          basUBound,          2,  0},

//    Strings
    {"chr",             basChr,             1,  0},
    {"chr$",            basChr,             1,  0},
    {"format",          basFormat,          1,  20},
    {"format$",         basFormat,          1,  20},
    {"insert",          basInsert,          3,  0},
    {"insert$",         basInsert,          3,  0},
    {"instr",           basInstr,           2,  1},
    {"lcase",           basLCase,           1,  0},
    {"lcase$",          basLCase,           1,  0},
    {"left",            basLeft,            2,  0},
    {"left$",           basLeft,            2,  0},
    {"len",             basLen,             1,  0},
    {"length",          basLen,             1,  0},
    {"ltrim",           basLTrim,           1,  0},
    {"ltrim$",          basLTrim,           1,  0},
    {"mid",             basMid,             2,  1},
    {"mid$",            basMid,             2,  1},
    {"replace",         basReplace,         2,  1},
    {"replace$",        basReplace,         2,  1},
    {"replacesubstr",   basReplaceSubStr,   3,  1},
    {"replacesubstr$",  basReplaceSubStr,   3,  1},
    {"reverse",         basReverse,         1,  0},
    {"reverse$",        basReverse,         1,  0},
    {"right",           basRight,           2,  0},
    {"right$",          basRight,           2,  0},
    {"rinstr",          basRInstr,          2,  1},
    {"rtrim",           basRTrim,           1,  0},
    {"rtrim$",          basRTrim,           1,  0},
    {"space",           basSpace,           1,  0},
    {"space$",          basSpace,           1,  0},
    {"str",             basStr,             1,  0},
    {"str$",            basStr,             1,  0},
    {"strf",            basStrF,            1,  0},
    {"strf$",           basStrF,            1,  0},
    {"string",          basString,          2,  0},
    {"string$",         basString,          2,  0},
    {"trim",            basTrim,            1,  0},
    {"trim$",           basTrim,            1,  0},
    {"tally",           basTally,           2,  1},
    {"ucase",           basUCase,           1,  0},
    {"ucase$",          basUCase,           1,  0},
    {"typeof$",         basTypeOf,          1,  0},
    {"typeof",          basTypeOf,          1,  0},

//    Maths
    {"abs",             basAbs,             1,  0},
    {"acos",            basACos,            1,  0},
    {"asc",             basAsc,             1,  0},
    {"asin",            basASin,            1,  0},
    {"atan",            basATan,            1,  0},
    {"bin",             basBin,             1,  0},
    {"bin$",            basBin,             1,  0},
    {"cos",             basCos,             1,  0},
    {"exp",             basExp,             1,  0},
    {"fix",             basFix,             1,  0},
    {"floor",           basFix,             1,  0},
    {"frac",            basFrac,            1,  0},
    {"hex",             basHex,             1,  0},
    {"hex$",            basHex,             1,  0},
    {"int",             basInt,             1,  0},
    {"log",             basLog,             1,  0},
    {"randomize",       basRandomize,       0,  1},
    {"rnd",             basRnd,             0,  1},
    {"round",           basRound,           1,  0},
    {"sgn",             basSgn,             1,  0},
    {"sin",             basSin,             1,  0},
    {"sqr",             basSqr,             1,  0},
    {"tan",             basTan,             1,  0},
    {"val",             basVal,             1,  0},
    {"min",             basMin,             2,  0},
    {"max",             basMax,             2,  0},
    {"bitwiseand",      basBitwiseAnd,      2,  0},
    {"bitwiseor",       basBitwiseOr,       2,  0},
    {"bitwisexor",      basBitwiseXor,      2,  0},
    {"andbit",          basBitwiseAnd,      2,  0},
    {"orbit",           basBitwiseOr,       2,  0},
    {"xorbit",          basBitwiseXor,      2,  0},

//    Files
    {"eof",             basEof,             1,  0},
    {"fileexists",      basFileExists,      1,  0},
    {"filecopy",        basFileCopy  ,      2,  0},
    {"filemove",        basFileMove  ,      2,  0},
    {"filerename",      basFileRename,      2,  0},
    {"freefile",        basFreeFile,        0,  0},
    {"kill",            basKill,            1,  0},
    {"filedelete",      basKill,            1,  0},
    {"loc",             basLoc,             1,  0},
    {"lof",             basLof,             1,  0},
    {"readbyte",        basReadByte,        1,  0},
    {"rename",          basFileRename,      2,  0},
    {"seek",            basSeek,            1,  1},
    {"writebyte",       basWriteByte,       2,  0},

//    Dirs
    {"chdir",           basChDir,           1,  0},
    {"dir",		basDir,             0,  0},
    {"dir$",		basDir,             0,  0},
    {"dirfirst",        basDirFirst,        1,  0},
    {"dirnext",		basDirNext,         0,  0},
    {"direxists",       basDirExists,       1,  0},
    {"mkdir",           basMkDir,           1,  0},
    {"rmdir",           basRmDir,           1,  0},

//    Data function support
    {"data",            basData,            0,  255},
    {"read",            basRead,            0,  1},

//    Date and time
    {"date",            basDate,            0,  0},
    {"date$",           basDate,            0,  0},
    {"ticks",           basTicks,           0,  0},
    {"time",            basTime,            0,  0},
    {"time$",           basTime,            0,  0},

//    Memory Bank

    {"reservebank",     basReserveBank,     2,  0},
    {"baseimage",       basBaseImage,       2,  0},
    {"baseimagecc",     basBaseImageCC,     2,  0},
    {"basescreen",      basBaseScreen,      2,  0},
    {"basesound",       basBaseSound,       2,  0},

    {"freebase",        basFreeBase,        1,  0},
    {"freebank",        basFreeBank,        1,  0},

    {"copybank",        basCopyBank,        2,  0},
    {"loadbank",        basLoadBank,        1,  1},
    {"savebank",        basSaveBank,        1,  1},

    {"setbank",         basSetBank,         0,  1},
    {"currentbank",     basSetBank,         0,  1},
    {"sizebank",        basSizeBank,        0,  1},
    {"banksize",        basSizeBank,        0,  1},

    {"poke",            basPoke,            2,  1},
    {"doke",            basDoke,            2,  1},
    {"loke",            basLoke,            2,  1},

    {"peek",            basPeek,            1,  1},
    {"deek",            basDeek,            1,  1},
    {"leek",            basLeek,            1,  1},

    {"memcopy",         basMemCopy,         5,  0},


/***************** SDLengine *********************/
//    Screen
    {"setdefaults",     basSetDefaults,     4,  0},
    {"setdisplay",      basSetDisplay,      4,  0},
    {"setalphachannel", basSetAlphaChannel, 1,  0},
    {"setcaption",      basSetCaption,      1,  0},
    {"caption",      	basCaption,         0,  0},
    {"displaymode",     basDisplayMode,     0,  0},
    {"displaywidth",    basDisplayWidth,    0,  0},
    {"displayheight",   basDisplayHeight,   0,  0},
    {"displaybpp",      basDisplayBpp,      0,  0},

    {"screen",          basScreen,	    0,  1},
    {"screenz",         basScreenZ,	    1,  1},
    {"lastscreen",      basLastScreen,	    0,  0},
    {"directscreen",    basDirectScreen,    0,  0},
    {"screenopen",      basScreenOpen,	    8,  0},
    {"screenclose",     basScreenClose,	    1,  0},
    {"screenclone",     basScreenClone,	    7,  0},

    {"screencopy",      basScreenCopy,	    8,  0},
    {"screenfade",      basScreenFade,	    1,  1},
    {"screenfadeout",   basScreenFade,	    1,  1},
    {"screenfadein",    basScreenFadein,    1,  2},
    {"screencrossfade", basScreenCrossFade, 1,  2},
    {"screenalpha",     basScreenAlpha,     2,  0},
    {"screenlock",      basScreenLock,      1,  0},
    {"screenunlock",    basScreenUnlock,    1,  0},

    {"screenrect",      basScreenRect,	    5,  0},
    {"screenviewport",  basScreenRect,	    5,  0},
    {"xscreenrect",     basXScreenRect,	    0,  0},
    {"screenviewportx", basXScreenRect,	    0,  0},
    {"yscreenrect",     basYScreenRect,	    0,  0},
    {"screenviewporty", basYScreenRect,	    0,  0},
    {"wscreenrect",     basWScreenRect,	    0,  0},
    {"screenviewportw", basWScreenRect,	    0,  0},
    {"hscreenrect",     basHScreenRect,	    0,  0},
    {"screenviewporth", basHScreenRect,	    0,  0},
    {"flagscreenrect",  basFlagScreenRect,  0,  0},
    {"screenviewportflag",basFlagScreenRect,  0,  0},

    {"screenwidth",     basScreenWidth,	    0,  0},
    {"screenheight",    basScreenHeight,    0,  0},

    {"offset",  	basOffset,	    2,  0},
    {"screenoffset",  	basOffset,	    2,  0},
    {"xoffset", 	basXOffset,   	    0,  0},
    {"screenoffsetx", 	basXOffset,   	    0,  0},
    {"yoffset", 	basYOffset,         0,  0},
    {"screenoffsety", 	basYOffset,         0,  0},

    {"cls",				basCls,     	    0,  0},
    {"screenswap",      basScreenSwap,      0,  0},
    {"setautoback",     basAutoBack,        0,  1},
    {"autoback",    	basAutoBack,        0,  1},
    {"dualplayfield",   basDualPlayfield,   0,  1},
    {"waitvbl",     	basWaitVbl,         0,  0},
    {"fps",         	basFps,             0,  1},

//    Graphics
    {"rgb",     	basRgb,      	    3,  0},
    {"enablepalette",  	basEnablePalette,   0,  1},
    {"color",     	basColor,      	    1,  1},
    {"palette",     	basPalette,         0,  255},
    {"colorcycling",    basColorCycling,    0,  4},
    {"ink",     	basInk,      	    0,  1},

    {"point",     	basPoint,      	    2,  0},
    {"getpixel",     	basPoint,      	    2,  0},
    {"dot",     	basDot,      	    2,  0},
    {"setpixel",     	basDot,      	    2,  0},
    {"putpixel",     	basDot,      	    2,  0},
    {"plot",     	basPlot,      	    3,  0},
    {"line",     	basLine,      	    4,  0},
    {"box",     	basBox,      	    4,  0},
    {"bar",     	basBar,      	    4,  0},
    {"rectangle",     	basRectangle, 	    4,  1},
    {"circle",     	basCircle,     	    3,  0},
    {"fillcircle",      basFillCircle, 	    3,  0},
    {"ellipse",         basEllipse,   	    4,  0},
    {"fillellipse",     basFillEllipse,	    4,  0},
    {"paint",		basPaint,	    2,  0},
    {"triangle",	basTriangle,	    6,  0},
    {"polyline",	basPolyLine,	    6,  254},
    {"polygon",		basPolyGon,	    6,  254},

//    File graphics input output
    {"loadimage",       basLoadImage,	    1,  1},
    {"loadzipimage",    basLoadZipImage,    2,  1},
    {"saveimage",       basSaveImage,	    2,  0},
    {"loadsound",       basLoadSound,	    1,  1},
    {"loadzipsound",    basLoadZipSound,    2,  1},
    {"savesound",       basSaveSound,	    2,  0},
    {"loadmusic",       basLoadMusic,	    1,  0},
    {"loadzipmusic",    basLoadZipMusic,    2,  0},

//    Image manipulation
    {"hotspot",      	basHotSpot,	    3,  0},
    {"setcolorkey",     basSetColorKey,	    1,  0},
    {"colorkey",        basSetColorKey,	    1,  0},
    {"imageexists",  	basImageExists,	    1,  0},
    {"imagewidth",   	basImageWidth,	    1,  0},
    {"imageheight",  	basImageHeight,	    1,  0},
    {"deleteimage",  	basDeleteImage,	    1,  0},
    {"copyimage",    	basCopyImage,	    2,  0},
    {"setalpha",     	basSetAlpha,	    2,  0},
    {"imagealpha",     	basSetAlpha,	    2,  0},
    {"zoomimage",     	basZoomImage,	    3,  0},
    {"rotateimage",    	basRotateImage,	    2,  0},
    {"rotozoomimage",  	basRotozoomImage,   3,  0},
    {"mirrorimage",  	basMirrorImage,     3,  0},

//    Blitting
    {"blt", 	      	basBlt,	            7,  0},
    {"pastebob",      	basPasteBob,        3,  0},
    {"pasteicon",     	basPasteIcon,       3,  0},
    {"grab",          	basGrab,            5,  0},

//    Sprite system
    {"spriteclip",    	basSpriteClip,      4,  0},
    {"sprite",        	basSprite,          4,  0},
    {"deletesprite",  	basDeleteSprite,    1,  0},
    {"xsprite",       	basXSprite,         1,  0},
    {"spritex",       	basXSprite,         1,  0},
    {"ysprite",       	basYSprite,         1,  0},
    {"spritey",       	basYSprite,         1,  0},
    {"spritewidth",   	basSpriteWidth,     1,  0},
    {"spriteheight",  	basSpriteHeight,    1,  0},
    {"frsprite",      	basFrSprite,        1,  0},
    {"spriteimage",    	basFrSprite,        1,  0},
    {"livesprite",    	basLiveSprite,      1,  0},
    {"spriteexist",    	basLiveSprite,      1,  0},
    {"spritehit",     	basSpriteHit,       1,  1},
    {"spritez",     	basSpriteZ,         1,  1},
    {"lastsprite",     	basLastSprite,      0,  0},
    {"autoupdatesprite",basAutoUpdateSprite,1,  0},
    {"updatesprite",  	basUpdateSprite,    0,  0},

//    Bob system
    {"setbob",        	basSetBob,          2,  0},
    {"bob",           	basBob    ,         4,  0},
    {"deletebob",     	basDeleteBob,       1,  0},
    {"xbob",          	basXBob,            1,  0},
    {"bobx",          	basXBob,            1,  0},
    {"ybob",          	basYBob,            1,  0},
    {"boby",          	basYBob,            1,  0},
    {"bobwidth",      	basBobWidth,        1,  0},
    {"bobheight",     	basBobHeight,       1,  0},
    {"frbob",         	basFrBob,           1,  0},
    {"bobimage",       	basFrBob,           1,  0},
    {"livebob",       	basLiveBob,         1,  0},
    {"bobexist",       	basLiveBob,         1,  0},
    {"bobhit",        	basBobHit,          1,  1},
    {"bobz",     	basBobZ,            1,  1},
    {"lastbob",     	basLastBob,         0,  0},
    {"autoupdatebob", 	basAutoUpdateBob,   1,  0},
    {"updatebob",     	basUpdateBob,       0,  0},

//    Text draw
    {"text",          	basText,            4,  1},
    {"setfont",       	basSetFont,         1,  0},
    {"getfont",       	basGetFont,         0,  0},
    {"textrender",    	basTextRender,      2,  2},

//    Print screen
    {"pen",    	      	basPen,             0,  1},
    {"paper",         	basPaper,           0,  1},
    {"fprints",       	basfPrints,         1,  0},
    {"prints",        	basPrints,          1,  0},
    {"locate",        	basLocate,          2,  0},
    {"atx",           	basAtx,             0,  0},
    {"aty",           	basAty,             0,  0},
    {"curson",        	basCursOn,          0,  0},
    {"cursoff",       	basCursOff,         0,  0},
    {"inputs",        	basInputs,          2,  0},
    {"zoneinputs",    	basZoneInputs,      4,  0},

//    Sounds and music
    {"isenabledsound",  basIsEnabledSound,  0,  0},
    {"soundenabled",    basIsEnabledSound,  0,  0},

    {"soundexists",     basSoundExists,	    1,  0},
    {"deletesound",     basDeleteSound,	    1,  0},
    {"copysound",       basCopySound,	    2,  0},

    {"musicexists",  	basMusicExists,	    0,  0},

    {"playsound",     	basPlaySound,       2,  1},
    {"playfreqsound",   basPlayFreqSound,   3,  1},
    {"volumesound",   	basVolumeSound,     1,  1},
    {"soundvolume",   	basVolumeSound,     1,  1},
    {"stopsound",     	basStopSound,       0,  1},
    {"pausesound",     	basPauseSound,      0,  1},
    {"resumesound",     basResumeSound,     0,  1},
    {"vumetersound",    basVuMeterSound,    0,  1},
    {"sound3d",		basPositionSound,   3,  0},
    {"positionsound",   basPositionSound,   3,  0},
    {"soundchannels",   basSoundChannels,   1,  0},

    {"playmusic",     	basPlayMusic,       1,  0},
    {"positionmusic",  	basPositionMusic,   1,  0},
    {"stopmusic",     	basStopMusic,       0,  0},
    {"pausemusic",     	basPauseMusic,      0,  0},
    {"resumemusic",    	basResumeMusic,     0,  0},
    {"rewindmusic",    	basRewindMusic,     0,  0},
    {"fademusic",     	basFadeMusic,       0,  1},
    {"volumemusic",   	basVolumeMusic,     0,  1},
    {"musicvolume",   	basVolumeMusic,     0,  1},
    {"speedmusic",   	basSpeedMusic,      1,  0},
    {"musicspeed",   	basSpeedMusic,      1,  0},

//    CD support
    {"numdrivescd",   	basNumDrivesCD,      0,  0},
    {"countcddrives",  	basNumDrivesCD,      0,  0},
    {"namecd",   	basNameCD,           1,  0},
    {"cdname",   	basNameCD,           1,  0},
    {"opencd",   	basOpenCD,           1,  1},
    {"indrivecd",   	basInDriveCD,        1,  0},
    {"cdinserted",   	basInDriveCD,        1,  0},
    {"trackscd",   	basTracksCD,         1,  0},
    {"countcdtracks",  	basTracksCD,         1,  0},
    {"curtrackcd",   	basCurTrackCD,       1,  0},
    {"cdcurtrack",   	basCurTrackCD,       1,  0},
    {"curframecd",   	basCurFrameCD,       1,  0},
    {"cdcurframe",   	basCurFrameCD,       1,  0},
    {"playcd",   	basPlayCD,           1,  2},
    {"playtrackscd",   	basPlayTracksCD,     1,  4},
    {"playcdtracks",   	basPlayTracksCD,     1,  4},
    {"pausecd",   	basPauseCD,          1,  0},
    {"resumecd",   	basResumeCD,         1,  0},
    {"stopcd",   	basStopCD,           1,  0},
    {"ejectcd",   	basEjectCD,          1,  0},
    {"closecd",   	basCloseCD,          1,  0},
    {"tracktypecd",   	basTrackTypeCD,      2,  0},
    {"cdtracktype",   	basTrackTypeCD,      2,  0},
    {"tracklengthcd",   basTrackLengthCD,    2,  0},
    {"cdtracklength",   basTrackLengthCD,    2,  0},
    {"trackoffsetcd",   basTrackOffsetCD,    2,  0},
    {"cdtrackoffset",   basTrackOffsetCD,    2,  0},

//   Video mpeg
    {"loadmpeg",   	basLoadMpeg,         2,  0},
    {"plaympeg",   	basPlayMpeg,         0,  1},
    {"stopmpeg",   	basStopMpeg,         0,  0},
    {"deletempeg",   	basDeleteMpeg,       0,  0},
    {"pausempeg",	basPauseMpeg,        0,  0},
    {"rewindmpeg",	basRewindMpeg,       0,  0},
    {"seekmpeg",	basSeekMpeg,         1,  0},
    {"skipmpeg",	basSkipMpeg,         1,  0},
    {"statusmpeg",	basStatusMpeg,       0,  0},

//    Keyboard
    {"key",           	basKey,             1,  0},
    {"inkey",         	basInkey,           0,  0},
    {"waitkey",       	basWaitKey,         0,  1},

//    Mouse
    {"xmouse",        	basXMouse,          0,  0},
    {"ymouse",        	basYMouse,          0,  0},
    {"mousex",        	basXMouse,          0,  0},
    {"mousey",        	basYMouse,          0,  0},
    {"xmousescreen",  	basXMouseScreen,    1,  0},
    {"ymousescreen",  	basYMouseScreen,    1,  0},
    {"mousescreenx",  	basXMouseScreen,    1,  0},
    {"mousescreeny",  	basYMouseScreen,    1,  0},
    {"bmouse",        	basBMouse,          0,  0},
    {"mousebutton",    	basBMouse,          0,  0},
    {"changemouse",    	basChangeMouse,     0,  1},
    {"mousepointer",   	basChangeMouse,     0,  1},
    {"locatemouse",    	basLocateMouse,     2,  0},
    {"placemouse",    	basLocateMouse,     2,  0},
    {"mouseshow",     	basMouseShow,       0,  0},
    {"showmouse",     	basMouseShow,       0,  0},
    {"mousehide",     	basMouseHide,       0,  0},
    {"hidemouse",     	basMouseHide,       0,  0},
    {"mousezone",     	basMouseZone,       4,  0},

//    Joystick

    {"numjoysticks",    basNumJoySticks,    0,  0},
    {"namejoystick",    basNameJoyStick,    1,  0},
    {"numaxesjoystick", basNumAxesJoyStick, 1,  0},
    {"numballsjoystick",basNumBallsJoyStick,1,  0},
    {"numhatsjoystick", basNumHatsJoyStick, 1,  0},
    {"numbuttonsjoystick",basNumButtonsJoyStick,1,  0},
    {"getaxisjoystick", basGetAxisJoyStick, 2,  0},
    {"gethatjoystick", basGetHatJoyStick,   2,  0},
    {"getbuttonjoystick", basGetButtonJoyStick, 2,  0},
    {"xgetballjoystick", basXGetBallJoyStick, 2,  0},
    {"ygetballjoystick", basYGetBallJoyStick, 2,  0},
    {"joy",         	basJoy,             1,  0},
    {"bjoy",          	basBJoy,            1,  0},
    {"joybuttons",     	basBJoy,            1,  0},
    {"fire",          	basBJoy,            1,  0},
    {"waitbjoy",      	basWaitBJoy,        0,  1},

//    SDLtime
    {"wait",          	basWait,            1,  0},
    {"timer",         	basTimer,           0,  0},

// Socket
    {"isenabledsock",   basIsEnabledSock,   0,  0},

    {"getfreesock",     basGetFreeSock,     0,  0},
    {"opensock",        basOpenSock,        1,  0},
    {"acceptsock",      basAcceptSock,      1,  0},
    {"isserverready",   basIsServerReady,   1,  0},
    {"connectsock",     basConnectSock,     2,  0},
  //{"connectionreadysock",basConnectionReadySock,1,  0},
    {"isclientready",   basIsClientReady,   1,  0},
    {"closesock",       basCloseSock,       1,  0},
  //{"peeksock",        basPeekSock,        2,  0},
    {"readsock",        basReadSock,        2,  0},
    {"readbytesock",    basReadByteSock,    1,  0},
    {"readlinesock",    basReadLineSock,    1,  0},
    {"writesock",       basWriteSock,       3,  0},
    {"writebytesock",   basWriteByteSock,   2,  0},
    {"writelinesock",   basWriteLineSock,   2,  0},
    {"getremoteip",     basGetRemoteIp,     1,  0},
    {"getremoteport",   basGetRemotePort,   1,  0},
    {"getlocalip",     	basGetLocalIp,      0,  0},

    {NULL,              NULL,               0,  0}
};

