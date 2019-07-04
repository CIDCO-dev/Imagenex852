@echo off

::NOTE - cl.exe must be in Environment PATH (C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64)

set error=0

cd src\examples\Dump852

::Locate c++ files for compilation
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

call "C:\Qt\5.12.2\msvc2017_64\bin\qmake.exe" Dump852.pro -spec win32-msvc "CONFIG+=qtquickcompiler" && "C:/Qt/Tools/QtCreator/bin/jom.exe"  -f Makefile.Release
move release\Dump852.exe .
rmdir /s /q release
mkdir release
move Dump852.exe release
call "C:\Qt\5.12.2\msvc2017_64\bin\windeployqt.exe" release\Dump852.exe || set error=1
cd ..\..\..\

if %error%==1 echo [+] FAILED TO BUILD GUI
if %error%==0 echo [+] SUCCESSFULLY BUILT GUI

exit /B %error%
