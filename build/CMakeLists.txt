cmake_minimum_required(VERSION 3.1)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
set (CMAKE_CXX_STANDARD 11)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(
    runTests
    ../src/edge.cpp
    ../src/node.cpp
    ../src/tree.cpp
    ../src/TableAlgorithm.cpp
    ../tests/Tests.cpp
    ../tests/EdgeTest.cpp
)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
