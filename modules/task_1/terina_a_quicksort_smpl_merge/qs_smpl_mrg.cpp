// Copyright 2023 Terina Alina
#include <ctime>
#include <random>
#include <utility>
#include "../../../modules/task_1/terina_a_quicksort_smpl_merge/qs_smpl_mrg.h"

void get_mas_rand(double* list, int size) {
    std::mt19937 generator(time(0));
    std::uniform_int_distribution<> dist(-1000, 1000);
    for (int i = 0; i <= size; i++) {
        list[i] = dist(generator);
    }
}

void quickSort(double* list, int lo, int hi) {
    int i = lo, j = hi;
    double p = list[(lo + hi) / 2];

    do {
        while (list[i] < p) i++;
        while (list[j] > p) j--;
        if (i <= j) {
            if (i < j) {
                swap_quick(list, i, j);
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < hi) quickSort(list, i, hi);
    if (lo < j) quickSort(list, lo, j);
}

void swap_quick(double* list, unsigned int i, unsigned int j) {
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
int CheckSort(double* list, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (list[i] > list[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void Copy_elements(double* elem1, double* elem2, int n) {
    for (int i = 0; i < n; i++) {
        elem2[i] = elem1[i];
    }
}
