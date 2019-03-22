#include "tree.cpp"
#include <gtest/gtest.h>


TEST (TreeTest, defaultGraph) {    
    int size = 7;
    vector<Edge> edges = {
        Edge(0, 1),
        Edge(0, 2),
        Edge(0, 3),
        Edge(2, 4),
        Edge(2, 5),
        Edge(3, 6)
    }; 
    Tree tree(size, edges);
    vector<int> dfs = {0, 1, 2, 4, 5, 3, 6};
    fprintf(stderr, "Hello");
    vector<int> out = tree.dfs();
    fprintf(stderr, "\n\n%ld %ld\n\n", out.size(), dfs.size());
    for (int i = 0; i < out.size(); i++) {
        EXPECT_EQ(dfs[i], out[i]);
    }
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}