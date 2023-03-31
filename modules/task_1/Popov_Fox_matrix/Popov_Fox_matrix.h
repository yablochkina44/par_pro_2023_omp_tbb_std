// Copyright 2023 Popov Andrey
#ifndef MODULES_TASK_1_Popov_Fox_matrix
#define MODULES_TASK_1_Popov_Fox_matrix

#include <vector>

using matrix = std::vector<std::vector<double>>;

matrix simpleMult(const matrix& X, const matrix& Y);
matrix foxMult(const matrix& X, const matrix& Y, const int& sizeb);
matrix randMatrix(const int& cnt);

#endif  // MODULES_TASK_1_Popov_Fox_matrix