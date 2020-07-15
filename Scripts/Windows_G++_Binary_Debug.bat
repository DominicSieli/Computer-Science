cd ..

mkdir Binaries

set file=Windows_G++_Binary_Debug

g++ -g -Wall -std=c++17 Source/*.cpp -o Binaries/%file%

start Binaries/%file%