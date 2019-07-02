@echo off

"C:\Program Files\7-Zip\7z.exe" a -r imagenex853-CLI.7z -w build\bin\.

move imagenex853-CLI.7z Installer\\packages\\ca.cidco.imagenex852-cli\\data\\
move build\\bin\\Dump852-GUI.7z Installer\\packages\\ca.cidco.dump852-gui\\data\\
