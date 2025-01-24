# SECTION:
#	General Setup

cmake_minimum_required(VERSION 3.11)

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

project(test)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/libtdd_test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main tdd)
