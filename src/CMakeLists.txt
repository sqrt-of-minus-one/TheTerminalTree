cmake_minimum_required(VERSION 3.20)

project(TheTerminalTree
	VERSION 0.0.1
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE main.cpp)

add_executable(the_tree ${SOURCE})
