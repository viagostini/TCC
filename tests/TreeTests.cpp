#include <gtest/gtest.h>
#include "../include/tree.hpp"
#include "TreeTests.hpp"


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

TEST_F (EmptyTreeTest, EmptyTest) {
    ASSERT_EQ(0, tree->size());
}

TEST_F (DefaultTreeTest, SizeTest) {
    ASSERT_EQ(7, tree->size());
}

TEST_F (DefaultTreeTest, DFSTestSimple) {    
    vector<int> dfs = {0, 1, 2, 4, 5, 3, 6};
    vector<int> out = tree->dfs();
    for (int i = 0; i < out.size(); i++) {
        EXPECT_EQ(dfs[i], out[i]);
    }
}