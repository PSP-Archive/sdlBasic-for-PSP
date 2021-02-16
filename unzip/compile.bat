@echo off
echo now compiling unzip: please wait

rem WARNING!!! verify the correct path of mingGw
set MINGWPATH=c:\devel\c-cpp\mingw
path %MINGWPATH%\bin;%PATH%

mingw32-make os=win32
