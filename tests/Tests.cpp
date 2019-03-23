#include <gtest/gtest.h>

#include "../src/edge.cpp"
#include "../src/node.cpp"
#include "../src/tree.cpp"

int default_graph_size = 7;
vector<Edge> default_graph_edges = {
    Edge(0, 1),
    Edge(0, 2),
    Edge(0, 3),
    Edge(2, 4),
    Edge(2, 5),
    Edge(3, 6)
};

TEST (EdgeTest, SimpleTest) {
    Edge edge(4, 5);
    ASSERT_EQ(4, edge.from());
    ASSERT_EQ(5, edge.to());
}

TEST (TreeTest, SizeTest) {
    Tree tree(default_graph_size, default_graph_edges);
    ASSERT_EQ(7, tree.size());
}

TEST (TreeTest, DFSTestSimple) {    
    Tree tree(default_graph_size, default_graph_edges);
    vector<int> dfs = {0, 1, 2, 4, 5, 3, 6};
    vector<int> out = tree.dfs();
    for (int i = 0; i < out.size(); i++) {
        EXPECT_EQ(dfs[i], out[i]);
    }
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}