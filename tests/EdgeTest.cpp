#include <gtest/gtest.h>
#include "../include/edge.hpp"

TEST (EdgeTest, SimpleTest) {
    Edge edge(4, 5);
    ASSERT_EQ(4, edge.from());
    ASSERT_EQ(5, edge.to());
}