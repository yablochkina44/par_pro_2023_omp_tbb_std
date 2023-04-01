// Copyright 2023 Sharovatov Daniil
#ifndef MODULES_TASK_1_SHAROVATOV_D_INT_RADIX_MERGE_INT_RADIX_MERGE_H_
#define MODULES_TASK_1_SHAROVATOV_D_INT_RADIX_MERGE_INT_RADIX_MERGE_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

int getMax(std::vector<int> arr);

std::vector<int> radixSortForExp(std::vector<int> arr, int exp);

std::vector<int> radixSort(std::vector<int> arr);

std::vector<int> radixSortMerge(std::vector<int> arr);

std::vector<int> getRandomVector(int size);

#endif  // MODULES_TASK_1_SHAROVATOV_D_INT_RADIX_MERGE_INT_RADIX_MERGE_H_
