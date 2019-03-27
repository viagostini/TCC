#include <gtest/gtest.h>
#include "../include/node.hpp"

TEST (NodeTest, SimpleTest) {
    Node node(2);
    Node another_node(1);
    ASSERT_EQ(2, node.label());
    ASSERT_EQ(true, node.children().empty());
    node.add_child(another_node);
    ASSERT_EQ(1, node.children().size());
    ASSERT_EQ(1, node.children()[0].label());
}