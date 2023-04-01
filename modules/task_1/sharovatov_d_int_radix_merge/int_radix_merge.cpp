// Copyright 2023 Sharovatov Daniil
#include "../../../modules/task_1/sharovatov_d_int_radix_merge/int_radix_merge.h"

int getMax(const std::vector<int> arr) {
  int maxNum = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > maxNum) {
      maxNum = arr[i];
    }
  }
  return maxNum;
}

std::vector<int> radixSortForExp(std::vector<int> arr, int exp) {
  int n = arr.size();
  std::vector<int> output(n);
  std::vector<int> count(10, 0);

  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  return arr;
}

std::vector<int> radixSort(std::vector<int> arr) {
  int maxNum = getMax(arr);

  for (int exp = 1; maxNum / exp > 0; exp *= 10) {
    arr = radixSortForExp(arr, exp);
  }

  return arr;
}

std::vector<int> radixSortMerge(std::vector<int> arr) {
  if (arr.size() == 0) throw - 1;

  std::vector<int> result(arr.size());

  int half = arr.size() / 2;
  std::vector<int> first(arr.begin(), arr.begin() + half);
  std::vector<int> second(arr.begin() + half, arr.end());

  first = radixSort(first);
  second = radixSort(second);

  std::merge(first.begin(), first.end(), second.begin(), second.end(),
             result.begin());

  return result;
}

std::vector<int> getRandomVector(int size) {
  if (size <= 0) {
    throw(-1);
  }

  std::vector<int> randomVector(size);

  std::random_device dev;
  std::mt19937 gen(dev());

  for (int i = 0; i < size; i++) {
    randomVector[i] = gen() % 1000;
  }

  return randomVector;
}
