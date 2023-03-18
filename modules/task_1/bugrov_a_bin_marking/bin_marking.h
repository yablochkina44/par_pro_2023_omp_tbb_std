#pragma once
#include <time.h>  // rand seed

#include <map>       // pairs
#include <queue>     // queue for Depth-first search
#include <random>    // mt19937
using namespace std;

// void seq_marking(const vector<vector<int>>& image, const int N,
//                vector<vector<int>>& marks, const int k_unnamed);
void marking(int** image, const int n, const int m, int** marks,
             const int k_unnamed);
void marking(const vector<vector<int>>& image, const int n, const int m,
             vector<vector<int>>& marks, const int k_unnamed);
void par_marking(const int& thread_num, const int& n, const int& m,
                 int**& image, int**& marks, const int& k_unnamed);
void create_arrays(const int& n, const int& m, int**& image, int**& marks,
                   const int& k_unnamed);
void create_random_image(int**& image, const int& n, const int& m);
// bool are_matrix_eq(const int**& a, const int**& b, const int n, const int m);

bool are_matrix_eq(const vector<vector<int>>& a, const vector<vector<int>>& b,
                   int n, int m);
