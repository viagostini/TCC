cmake_minimum_required(VERSION 3.1)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
set (CMAKE_CXX_STANDARD 11)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(
    runBench
    ../code/src/Edge.cpp
    ../code/src/Node.cpp
    ../code/src/Tree.cpp
    ../code/src/TableAlgorithm.cpp
    benchmark.cpp
)
target_link_libraries(runBench ${GTEST_LIBRARIES} pthread)
