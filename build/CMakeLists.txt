cmake_minimum_required(VERSION 3.1)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
set (CMAKE_CXX_STANDARD 11)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(
    runTests
    ../code/src/edge.cpp
    ../code/src/node.cpp
    ../code/src/tree.cpp
    ../code/src/TableAlgorithm.cpp
    ../tests/src/Tests.cpp
    ../tests/src/EdgeTests.cpp
    ../tests/src/NodeTests.cpp
    ../tests/src/TreeTests.cpp
    ../tests/src/TableAlgorithmTests.cpp
)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
