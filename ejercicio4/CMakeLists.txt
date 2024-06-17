cmake_minimum_required(VERSION 3.12)
project(Ejemplo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE Calculadora.cpp main.cpp)

add_executable(punteros ${SOURCE})


