cmake_minimum_required(VERSION 3.10)

project(summa)

set(HFILES summa.h)
set(CPPFILES summa.cpp main.cpp)

add_executable(${HFILES} ${CPPFILES})




