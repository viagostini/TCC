#ifndef NAIVE_TESTS_H
#define NAIVE_TESTS_H

#include <gtest/gtest.h>
#include "TreeTests.hpp"
#include "../../code/include/NaiveAlgorithm.hpp"

struct DefaultTreeNaiveTest: public ::testing::Test {
    protected:
    Tree* tree;
    NaiveAlgorithm *naive;
    struct DefaultTree default_tree;

    void SetUp () {
        tree = new Tree(default_tree.size, default_tree.edges);
        naive = new NaiveAlgorithm(tree);
    }

    void TearDown () {
        delete naive;
        delete tree;
    }
};

#endif // NAIVE_TESTS_H
