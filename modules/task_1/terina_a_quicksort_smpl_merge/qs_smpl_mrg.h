// Copyright 2023 Terina Alina
#ifndef MODULES_TASK_1_TERINA_A_QS_SMPL_MRG_H_
#define MODULES_TASK_1_TERINA_A_QS_SMPL_MRG_H_

#include <time.h>
#include <random>
#include <utility>
#include <algorithm>

void get_mas_rand(double* mas, int size);
void quickSort(double* list, int left, int right);
void swap_quick(double* list, unsigned int i, unsigned int j);
int CheckSort(double* list, int n);
void Copy_elements(double* elem1, double* elem2, int n);
#endif  // MODULES_TASK_1_TERINA_A_QS_SMPL_MRG_H_
