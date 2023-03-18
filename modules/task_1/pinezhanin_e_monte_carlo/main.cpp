// Copyright 2023 Pinezhanin Evgeny
#include <gtest/gtest.h>
#include <vector>

TEST(Sequential, Test_1) {
    ASSERT_EQ(true, true);
}

TEST(Sequential, Test_2) {
    ASSERT_EQ(true, true);
}

TEST(Sequential, Test_3) {
    ASSERT_EQ(true, true);
}

TEST(Sequential, Test_4) {
    ASSERT_EQ(true, true);
}

TEST(Sequential, Test_5) {
    ASSERT_EQ(true, true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
