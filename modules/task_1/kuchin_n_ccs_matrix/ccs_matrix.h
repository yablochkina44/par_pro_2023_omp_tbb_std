// Copyright 2023 Kuchin Nikita
#ifndef MODULES_TASK_1_KUCHIN_N_CCS_MATIX_CCS_MATRIX_H_
#define MODULES_TASK_1_KUCHIN_N_CCS_MATIX_CCS_MATRIX_H_

#include <vector>
struct SparceMatrix {
    std::vector<double> data;
    std::vector<int> row_id;
    std::vector<int> col_ptr;
};

#endif  // MODULES_TASK_1_KUCHIN_N_CCS_MATIX_CCS_MATRIX_H_
