// Copyright 2023 Bataev Ivan
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "../../../modules/task_1/bataev_i_rdx_srt_dbl_odd_evn/rdx_srt_dbl_odd_evn.h"

TEST(Sequential, Test_RadixSort) {
    const int size = 9;
    std::vector<double> v1 = { 7698721.0, -456412.0, 2342432.0, 333276.0, -11.0, 765.0, -2019.0, 0.0, 11113.0 };
    std::vector<double> v2(v1);
    printVector(v1);

    seqRdxSrt(&v1, size);
    printVector(v1);

    std::sort(v2.begin(), v2.end());
    ASSERT_EQ(v1, v2);
}

TEST(Sequential, Test_OddEvenMerge) {
    std::vector<double> v1 = { -33.5539, -16.0284, 0.0245546, 63.516,
                                    -3.70987, 1.50916, 9.31509, 48.857,
                                        -39.0917, 0.0, 1.59403, 16.7192 };
    // all 3 parts are sorted and the same size 4
    std::vector<double> v2(v1);
    printVector(v1);

    std::vector<double> tmp(v1.size());
    std::vector<double*> ptrs = {v1.data(), v1.data() + 4, v1.data() + 8};
    std::vector<double*> tmpPtrs = {tmp.data(), tmp.data() + 4, tmp.data() + 8};
    int numParts = 3;
    int lSize = 4;
    oddEvnMerge(&v1, &tmp, ptrs, tmpPtrs, numParts, lSize);
    // sorting network that was built and used: [(1, 2), (0, 1), (1, 2)]
    // (order of merging 3 parts of v1)
    printVector(v1);

    std::sort(v2.begin(), v2.end());
    ASSERT_EQ(v1, v2);
}

TEST(Sequential, Test_RadixSort_OddEvenMerge_1) {
    const int size = 9;
    std::vector<double> v1 = { 7698721.0, -456412.0, 2342432.0, 333276.0, -11.0, 765.0, -2019.0, 0.0, 11113.0 };
    std::vector<double> v2(v1);

    seqRdxSrt(&v1, size, 3);
    // sorting network that was built and used: [(1, 2), (0, 1), (1, 2)]
    // (order of merging 3 parts of v1)

    std::sort(v2.begin(), v2.end());
    ASSERT_EQ(v1, v2);
}

TEST(Sequential, Test_RadixSort_OddEvenMerge_2) {
    const int size = 17; const double left = -100.0; const double right = 100.0;
    std::vector<double> v1 = getRandomVector(size, left, right);
    std::vector<double> v2(v1);

    seqRdxSrt(&v1, size, 6);  // 17 % 3 = 2 -> temp elem will be added
    // sorting network that was built and used:
    // [(1, 2), (0, 1), (1, 2), (4, 5), (3, 4), (4, 5),
    // (0, 3), (2, 5), (2, 3), (1, 4), (1, 2), (3, 4)]
    // (order of merging 6 parts of v1)

    std::sort(v2.begin(), v2.end());
    ASSERT_EQ(v1, v2);
}

TEST(Sequential, Test_RadixSort_OddEvenMerge_3) {
    const int size = 1000; const double left = -1000.0; const double right = 1000.0;
    std::vector<double> v1 = getRandomVector(size, left, right);
    std::vector<double> v2(v1);

    seqRdxSrt(&v1, size, 6);

    std::sort(v2.begin(), v2.end());
    ASSERT_EQ(v1, v2);
}

TEST(Sequential, Test_RadixSort_OddEvenMerge_4) {
    const int size = 100000; const double left = -1000.0; const double right = 1000.0;
    std::vector<double> v1 = getRandomVector(size, left, right);
    std::vector<double> v2(v1);

    seqRdxSrt(&v1, size, 12);

    std::sort(v2.begin(), v2.end());
    ASSERT_EQ(v1, v2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
