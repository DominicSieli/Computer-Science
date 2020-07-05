#!/usr/bin/env bash

cd ../..

mkdir -p Binaries/Linux

title=${PWD##*/}_Optimized

g++ -O3 -std=c++17 Source/*.cpp -o Binaries/Linux/$title

./Binaries/Linux/$title