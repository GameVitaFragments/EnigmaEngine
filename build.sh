#!/bin/sh

set -xe

cd build
meson compile
cd ..
./build/main
