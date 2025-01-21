# SECTION:
#	General Setup

cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# SECTION:
#	FetchContent

include(FetchContent)

FetchContent_Declare(
	gtest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.15.2
)

FetchContent_MakeAvailable(gtest)

# SECTION:
#	Project Setup

project(tdd)

set(SOURCES
	${CMAKE_SOURCE_DIR}/memmove.c
	${CMAKE_SOURCE_DIR}/split.c
	${CMAKE_SOURCE_DIR}/sqrt.c
	${CMAKE_SOURCE_DIR}/strjoin.c
)

add_library(tdd ${SOURCES})

add_executable(test.out ${CMAKE_SOURCE_DIR}/test/libtdd_test.cpp)
target_link_libraries(test.out PRIVATE gtest gtest_main tdd)
