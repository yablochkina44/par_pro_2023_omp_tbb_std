// Copyright 2023 Bulgakov Daniil

// Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>

#include "../../../modules/task_1/bulgakov_d_slau_gradient/slau_gradient.h"


const double SML = 1.0e-4;

void GoogleAssertNear(dvec a, dvec b, double smol) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            ASSERT_NEAR(a[i], b[i], smol);
        }
    }
}

TEST(Sequential, Test_1) {
    dmat A =  {{4, 1}, {1, 3}};
    dvec B = {1, 2};
    dvec ans = {0.0909, 0.6364};
    dvec solved = solve(A, B);
    GoogleAssertNear(solved, ans, SML);
}

TEST(Sequential, Test_2) {
    dmat A =  {{ 2.5409, -0.0113}, {-0.0113,  0.5287}};
    dvec B = {1.3864,  0.3719};
    dvec ans = {0.5488, 0.7151};
    dvec solved = solve(A, B);
    GoogleAssertNear(solved, ans, SML);
}

TEST(Sequential, Test_3) {
    dmat A =   {{ 0.7444, -0.5055, -0.0851},
                {-0.5055,  3.4858,  0.0572},
                {-0.0851,  0.0572,  0.4738}};
    dvec B = {-0.0043,  2.2501,  0.2798};
    dvec ans = { 0.5488,  0.7152,  0.6028};
    dvec solved = solve(A, B);
    GoogleAssertNear(solved, ans, SML);
}

TEST(Sequential, Test_4) {
    dmat A =   {{1.47291346, 1.44411773, 1.56851324, 1.06402062},
                {1.44411773, 1.58340425, 1.47402593, 0.94727625},
                {1.56851324, 1.47402593, 1.98223169, 1.00463884},
                {1.06402062, 0.94727625, 1.00463884, 1.1920414 }};
    dvec B = {3.37844107, 3.31873662, 3.67555103, 2.62909079};
    dvec ans = { 0.02022, 0.83262, 0.77816, 0.87001};
    dvec solved = solve(A, B);
    GoogleAssertNear(solved, ans, SML);
}

TEST(Sequential, Test_5) {
    dmat A =    {{ 3.4430, -0.3963,  2.5012,  0.9525,  0.6084, -1.2728},
                {-0.3963,  0.6015, -0.4108, -0.1359, -0.0295,  0.2630},
                { 2.5012, -0.4108,  2.5927,  0.7072,  0.5587, -1.0613},
                { 0.9525, -0.1359,  0.7072,  1.1634,  0.1920, -0.4344},
                { 0.6084, -0.0295,  0.5587,  0.1920,  0.7636, -0.3261},
                {-1.2728,  0.2630, -1.0613, -0.4344, -0.3261, 1.0869}};
    dvec B = { 3.0685,  0.0484,  2.5783,  1.2865,  0.8671, -0.8230};
    dvec ans = { 0.5488,  0.7152,  0.6028, 0.5449,  0.4237,  0.6459};
    dvec solved = solve(A, B);
    GoogleAssertNear(solved, ans, SML);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



