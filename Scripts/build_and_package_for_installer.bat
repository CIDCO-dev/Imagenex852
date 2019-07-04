@echo off

mkdir Installer\\packages\\ca.cidco.dump852_gui\\data
mkdir Installer\\packages\\ca.cidco.imagenex852_cli\\data

cd build
del bin\\*.obj
"C:\Program Files\7-Zip\7z.exe" a -r imagenex852-CLI.7z -w bin
cd ..

move build\\imagenex852-CLI.7z Installer\\packages\\ca.cidco.imagenex852_cli\\data\\
move build\\gui\\Dump852-GUI.7z Installer\\packages\\ca.cidco.dump852_gui\\data\\
