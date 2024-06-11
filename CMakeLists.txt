cmake_minimum_required(VERSION 3.12)
project(Ejemplo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE hola.cpp)

add_executable(hola ${SOURCE})

