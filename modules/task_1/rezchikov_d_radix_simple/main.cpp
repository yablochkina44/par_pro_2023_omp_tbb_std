#include <gtest/gtest.h>
#include "./ops.h"


TEST(Sequential, Test_Size_0) {
    std::vector<int> v{};
    std::vector<int> ref{};
    mergeRadixSort(v);
    ASSERT_EQ(v, ref);
}

TEST(Sequential, Test_Size_1) {
    std::vector<int> v{1};
    std::vector<int> ref{1};
    mergeRadixSort(v);
    ASSERT_EQ(v, ref);
}

TEST(Sequential, Test_Size_100) {
    const int N = 100;
    auto vec = getRndVector(N);
    auto ref = std::vector<int>(vec);
    std::stable_sort(ref.begin(), ref.end());
    mergeRadixSort(vec);

    ASSERT_EQ(vec, ref);
}

TEST(Sequential, Test_Size_1000) {
    const int N = 1000;
    auto vec = getRndVector(N);
    auto ref = std::vector<int>(vec);
    std::stable_sort(ref.begin(), ref.end());
    mergeRadixSort(vec);

    ASSERT_EQ(vec, ref);
}

TEST(Sequential, Test_Size_100000) {
    const int N = 100000;
    auto vec = getRndVector(N);
    auto ref = std::vector<int>(vec);
    std::stable_sort(ref.begin(), ref.end());
    mergeRadixSort(vec);

    ASSERT_EQ(vec, ref);
}