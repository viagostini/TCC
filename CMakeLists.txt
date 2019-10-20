cmake_minimum_required(VERSION 3.10.2)
project(Tests)

# bring headers to project
include_directories(code/include)
include_directories(generators/)
include_directories(tests/include)

# add sources with file(GLOB...)
file(GLOB SOURCES "code/src/*" "tests/src/*" "generators/generators.cpp")

add_executable(runTests ${SOURCES})

