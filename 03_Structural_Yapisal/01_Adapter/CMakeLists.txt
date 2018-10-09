cmake_minimum_required(VERSION 3.9)

# VARIABLES
set(AUTHOR_NAME "Mert Acel")
set(PROJECT_NAME "Adapter")

# Project Information
project (${PROJECT_NAME} VERSION 1.0.1 DESCRIPTION "Adapter")

# Information
message(STATUS "AUTHOR_NAME          : ${AUTHOR_NAME}")
message(STATUS "PROJECT_NAME         : ${PROJECT_NAME}") 
message(STATUS "CMAKE_SOURCE_DIR     : ${CMAKE_SOURCE_DIR}") 
message(STATUS "CMAKE_SYSTEM         : ${CMAKE_SYSTEM}") 

# Set g++ Parameter
set(CMAKE_CXX_FLAGS "-O2 -Wall -Wextra -std=c++17")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} src/main.cpp)
