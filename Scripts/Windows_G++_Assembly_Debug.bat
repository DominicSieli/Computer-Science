cd ..

mkdir Assembly

set file=Windows_G++_Assembly_Debug

g++ -S -g -Wall -std=c++17 Source/*.cpp -o Assembly/%file%