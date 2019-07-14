#include "../include/JumpPointersTests.hpp"

TEST_F (DefaultJumpTest, DepthZero) {
    ASSERT_EQ(0, jump_pointers->query1(0, 0));
    ASSERT_EQ(0, jump_pointers->query1(4, 0));
    ASSERT_EQ(0, jump_pointers->query2(0, 0));
    ASSERT_EQ(0, jump_pointers->query2(4, 0));
}

TEST_F (DefaultJumpTest, DefaultTest) {
    ASSERT_EQ(2, jump_pointers->query1(4, 1));
    ASSERT_EQ(3, jump_pointers->query1(6, 1));
    ASSERT_EQ(2, jump_pointers->query2(4, 1));
    ASSERT_EQ(3, jump_pointers->query2(6, 1));
}

TEST_F (DefaultJumpTest, OwnDepth) {
    ASSERT_EQ(6, jump_pointers->query1(6, tree->depth(6)));
    ASSERT_EQ(1, jump_pointers->query1(1, tree->depth(1)));
    ASSERT_EQ(6, jump_pointers->query2(6, tree->depth(6)));
    ASSERT_EQ(1, jump_pointers->query2(1, tree->depth(1)));
}

TEST_F (DefaultJumpTest, NegativeDepth) {
    ASSERT_THROW(jump_pointers->query1(1, -1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query2(1, -1), std::invalid_argument);
}

TEST_F (DefaultJumpTest, LargerDepth) {
    ASSERT_EQ(-1, jump_pointers->query1(1, 100));
    ASSERT_EQ(-1, jump_pointers->query2(1, 100));
}

TEST_F (DefaultJumpTest, InvalidNode) {
    ASSERT_THROW(jump_pointers->query1(-1, 1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query1(100, 1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query2(-1, 1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query2(100, 1), std::invalid_argument);
}