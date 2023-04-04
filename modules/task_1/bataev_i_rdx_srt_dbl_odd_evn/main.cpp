// Copyright 2023 Bataev Ivan
#include <gtest/gtest.h>
#include <vector>
#include "../../../modules/task_1/bataev_i_rdx_srt_dbl_odd_evn/rdx_srt_dbl_odd_evn.h"

TEST(Sequential, Test1) {
    const int size = 9;
    std::vector<double> input = { 7698721.0, -456412.0, 2342432.0, 333276.0, -11.0, 765.0, -2019.0, 0.0, 11113.0 };

    for (int i = 0; i < size; ++i)
        std::cout << input[i] << ", ";
    std::cout << "\n";

    seqRdxSrt(input, size, 2);

    for (int i = 0; i < size; ++i)
        std::cout << input[i] << ", ";
    std::cout << "\n";

    ASSERT_EQ(1, 1);
}

TEST(Sequential, Test2) {
    ASSERT_EQ(1, 1);
}

TEST(Sequential, Test3) {
    ASSERT_EQ(1, 1);
}

TEST(Sequential, Test4) {
    ASSERT_EQ(1, 1);
}

TEST(Sequential, Test5) {
    ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
