// Copyright 2023 Pinezhanin Evgeny
#ifndef MODULES_TASK_1_PINEZHANIN_E_MONTE_CARLO_MONTE_CARLO_H
#define MODULES_TASK_1_PINEZHANIN_E_MONTE_CARLO_MONTE_CARLO_H

#include <vector>
#include <functional>

int getIntegralMonteCarlo(const std::function<double(std::vector<double>)>& f, std::vector<double> a, std::vector<double> b, int n);

#endif  // MODULES_TASK_1_PINEZHANIN_E_MONTE_CARLO_MONTE_CARLO_H
