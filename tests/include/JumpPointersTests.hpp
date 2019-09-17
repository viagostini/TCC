#ifndef JUMP_TESTS_H
#define JUMP_TESTS_H

#include <gtest/gtest.h>
#include "TreeTests.hpp"
#include "../../code/include/JumpPointers.hpp"

struct DefaultTreeJumpTest: public ::testing::Test {
    protected:
    Tree* tree;
    JumpPointerLA *jump_pointers;
    struct DefaultTree default_tree;

    void SetUp () {
        tree = new Tree(default_tree.size, default_tree.edges);
        jump_pointers = new JumpPointerLA(tree);
    }

    void TearDown () {
        delete jump_pointers;
        delete tree;
    }
};

struct LinearTreeJumpTest: public ::testing::Test {
    protected:
    Tree* tree;
    JumpPointerLA *jump_pointers;
    vector<Edge> edges;

    void SetUp () {
        int n = 50;
        for (int i = 0; i < n-1; i++)
            edges.push_back(make_edge(i, i+1));
        tree = new Tree(n, edges);
        jump_pointers = new JumpPointerLA(tree);
    }

    void TearDown () {
        delete jump_pointers;
        delete tree;
    }
};

#endif // JUMP_TESTS_H