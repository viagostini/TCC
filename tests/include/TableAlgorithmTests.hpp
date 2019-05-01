#ifndef TABLE_TESTS_H
#define TABLE_TESTS_H

#include <gtest/gtest.h>
#include "TreeTests.hpp"
#include "../../code/include/TableAlgorithm.hpp"

struct DefaultTableTest: public ::testing::Test {
    protected:
    Tree *tree;
    TableAlgorithm *table;
    struct DefaultTree default_tree;

    void SetUp () {
        tree = new Tree(default_tree.size, default_tree.edges);
        table = new TableAlgorithm(tree);
    }

    void TearDown () {
        delete table;
        delete tree;
    }
};

#endif // TABLE_TESTS_H
