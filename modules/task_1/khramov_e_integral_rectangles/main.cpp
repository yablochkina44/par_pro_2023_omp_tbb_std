// Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "../../../modules/task_1/khramov_e_integral_rectangles/khramov_e_integral_rectangles.h"

const double epsilon = 0.001;


IntegralFunction foo1 = [](double x, double y, double z) {
    return 1.0;
};

IntegralFunction foo2 = [](double x, double y, double z) {
    return x * y * z;
};

IntegralFunction foo3 = [](double x, double y, double z) {
    return x * z - y * y * y;
};

IntegralFunction foo4 = [](double x, double y, double z) {
    return 3 * exp(x) - y * z;
};

IntegralFunction foo5 = [](double x, double y, double z) {
    return sin(x) + cos(y) + 3 * z;
};

double a[3] = {1, 1, 1};
double b[3] = {2, 2, 2};
int n[3] = {100, 100, 100};

TEST(Parallel_Operations_OpenMP, Test_Integral) {
    double sequential = integrateSequential(foo1, a, b, n);
    ASSERT_NEAR(sequential, 1.0, epsilon);
}

TEST(Parallel_Operations_OpenMP, Test_Integral_2) {
    double sequential = integrateSequential(foo2, a, b, n);
    ASSERT_NEAR(sequential, 3.375, epsilon);
}


TEST(Parallel_Operations_OpenMP, Test_Integral_3) {
    double sequential = integrateSequential(foo3, a, b, n);
    ASSERT_NEAR(sequential, -1.5, epsilon);
}


TEST(Parallel_Operations_OpenMP, Test_Integral_4) {
    double sequential = integrateSequential(foo4, a, b, n);
    ASSERT_NEAR(sequential, 11.7623, epsilon);
}


TEST(Parallel_Operations_OpenMP, Test_Integral_5) {
    double sequential = integrateSequential(foo5, a, b, n);
    ASSERT_NEAR(sequential, 5.5243, epsilon);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
