// Copyright 2023 Mironov Nikita
#ifndef MODULES_TASK_1_KOLESNIKOV_D_INTEGRAL_SEQ_INTEGRAL_H_
#define MODULES_TASK_1_KOLESNIKOV_D_INTEGRAL_SEQ_INTEGRAL_H_

#include <vector>
#include <utility>

double trapezoid_method(
    double f(std::vector<double>),
    const std::vector<std::pair<double, double>> bounds,
    int dimensions,
    int N
);


#endif  // MODULES_TASK_1_MIRONOV_N_TRAPEZOID_METHOD_H_
