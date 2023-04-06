// Copyright 2023 Tychinin Alexey

#include "shell_sort.h"  // NOLINT

namespace task1 {
    std::vector<double> shell_sort(const std::vector<double>& vec) {
        std::vector<double> res{vec};
        for (int interval = res.size() / 2; interval > 0; interval /= 2) {
            for (int i = interval; i < res.size(); i++) {
                double tmp = res[i];
                int j = i;
                for (; j >= interval && res[j - interval] > tmp; j -= interval) {
                    res[j] = res[j - interval];
                }
                res[j] = tmp;
            }
        }

        return res;
    }

}  // namespace task1
