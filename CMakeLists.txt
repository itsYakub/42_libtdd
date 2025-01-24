# SECTION:
#	General Setup

cmake_minimum_required(VERSION 3.11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# SECTION:
#	Project Setup

project(tdd)

set(SOURCES
	${CMAKE_SOURCE_DIR}/memmove.c
	${CMAKE_SOURCE_DIR}/split.c
	${CMAKE_SOURCE_DIR}/sqrt.c
	${CMAKE_SOURCE_DIR}/strjoin.c
)

add_library(${PROJECT_NAME} ${SOURCES})
add_subdirectory(${CMAKE_SOURCE_DIR}/test)
