// Copyright 2023 Terina Alina
#include <gtest/gtest.h>
#include <omp.h>

#include <iostream>

#include "../../../modules/task_1/terina_a_quicksort_smpl_merge/qs_smpl_mrg.h"

TEST(Sequentional_version_QS, can_sort_mas) {
    int n = 10000;
    double* mas = new double[n];
    get_mas_rand(mas, n);
    quickSort(mas, 0, n - 1);

    ASSERT_EQ(1, CheckSort(mas, n));
}

TEST(Sequentional_version_QS, sort_already_sorted_mas) {
    int n = 10000;
    double* mas = new double[n];
    get_mas_rand(mas, n);

    std::sort(&mas[0], &mas[n]);
    quickSort(mas, 0, n - 1);

    ASSERT_EQ(1, CheckSort(mas, n));
}
TEST(Sequentional_version_QS, sort_mas_with_the_same_elems) {
    int n = 10000;
    double* mas = new double[n];
    for (int i = 0; i < n; i++) {
        mas[i] = 5;
    }
    quickSort(mas, 0, n - 1);
    ASSERT_EQ(1, CheckSort(mas, n));
}
TEST(Sequentional_version_QS, sort_mirror_mas) {
    int n = 10000;
    double* mas = new double[n], * b = new double[n];
    get_mas_rand(mas, n);

    std::sort(&mas[0], &mas[n]);
    Copy_elements(mas, b, n);

    for (int i = 0; i < n / 2; i++) {
        std::swap(mas[i], mas[n - i - 1]);
    }

    quickSort(mas, 0, n - 1);

    bool res = std::equal(&mas[0], &mas[n], &b[0]);
    ASSERT_EQ(1, res);
}

TEST(Sequentional_version_QS, one_elem_in_mass) {
    int n = 10000;
    double* mas = new double[n];
    mas[0] = 1;
    quickSort(mas, 0, n - 1);
    ASSERT_EQ(mas[n - 1], 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
