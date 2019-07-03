#!/bin/bash

make

mkdir -p build/gui || true
mkdir -p Installer/packages/ca.cidco.dump852_gui/data
mkdir -p Installer/packages/ca.cidco.imagenex852_cli/data

cd src/examples/Dump852

qmake
make

cp *.o ../../../build/gui
cp moc* ../../../build/gui
cp ui_* ../../../build/gui
cp Dump852 ../../../build/gui
cd ../../../

cd build/gui
7z a ../../Installer/packages/ca.cidco.dump852_gui/data/dump852_linux.7z *
cd ..
7z a ../Installer/packages/ca.cidco.imagenex852_cli/data/imagenex853-CLI.7z bin/*
cd ../
