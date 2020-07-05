#!/usr/bin/env bash

cd ../..

mkdir -p Assembly/Linux

title=${PWD##*/}_Optimized.asm

g++ -S -O3 -std=c++17 Source/*.cpp -o Assembly/Linux/$title