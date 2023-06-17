#!/bin/sh

set -xe

cd build
meson compile
./main
