#ifndef TREE_TESTS_H
#define TREE_TESTS_H

#include <gtest/gtest.h>
#include "../../code/include/Tree.hpp"

struct EmptyTree {
    int size = 0;
    vector<Edge> edges = {};
};

struct DefaultTree {
    int size = 7;
    vector<Edge> edges = {
        Edge(0, 1),
        Edge(0, 2),
        Edge(0, 3),
        Edge(2, 4),
        Edge(2, 5),
        Edge(3, 6)
    };
};

struct DefaultTreeTest: public ::testing::Test {
    protected:
    Tree *tree;
    struct DefaultTree default_tree;

    void SetUp () {
        tree = new Tree(default_tree.size, default_tree.edges);
    }

    void TearDown () {
        delete tree;
    }
};

struct EmptyTreeTest: public ::testing::Test {
    protected:
    Tree *tree;
    struct EmptyTree empty_tree;

    void SetUp () {
        tree = new Tree(empty_tree.size, empty_tree.edges);
    }

    void TearDown () {
        delete tree;
    }
};

#endif // TREE_TESTS_H