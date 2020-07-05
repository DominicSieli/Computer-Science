#!/usr/bin/env bash

cd ../..

mkdir -p Assembly/Linux

title=${PWD##*/}_Debug.asm

g++ -S -g -Wall -std=c++17 Source/*.cpp -o Assembly/Linux/$title