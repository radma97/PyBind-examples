mkdir build
cd build
rem set PATH=C:\Program Files\CodeBlocks\MinGW\bin;%PATH%
rem cmake .. -G "MinGW Makefiles"

cmake .. -G "Visual Studio 17" -A "x64"
cmake --build . --config Release