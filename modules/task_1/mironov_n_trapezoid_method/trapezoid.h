// Copyright 2023 Mironov Nikita
#ifndef _MODULES_TASK_1_KOLESNIKOV_D_INTEGRAL_SEQ_INTEGRAL_H_
#define _MODULES_TASK_1_KOLESNIKOV_D_INTEGRAL_SEQ_INTEGRAL_H_

#include <vector>
#include <utility>

double trapezoid_method(
    (*f)(std::vector<double>),
    const std::vector<std::pair<double, double>> bounds,
    int dimensions,
    int N
);


#endif  // _MODULES_TASK_1_MIRONOV_N_TRAPEZOID_METHOD_H_
