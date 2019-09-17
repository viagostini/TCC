#include "../include/NaiveAlgorithmTests.hpp"

TEST_F (DefaultTreeNaiveTest, Query_DepthZero_ReturnZero) {
    for (int i = 0; i < tree->size(); i++) {
        ASSERT_EQ(0, naive->query(i, 0));
    }
}

TEST_F (DefaultTreeNaiveTest, Query_DefaultTest) {
    // TODO: maybe test all possible queries?
    ASSERT_EQ(2, naive->query(4, 1));
    ASSERT_EQ(3, naive->query(6, 1));
    ASSERT_EQ(2, naive->query(4, 1));
    ASSERT_EQ(3, naive->query(6, 1));
}

TEST_F (DefaultTreeNaiveTest, Query_OwnDepth_ReturnItself) {
    for (int i = 0; i < tree->size(); i++) {
        ASSERT_EQ(i, naive->query(i, tree->depth(i)));
    }
}

TEST_F (DefaultTreeNaiveTest, Query_NegativeDepth_ThrowsException) {
    ASSERT_THROW(naive->query(1, -1), std::invalid_argument);
}

TEST_F (DefaultTreeNaiveTest, Query_LargerDepth_ReturnsNegativeOne) {
    ASSERT_EQ(-1, naive->query(1, tree->size()));
}

TEST_F (DefaultTreeNaiveTest, Query_InvalidNode_ThrowsException) {
    ASSERT_THROW(naive->query(-1, 1), std::invalid_argument);
    ASSERT_THROW(naive->query(100, 1), std::invalid_argument);
}

