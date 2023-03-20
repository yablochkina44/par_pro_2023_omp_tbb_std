// Copyright 2023 Pinezhanin Evgeny
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "./monte_carlo.h"

TEST(Monte_Carlo_seq, Test_one_dimension) {
    const std::function<double(const std::vector<double>)> f = 
            [](const std::vector<double> x) -> double { return x[0] * x[0]; };
    std::vector<double> a = { 0.0 }, b = { 10.0 };
    int number_points = 1000000;
    double exact_value_integral = 1000.0 / 3.0;
    double abs_error = 1.0;

    double calc_value_integral = getIntegralMonteCarlo(f, a, b, number_points);
 
    std::cout << exact_value_integral << " " << calc_value_integral << std::endl;
    ASSERT_NEAR(calc_value_integral, exact_value_integral, abs_error);
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
