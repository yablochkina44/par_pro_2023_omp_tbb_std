// Copyright 2023 Artemev Alexej
#include <gtest/gtest.h>
#include "./artemev_alexej_conj_grad.h"

TEST(Conjugate_gradient, TEST_random_vec) {
    std::vector<double> a = random_vec(5);
    std::vector<double> emp;
    ASSERT_NE(emp, a);
}
TEST(Conjugate_gradient, TEST_random_matrix1) {
    std::vector<std::vector<double>> A = random_matrix(5);
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


TEST(Conjugate_gradient, TEST_1000x1000) {
    int n = 11;
    std::vector<std::vector<double>> A = random_matrix(1000);
    std::vector<double> b = random_vec(1000);
    clock_t start2 = clock();
    std::vector<double> ResPar = par_conj_grad_method(A, b, n);
    clock_t finish2 = clock();
    clock_t start1 = clock();
    std::vector<double> ResSec = conj_grad_method(A, b);
    clock_t finish1 = clock();
    double TimeSec = static_cast<double>(finish1 - start1) / CLOCKS_PER_SEC;
    std::cout << "Sequental Time:" << TimeSec << std::endl;
    double TimePar = static_cast<double>(finish2 - start2) / CLOCKS_PER_SEC;
    std::cout << "Parallel Time:" << TimePar << std::endl;
    for (int i = 0; i < 1000; i++) {
        ASSERT_NEAR(ResSec[i], ResPar[i], 0.5);
    }
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
