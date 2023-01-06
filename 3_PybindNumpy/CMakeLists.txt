cmake_minimum_required(VERSION 3.10)

project(sumnp)

#set(HFILES summa.h)
set(CPPFILES example-np.cpp)

#add_executable(${HFILES} ${CPPFILES})
#add_executable(${CPPFILES})

add_subdirectory(extern/pybind11)
pybind11_add_module(sumnp ${CPPFILES})
add_executable(benchmark bench-main.cpp)


