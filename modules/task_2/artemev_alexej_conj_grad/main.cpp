// Copyright 2023 Artemev Alexej
#include <gtest/gtest.h>
#include "./artemev_alexej_conj_grad.h"


TEST(PAR_CONJ_GRAD, TEST_2x2) {
    int n = 2;
    std::vector<std::vector<double>> A = { { 3, 2}, {2, 4} };
    std::vector<double> b = { 1, 5 };
    std::vector<double> sol = par_conj_grad_method(A, b, n);
    std::vector<double> res = { -0.75, 1.625 };
    for (size_t i = 0; i < res.size(); ++i) {
        ASSERT_NEAR(sol[i], res[i], 0.5);
    }
}

TEST(PAR_CONJ_GRAD, TEST_3x3) {
    int n = 3;
    std::vector<std::vector<double>> A = { { 3, 4, 0}, {4, -3, 0}, {0, 0, 5} };
    std::vector<double> betta = { 1, 5, 9 };
    std::vector<double> result = { 0.92, -0.44, 1.8 };
    std::vector<double> decision = par_conj_grad_method(A, betta, n);

    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_NEAR(decision[i], result[i], 0.5);
    }
}

TEST(PAR_CONJ_GRAD, TEST2_3x3) {
    int n = 3;
    std::vector<std::vector<double>> A = { { 3.2, -1.7, 2.5}, {1.5, 6.2, -2.9}, {2.8, -1.7, 3.8} };
    std::vector<double> betta = { 3.7, 3.2, 2.8 };
    std::vector<double> result = { 2.094, -0.465, -1.015 };
    std::vector<double> decision = par_conj_grad_method(A, betta, n);

    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_NEAR(decision[i], result[i], 0.5);
    }
}

TEST(PAR_CONJ_GRAD, TEST_5x5) {
    int n = 4;
    std::vector<std::vector<double>> A = { {5, 4, 0, 3, 6},
                                           {4, 6, 1, 5, 7},
                                           {0, 1, 0, 1, 1},
                                           {3, 5, 1, 5, 6},
                                           {6, 7, 1, 6, 10}, };
    std::vector<double> betta = { 2, 5, 0, 9, 1 };

    std::vector<double> x = par_conj_grad_method(A, betta, n);
    std::vector<double> result = { 5, -2, 1, 9, -7 };
    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_NEAR(x[i], result[i], 0.5);
    }
}

TEST(PAR_CONJ_GRAD, TEST2_5x5) {
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


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
