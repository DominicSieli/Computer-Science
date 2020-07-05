#!/usr/bin/env bash

cd ../..

mkdir -p Binaries/Linux

title=${PWD##*/}_Debug

g++ -g -Wall -std=c++17 Source/*.cpp -o Binaries/Linux/$title

./Binaries/Linux/$title