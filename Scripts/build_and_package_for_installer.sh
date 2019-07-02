#!/bin/bash

mkdir -p build || true
mkdir -p build/gui || true

cd Dump852

qmake
make

cp *.o ../build/gui
cp moc* ../build/gui
cp ui_* ../build/gui
cp Dump852 ../build/gui
cd ..

7z a Installer/packages/ca.cidco.dump852-gui/data/dump852_linux.7z build/gui/*
