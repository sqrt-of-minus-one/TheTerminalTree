cmake_minimum_required(VERSION 3.20)

project(TheTerminalTree
	VERSION 0.0.1
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(UI_SOURCE
	ui/Escape.cpp
	ui/FormattedString/FormattedString.cpp ui/FormattedString/FormattedStringPiece.cpp ui/FormattedString/TextStyle.cpp)
set(TREE_SOURCE Tree/Data.cpp Tree/Tree.cpp)
set(SOURCE
	main.cpp ${UI_SOURCE} ${TREE_SOURCE})

add_executable(the_tree ${SOURCE})
