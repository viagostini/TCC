cmake_minimum_required(VERSION 3.1)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
set (CMAKE_CXX_STANDARD 11)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(
    runTests
    ../code/src/Edge.cpp
    ../code/src/Node.cpp
    ../code/src/Tree.cpp
    ../code/src/NaiveAlgorithm.cpp
    ../code/src/TableAlgorithm.cpp
    ../code/src/JumpPointers.cpp
    ../tests/src/Tests.cpp
    ../tests/src/EdgeTests.cpp
    ../tests/src/NodeTests.cpp
    ../tests/src/TreeTests.cpp
    ../tests/src/NaiveAlgorithmTests.cpp
    ../tests/src/TableAlgorithmTests.cpp
    ../tests/src/JumpPointersTests.cpp
)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
