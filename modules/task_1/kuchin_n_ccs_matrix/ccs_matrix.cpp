// Copyright 2023 Kuchin Nikita

#include "../../../modules/task_1/kuchin_n_ccs_matrix/ccs_matrix.h"

SparceMatrix multiply(SparceMatrix A, SparceMatrix B) {
    SparceMatrix C;
    std::vector<double> temp(A.col_ptr.size() - 1);
    for (int j = 0; j < B.col_ptr.size() - 1; j++) {
        fill(temp.begin(), temp.end(), 0);
        for (int k = B.col_ptr[j]; k < B.col_ptr[j + 1]; k++) {
            int row = B.row_id[k];
            double val = B.data[k];
            for (int i = A.col_ptr[row]; i < A.col_ptr[row + 1]; i++) {
                int col = A.row_id[i];
                temp[col] += A.data[i] * val;
            }
        }
        C.col_ptr.push_back(C.data.size());
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] != 0) {
                C.data.push_back(temp[i]);
                C.row_id.push_back(i);
            }
        }
    }
    C.col_ptr.push_back(C.data.size());
    return C;
}