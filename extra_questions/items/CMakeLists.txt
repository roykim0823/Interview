cmake_minimum_required(VERSION 2.8)
project(Questions)

set(CMAKE_C_FLAGS "-g -Wall")
#set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall")
set(CMAKE_CXX_FLAGS "-std=c++14 -g -Wall")
find_library(MATHLIB m)

include_directories(include)

file(GLOB SRCS "src/*.cpp")

foreach(src IN LISTS SRCS) 
#	message(STATUS "${src}")
	get_filename_component(filename ${src} NAME)
	string(REPLACE "." ";" temp ${filename})
	list(GET temp 0 target)
	add_executable(${target} ${src})
	list(APPEND TARGET_LIST ${target})
endforeach()
