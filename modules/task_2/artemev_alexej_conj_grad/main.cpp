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
TEST(Conjugate_gradient, TEST_2x2) {
    int n = 2;
    std::vector<std::vector<double>> A = { { 3, 2}, {2, 4} };
    std::vector<double> b = { 1, 5 };
    std::vector<double> sol = par_conj_grad_method(A, b, n);
    std::vector<double> res = { -0.75, 1.625 };
    for (size_t i = 0; i < res.size(); ++i) {
        ASSERT_NEAR(sol[i], res[i], 0.5);
    }
}
TEST(Conjugate_gradient, TEST_5x5) {
    int n = 5;
    std::vector<std::vector<double>> A = { {3, 2, 3, 1, 2},
                                           {2, 4, 1, 4, 3},
                                           {3, 1, 6, 2, 5},
                                           {1, 4, 2, 8, 7},
                                           {2, 3, 5, 7, 11}, };
    std::vector<double> b = { 4, 6, 3, 1, 8};
    std::vector<double> x = par_conj_grad_method(A, b, n);
    std::vector<double> res = { -3.576, 6, 0.94565, -4.6521, 2.2717};
    for (size_t i = 0; i < res.size(); ++i) {
        ASSERT_NEAR(x[i], res[i], 0.5);
    }
}
TEST(Conjugate_gradient, TEST_100x100) {
    int n = 11;
    std::vector<std::vector<double>> A = random_matrix(100);
    std::vector<double> b = random_vec(100);
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
    for (int i = 0; i < 100; i++) {
        ASSERT_NEAR(ResSec[i], ResPar[i], 0.5);
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
