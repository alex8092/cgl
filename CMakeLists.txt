cmake_minimum_required(VERSION 2.8)

project(cgl)

include_directories(include)

set(CMAKE_C_FLAGS "-Wall -Wextra -g")

file(
	GLOB_RECURSE
	source_files
	src/*.c
)

file(
	GLOB_RECURSE
	header_files
	include/*.h
)

add_library(cgl SHARED ${header_files} ${source_files})