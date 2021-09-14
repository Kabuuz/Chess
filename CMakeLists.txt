cmake_minimum_required(VERSION 3.5)

project(BasicProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dependencies)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(DEPENDENCY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
set(SFML_INCLUDE ${DEPENDENCY_DIR}/sfml/include)
set(HEADERS_DIR ${INCLUDE_DIR} ${SFML_INCLUDE})

add_subdirectory(src)
add_subdirectory(test)
