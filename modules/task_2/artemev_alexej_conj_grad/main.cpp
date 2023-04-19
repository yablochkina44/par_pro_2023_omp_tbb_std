// Copyright 2023 Artemev Alexej
#include <gtest/gtest.h>
#include "./artemev_alexej_conj_grad.h"

TEST(Conjugate_gradient, TEST_random_vec) {
    std::vector<double> a = random_vec(5);
    std::vector<double> emp;
    ASSERT_NE(emp, a);
}

TEST(Conjugate_gradient, TEST_100x100) {
    int n = 4;
    std::vector<std::vector<double>> A = random_matrix(100);
    std::vector<double> b = random_vec(100);
    std::vector<double> ResPar = par_conj_grad_method(A, b, n);
    for (int i = 0; i < 100; i++) {
        ASSERT_NEAR(ResPar[i], 0.5);
    }
}

TEST(Conjugate_gradient, TEST_random_matrix1) {
    std::vector<std::vector<double>> A = random_matrix(5);
    std::vector<std::vector<double>> emp;
    ASSERT_NE(emp, A);
}

TEST(Conjugate_gradient, TEST_random_matrix3) {
    std::vector<std::vector<double>> A = random_matrix(6);
    std::vector<std::vector<double>> emp;
    ASSERT_NE(emp, A);
}

TEST(Conjugate_gradient, TEST_random_matrix4) {
    std::vector<std::vector<double>> A = random_matrix(6);
    std::vector<std::vector<double>> emp;
    ASSERT_NE(emp, A);
}
TEST(Conjugate_gradient, TEST_random_matrix2) {
    std::vector<std::vector<double>> A = random_matrix(5);
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            ASSERT_EQ(A[i][j], A[j][i]);
        }
    }
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
