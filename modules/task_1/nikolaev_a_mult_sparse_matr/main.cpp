// Copyright 2023 Nikolaev Alexander
#include <gtest/gtest.h>
#include "./sparse_matrix.h"

TEST(Sparse_Matrix_Mult, Test_Mult1) {
    const int N = 6;
    CCSMatrix A;
    CCSMatrix B;
    CCSMatrix C;
    std::vector<std::vector<Complex>> matrixA = { {0, 8, 0, 0, 1, 0},
                                                {0, 0, 7, 0, 0, 4},
                                                {5, 0, 0, 3, 0, 0},
                                                {0, 2, 0, 0, 1, 7},
                                                {0, 6, 3, 0, 0, 1},
                                                {4, 0, 0, 1, 0, 0}};

    std::vector<std::vector<Complex>> matrixB = { {0, 8, 0, 0, 1, 0},
                                                {0, 0, 7, 0, 0, 4},
                                                {5, 0, 0, 3, 0, 0},
                                                {0, 2, 0, 0, 1, 7},
                                                {0, 6, 3, 0, 0, 1},
                                                {4, 0, 0, 1, 0, 0} };
    std::vector<Complex> result = { 51, 28, 19, 6, 46, 6, 34, 59, 17, 42, 25,
        7, 10, 8, 5, 33, 21, 9, 24, 7 };
    A = MatrixtoCCSMatrix(matrixA);
    B = MatrixtoCCSMatrix(matrixB);
    TransposeMatrix(B);
    C = Multiplicate(A, B);
    ASSERT_EQ(C.value, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}