@echo off

if not exist "build" mkdir build
if not exist "build\\bin" mkdir build\\bin

copy C:\Users\cidco\Library\qtDLL\*.dll src\examples\Dump852\release\
"C:\Program Files\7-Zip\7z.exe" a -r Dump852-GUI.zip -w src\examples\Dump852\release\.
"C:\Program Files\7-Zip\7z.exe" a -r Dump852-GUI.7z -w src\examples\Dump852\release\.

move Dump852-GUI.zip build\bin
move Dump852-GUI.7z build\bin
