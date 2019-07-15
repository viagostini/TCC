#include "../include/JumpPointersTests.hpp"

TEST_F (DefaultTreeJumpTest, Query_DepthZero_ReturnZero) {
    for (int i = 0; i < tree->size(); i++) {
        ASSERT_EQ(0, jump_pointers->query1(i, 0));
        ASSERT_EQ(0, jump_pointers->query2(i, 0));
    }
}

TEST_F (DefaultTreeJumpTest, Query_DefaultTest) {
    // TODO: maybe test all possible queries?
    ASSERT_EQ(2, jump_pointers->query1(4, 1));
    ASSERT_EQ(3, jump_pointers->query1(6, 1));
    ASSERT_EQ(2, jump_pointers->query2(4, 1));
    ASSERT_EQ(3, jump_pointers->query2(6, 1));
}

TEST_F (DefaultTreeJumpTest, Query_OwnDepth_ReturnItself) {
    for (int i = 0; i < tree->size(); i++) {
        ASSERT_EQ(i, jump_pointers->query1(i, tree->depth(i)));
        ASSERT_EQ(i, jump_pointers->query2(i, tree->depth(i)));
    }
}

TEST_F (DefaultTreeJumpTest, Query_NegativeDepth_ThrowsException) {
    ASSERT_THROW(jump_pointers->query1(1, -1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query2(1, -1), std::invalid_argument);
}

TEST_F (DefaultTreeJumpTest, Query_LargerDepth_ReturnsNegativeOne) {
    ASSERT_EQ(-1, jump_pointers->query1(1, tree->size()));
    ASSERT_EQ(-1, jump_pointers->query2(1, tree->size()));
}

TEST_F (DefaultTreeJumpTest, Query_InvalidNode_ThrowsException) {
    ASSERT_THROW(jump_pointers->query1(-1, 1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query1(100, 1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query2(-1, 1), std::invalid_argument);
    ASSERT_THROW(jump_pointers->query2(100, 1), std::invalid_argument);
}

TEST_F (LinearTreeJumpTest, DefaultTest) {
    ASSERT_EQ(1, jump_pointers->query1(49, 1));
    ASSERT_EQ(1, jump_pointers->query2(49, 1));
}