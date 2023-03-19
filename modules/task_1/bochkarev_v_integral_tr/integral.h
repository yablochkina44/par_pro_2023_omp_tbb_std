// Copyright 2023 Bochkarev Vladimir
#ifndef MODULES_TASK_1_BOCHKAREV_V_INTEGRAL_TR_INTEGRAL_H
#define MODULES_TASK_1_BOCHKAREV_V_INTEGRAL_TR_INTEGRAL_H

#include <iostream>
#include <functional>

double integral3D(double a, double b, double c, double d, 
double e, double f, int n, const std::function<double (double, double, double)> &fun);

#endif  // MODULES_TASK_1_BOCHKAREV_V_INTEGRAL_TR_INTEGRAL_H