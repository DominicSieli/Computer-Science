cd ../..

mkdir Binaries\Windows

set projectName=Build_Optimized

g++ -O3 -std=c++17 Source/*.cpp -o Binaries/Windows/%projectName%

start Binaries/Windows/%projectName%