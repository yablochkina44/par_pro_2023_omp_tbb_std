// Copyright 2022 Kuchin Nikita

#include <gtest/gtest.h>

#include "./ccs_matrix.h"

TEST(Str, test1) {
    SparceMatrix A;
    A.n = 3;
    A.data = {1.2, 3.4, 5.1};
    A.row_id = {2, 0, 0};
    A.col_ptr = {0, 1, 2, 3};
    SparceMatrix B;
    B.n = 3;
    B.data = {6.22, 2.18};
    B.row_id = {2, 1};
    B.col_ptr = {0, 1, 1, 2};
    SparceMatrix C;
    C.n = 3;
    C.data = {31.722, 7.412};
    C.row_id = {0, 0};
    C.col_ptr = {0, 1, 1, 2};
    SparceMatrix res = multiply(A, B);
    EXPECT_EQ(C.data, res.data);
    EXPECT_EQ(C.row_id, res.row_id);
    EXPECT_EQ(C.col_ptr, res.col_ptr);
}

TEST(Str, test2) {
    SparceMatrix A;
    A.n = 4;
    A.data = {2.86, 9.71, 1.15, 3.39};
    A.row_id = {0, 3, 1, 2};
    A.col_ptr = {0, 2, 2, 3, 4};
    SparceMatrix B;
    B.n = 4;
    B.data = {1.75, 2.93, 6.55, 1.93, 3.12};
    B.row_id = {1, 2, 0, 2, 3};
    B.col_ptr = {0, 1, 2, 5, 5};
    SparceMatrix C;
    C.n = 4;
    C.data = {3.3695, 18.733, 2.2195, 10.5768, 63.6005};
    C.row_id = {1, 0, 1, 2, 3};
    C.col_ptr = {0, 0, 1, 5, 5};
    SparceMatrix res = multiply(A, B);
    EXPECT_EQ(C.data, res.data);
    EXPECT_EQ(C.row_id, res.row_id);
    EXPECT_EQ(C.col_ptr, res.col_ptr);
}

TEST(Str, test3) {
    SparceMatrix A;
    A.n = 6;
    A.data = {1, 7, 3, 4, 2, 2, 5};
    A.row_id = {0, 5, 1, 1, 3, 0, 3};
    A.col_ptr = {0, 1, 2, 3, 5, 6, 7};
    SparceMatrix B;
    B.n = 6;
    B.data = {3, 1, 2, 1, 3, 3, 4, 1};
    B.row_id = {0, 4, 5, 1, 4, 3, 5, 0};
    B.col_ptr = {0, 2, 3, 5, 6, 7, 8};
    SparceMatrix C;
    C.n = 6;
    C.data = {5, 10, 6, 7, 12, 6, 20, 1};
    C.row_id = {0, 3, 0, 5, 1, 3, 3, 0};
    C.col_ptr = {0, 1, 2, 4, 6, 7, 8};
    SparceMatrix res = multiply(A, B);
    EXPECT_EQ(C.data, res.data);
    EXPECT_EQ(C.row_id, res.row_id);
    EXPECT_EQ(C.col_ptr, res.col_ptr);
}
TEST(Str, test4) {
    SparceMatrix A;
    A.n = 5;
    A.data = {8.85, 7.69, 2.56, 12.85, 19.47, 4.53, 15.81};
    A.row_id = {0, 3, 2, 3, 1, 3, 2};
    A.col_ptr = {0, 2, 3, 4, 6, 7};
    SparceMatrix B;
    B.n = 5;
    B.data = {9.77, 1.05, 8.38, 15.54, 8.07, 7.27, 6.24};
    B.row_id = {3, 1, 3, 4, 4, 1, 2};
    B.col_ptr = {0, 1, 2, 4, 5, 7};
    SparceMatrix C;
    C.n = 5;
    C.data = {190.2219, 44.2581,  2.688,   163.1586, 245.6874,
              37.6914,  127.5867, 18.6112, 80.184};
    C.row_id = {1, 3, 2, 1, 2, 3, 2, 2, 3};
    C.col_ptr = {0, 2, 3, 6, 7, 9};
    SparceMatrix res = multiply(A, B);
    EXPECT_EQ(C.data, res.data);
    EXPECT_EQ(C.row_id, res.row_id);
    EXPECT_EQ(C.col_ptr, res.col_ptr);
}
TEST(Str, test5) {
    SparceMatrix A;
    A.n = 6;
    A.data = {1.81, 7.47, 8.3, 5.62, 5.54, 8.36, 0.22, 0.69};
    A.row_id = {0, 4, 1, 2, 3, 0, 5};
    A.col_ptr = {0, 2, 3, 4, 6, 7, 8};
    SparceMatrix B;
    B.n = 6;
    B.data = {1.3, 2.5, 8.95, 3.11, 2.28, 3.22, 1.44, 6.55};
    B.row_id = {2, 4, 2, 1, 3, 5, 1, 4};
    B.col_ptr = {0, 1, 2, 3, 5, 6, 8};
    SparceMatrix C;
    C.n = 6;
    C.data = {7.306, 0.55, 50.299, 12.6312, 44.8738, 2.2218, 1.441, 11.952};
    C.row_id = {1, 0, 1, 2, 3, 5, 0, 3};
    C.col_ptr = {0, 1, 2, 3, 5, 6, 8};
    SparceMatrix res = multiply(A, B);
    EXPECT_EQ(C.data, res.data);
    EXPECT_EQ(C.row_id, res.row_id);
    EXPECT_EQ(C.col_ptr, res.col_ptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
