// Copyright 2022 Kuchin Nikita

#include <gtest/gtest.h>

#include "./ccs_matrix.h"

TEST(Str, test1) { EXPECT_EQ(1, 1); }

TEST(Str, test2) { EXPECT_EQ(1, 1); }

TEST(Str, test3) { EXPECT_EQ(1, 1); }
TEST(Str, test4) { EXPECT_EQ(1, 1); }
TEST(Str, test5) { EXPECT_EQ(2, 2); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}