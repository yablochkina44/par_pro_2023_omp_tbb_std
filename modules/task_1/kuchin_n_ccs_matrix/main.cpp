// Copyright 2022 Kuchin Nikita

#include <gtest/gtest.h>

#include "./ccs_matrix.h"

TEST(Str, test1) {
    SparceMatrix A;
    A.n = 4;
    A.data = {9, 3, 8, 15, 7, 16};
    A.row_id = {3, 0, 1, 3, 0, 3};
    A.col_ptr = {0, 1, 2, 4, 6};
    SparceMatrix B;
    B.data = {3, 7, 8, 9, 15, 16};
    B.row_id = {1, 3, 2, 0, 2, 3};
    B.col_ptr = {0, 2, 3, 3, 6};
    SparceMatrix C = transport(A);
    EXPECT_EQ(B.data, C.data);
    EXPECT_EQ(B.row_id, C.row_id);
    EXPECT_EQ(B.col_ptr, C.col_ptr);
}

TEST(Str, test2) {
    SparceMatrix A;
    A.n = 4;
    A.data = {2.37, 3.65, 1.22, 7.63, 4.22};
    A.row_id = {0, 2, 3, 3, 0};
    A.col_ptr = {0, 2, 3, 3, 4, 5};
    SparceMatrix B;
    B.data = {2.37, 4.22, 3.65, 1.22, 7.63};
    B.row_id = {0, 4, 0, 1, 3};
    B.col_ptr = {0, 2, 2, 3, 5, 5};
    SparceMatrix C = transport(A);
    EXPECT_EQ(B.data, C.data);
    EXPECT_EQ(B.row_id, C.row_id);
    EXPECT_EQ(B.col_ptr, C.col_ptr);
}

TEST(Str, test3) { EXPECT_EQ(1, 1); }
TEST(Str, test4) { EXPECT_EQ(1, 1); }
TEST(Str, test5) { EXPECT_EQ(2, 2); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
