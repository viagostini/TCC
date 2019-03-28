#include "../include/TreeTests.hpp"

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