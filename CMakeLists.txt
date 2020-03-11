cmake_minimum_required(VERSION 3.14)
project(POO2_Labo01)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

add_executable(project main.cpp Matrix.cpp Matrix.hpp Operator.hpp Addition.hpp Subtraction.hpp Multiply.hpp)

