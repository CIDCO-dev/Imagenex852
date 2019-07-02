#!/bin/bash

make

mkdir -p build/gui || true
mkdir -p Installer/packages/ca.cidco.dump852-gui/data
mkdir -p Installer/packages/ca.cidco.imagenex852-cli/data

cd src/examples/Dump852

qmake
make

cp *.o ../../../build/gui
cp moc* ../../../build/gui
cp ui_* ../../../build/gui
cp Dump852 ../../../build/gui
cd ../../../

cd build/gui
7z a ../../Installer/packages/ca.cidco.dump852-gui/data/dump852_linux.zip *
cd ..
7z a ../Installer/packages/ca.cidco.imagenex852-cli/data/imagenex853-CLI.zip bin/*
cd ../
