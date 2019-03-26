#include <gtest/gtest.h>

#include "../src/edge.cpp"
#include "../src/node.cpp"
#include "../src/tree.cpp"
#include "../src/TableAlgorithm.cpp"

struct EmptyTree {
    int size = 0;
    vector<Edge> edges = {};
} empty_tree;

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
} default_tree;

struct EmptyTreeTest: public ::testing::Test {
    protected:
    Tree *tree;

    void SetUp () {
        tree = new Tree(empty_tree.size, empty_tree.edges);
    }

    void TearDown () {
        delete tree;
    }
};

struct DefaultTreeTest: public ::testing::Test {
    protected:
    Tree *tree;

    void SetUp () {
        tree = new Tree(default_tree.size, default_tree.edges);
    }

    void TearDown () {
        delete tree;
    }
};

struct DefaultTableTest: public ::testing::Test {
    protected:
    Tree *tree;
    TableAlgorithm *table;

    void SetUp () {
        tree = new Tree(default_tree.size, default_tree.edges);
        table = new TableAlgorithm(*tree);
    }

    void TearDown () {
        delete table;
        delete tree;
    }
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

/* *********************************************************
 *                                                         *      
 *                  Table Algorithm Tests                  *     
 *                                                         *    
 * *********************************************************/

TEST_F (DefaultTableTest, DepthZero) {
    ASSERT_EQ(0, table->query(0, 0));
    ASSERT_EQ(0, table->query(4, 0));
}

TEST_F (DefaultTableTest, DefaultTest) {
    ASSERT_EQ(2, table->query(4, 1));
    ASSERT_EQ(3, table->query(6, 1));
}

TEST_F (DefaultTableTest, OwnDepth) {
    ASSERT_EQ(6, table->query(6, tree->depth(6)));
    ASSERT_EQ(1, table->query(1, tree->depth(1)));
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}