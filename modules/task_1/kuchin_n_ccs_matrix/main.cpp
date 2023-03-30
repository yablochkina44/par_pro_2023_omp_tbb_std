// Copyright 2022 Kuchin Nikita

#include <gtest/gtest.h>

#include "./ccs_matrix.h"

TEST(Str, test1) {
    SparceMatrix A;
    A.data = {9, 3, 8, 15, 7, 16};
    A.row_id = {3, 0, 1, 3, 0, 3};
    A.col_ptr = {0, 1, 2, 4, 6};
    SparceMatrix B;
    B.data = {3, 7, 8, 9, 15, 16};
    B.row_id = {1, 3, 2, 0, 2, 3};
    B.col_ptr = {0, 2, 3, 3, 6};
    SparceMatrix C = transport(A);
    EXPECT_EQ(A.data, C.data);
    EXPECT_EQ(A.row_id, C.row_id);
    EXPECT_EQ(A.col_ptr, C.col_ptr);
}

TEST(Str, test2) { EXPECT_EQ(1, 1); }

TEST(Str, test3) { EXPECT_EQ(1, 1); }
TEST(Str, test4) { EXPECT_EQ(1, 1); }
TEST(Str, test5) { EXPECT_EQ(2, 2); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
