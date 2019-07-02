#!/bin/bash

version=$1
date=$(date +"%m-%d-%Y")

if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
    exit 0
fi

sed -i "s/VERSION-NUMBER/$version/g" ./Installer/config/config.xml
sed -i "s/DATE/$date/g" ./Installer/packages/*/meta/package.xml
sed -i "s/VERSION-NUMBER/$version/g" ./Installer/packages/*/meta/package.xml
