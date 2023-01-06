cmake_minimum_required(VERSION 3.10)

project(summa)

#set(HFILES summa.h)
set(CPPFILES example.cpp)

#add_executable(${HFILES} ${CPPFILES})
#add_executable(${CPPFILES})

add_subdirectory(extern/pybind11)
pybind11_add_module(summa ${CPPFILES})



