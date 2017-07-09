#cmake_minimum_required(VERSION 3.7)
project(codas_fpa)

#set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-std=c++0x")

add_subdirectory(01_integer)
add_subdirectory(02_fpa)
add_subdirectory(patriot)
