#ifndef JUMP_TESTS_H
#define JUMP_TESTS_H

#include <gtest/gtest.h>
#include "TreeTests.hpp"
#include "../../code/include/JumpPointers.hpp"

struct DefaultJumpTest: public ::testing::Test {
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

#endif // JUMP_TESTS_H