cd ../..

mkdir Binaries\Windows

set projectName=Build_Debug

g++ -g -Wall -std=c++17 Source/*.cpp -o Binaries/Windows/%projectName%

start Binaries/Windows/%projectName%