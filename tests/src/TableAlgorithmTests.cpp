#include "../include/TableAlgorithmTests.hpp"

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

TEST_F (DefaultTableTest, NegativeDepth) {
    ASSERT_THROW(table->query(1, -1), std::invalid_argument);
}

TEST_F (DefaultTableTest, LargerDepth) {
    ASSERT_EQ(-1, table->query(1, 100));
}

TEST_F (DefaultTableTest, InvalidNode) {
    ASSERT_THROW(table->query(-1, 1), std::invalid_argument);
    ASSERT_THROW(table->query(100, 1), std::invalid_argument);
}
