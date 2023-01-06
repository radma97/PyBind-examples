mkdir build
cd build
set PATH=C:\Program Files\CodeBlocks\MinGW\bin;%PATH%
rem cmake .. -G "Visual Studio 16" -A "x64"
cmake .. -G "MinGW Makefiles"
cmake --build .