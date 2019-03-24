#include <gtest/gtest.h>

#include "../src/edge.cpp"
#include "../src/node.cpp"
#include "../src/tree.cpp"
#include "../src/TableAlgorithm.cpp"

int default_graph_size = 7;
vector<Edge> default_graph_edges = {
    Edge(0, 1),
    Edge(0, 2),
    Edge(0, 3),
    Edge(2, 4),
    Edge(2, 5),
    Edge(3, 6)
};

/* *********************************************************
 *                                                         *      
 *                      Edge Tests                         *     
 *                                                         *    
 * *********************************************************/

TEST (EdgeTest, SimpleTest) {
    Edge edge(4, 5);
    ASSERT_EQ(4, edge.from());
    ASSERT_EQ(5, edge.to());
}

/* *********************************************************
 *                                                         *      
 *                      Node Tests                         *     
 *                                                         *    
 * *********************************************************/

TEST (NodeTest, SimpleTest) {
    Node node(2);
    Node another_node(1);
    ASSERT_EQ(2, node.label());
    ASSERT_EQ(true, node.children().empty());
    node.add_child(another_node);
    ASSERT_EQ(1, node.children().size());
    ASSERT_EQ(1, node.children()[0].label());
}

/* *********************************************************
 *                                                         *      
 *                      Tree Tests                         *     
 *                                                         *    
 * *********************************************************/

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

/* *********************************************************
 *                                                         *      
 *                  Table Algorithm Tests                  *     
 *                                                         *    
 * *********************************************************/

TEST (TableAlgorithmTest, SimpleTest) {
    Tree tree(default_graph_size, default_graph_edges);
    TableAlgorithm table(tree);
    ASSERT_EQ(0, table.query(0, 0));
    ASSERT_EQ(0, table.query(4, 0));
    ASSERT_EQ(2, table.query(4, 1));
    ASSERT_EQ(3, table.query(6, 1));
    ASSERT_EQ(6, table.query(6, tree.depth(6)));
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}