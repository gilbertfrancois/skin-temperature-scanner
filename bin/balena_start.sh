#!/usr/bin/env bash

# Build ThermalCamera
echo "Building"
mkdir -p /usr/src/build
cd /usr/src/build
cmake /usr/src
make

# Start ThermalCamera
exec startx /usr/src/build/ThermalCamera
