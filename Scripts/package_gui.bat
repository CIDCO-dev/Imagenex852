@echo off

if not exist "build" mkdir build
if not exist "build\\bin" mkdir build\\bin

"C:\Program Files\7-Zip\7z.exe" a -r Dump852-GUI.zip -w Dump852\release\.
move Dump852-GUI.zip build\bin
