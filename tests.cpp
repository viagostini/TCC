#include "whattotest.cpp"
#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNum) {
    ASSERT_EQ(6, square_root(36.0));
}

TEST(SquareRootTest, NegativeNum) {
    ASSERT_EQ(-1.0, square_root(-15.0));
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
