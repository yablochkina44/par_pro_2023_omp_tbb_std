#include "bin_marking.h"

// void seq_marking(const vector<vector<int>>& image, const int N,
//                 vector<vector<int>>& marks, const int k_unnamed = 0,
//                 const int connectivity = 4) {
//  int cur_mark = 0;
//  const int k_back = 1;
//  queue<pair<int, int>> cur_queue;
//
//  for (int i = 0; i < N; i++) {
//    for (int j = 0; j < N; j++) {
//      if (image[i][j] != k_back && marks[i][j] == k_unnamed) {
//        cur_mark += 1;
//        marks[i][j] = cur_mark;
//        cur_queue.push(pair<int, int>(i, j));
//        while (!cur_queue.empty()) {
//          pair<int, int> tmp = cur_queue.front();
//          cur_queue.pop();
//          if (tmp.first - 1 >= 0) {
//            if (marks[tmp.first - 1][tmp.second] == k_unnamed &&
//                image[tmp.first - 1][tmp.second] != k_back) {
//              marks[tmp.first - 1][tmp.second] = cur_mark;
//              cur_queue.push(pair<int, int>(tmp.first - 1, tmp.second));
//            }
//          }
//          if (tmp.second - 1 >= 0) {
//            if (marks[tmp.first][tmp.second - 1] == k_unnamed &&
//                image[tmp.first][tmp.second - 1] != k_back) {
//              marks[tmp.first][tmp.second - 1] = cur_mark;
//              cur_queue.push(pair<int, int>(tmp.first, tmp.second - 1));
//            }
//          }
//          if (tmp.first + 1 < N) {
//            if (marks[tmp.first + 1][tmp.second] == k_unnamed &&
//                image[tmp.first + 1][tmp.second] != k_back) {
//              marks[tmp.first + 1][tmp.second] = cur_mark;
//              cur_queue.push(pair<int, int>(tmp.first + 1, tmp.second));
//            }
//          }
//          if (tmp.second + 1 < N) {
//            if (marks[tmp.first][tmp.second + 1] == k_unnamed &&
//                image[tmp.first][tmp.second + 1] != k_back) {
//              marks[tmp.first][tmp.second + 1] = cur_mark;
//              cur_queue.push(pair<int, int>(tmp.first, tmp.second + 1));
//            }
//          }
//        }
//      }
//    }
//  }
//}

// matrixes can be both vectors and arrays
void marking(int** image, const int n, const int m, int** marks,
             const int k_unnamed = 0) {
  int cur_mark = 0;
  const int k_back = 1;
  queue<pair<int, int>> cur_queue;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (image[i][j] != k_back && marks[i][j] == k_unnamed) {
        cur_mark += 1;
        marks[i][j] = cur_mark;
        cur_queue.push(pair<int, int>(i, j));
        while (!cur_queue.empty()) {
          pair<int, int> tmp = cur_queue.front();
          cur_queue.pop();
          if (tmp.first - 1 >= 0) {
            if (marks[tmp.first - 1][tmp.second] == k_unnamed &&
                image[tmp.first - 1][tmp.second] != k_back) {
              marks[tmp.first - 1][tmp.second] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first - 1, tmp.second));
            }
          }
          if (tmp.second - 1 >= 0) {
            if (marks[tmp.first][tmp.second - 1] == k_unnamed &&
                image[tmp.first][tmp.second - 1] != k_back) {
              marks[tmp.first][tmp.second - 1] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first, tmp.second - 1));
            }
          }
          if (tmp.first + 1 < n) {
            if (marks[tmp.first + 1][tmp.second] == k_unnamed &&
                image[tmp.first + 1][tmp.second] != k_back) {
              marks[tmp.first + 1][tmp.second] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first + 1, tmp.second));
            }
          }
          if (tmp.second + 1 < m) {
            if (marks[tmp.first][tmp.second + 1] == k_unnamed &&
                image[tmp.first][tmp.second + 1] != k_back) {
              marks[tmp.first][tmp.second + 1] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first, tmp.second + 1));
            }
          }
        }
      }
    }
  }
}
// matrixes can be both vectors and arrays
void marking(const vector<vector<int>>& image, const int n, const int m,
             vector<vector<int>>& marks, const int k_unnamed = 0) {
  int cur_mark = 0;
  const int k_back = 1;
  queue<pair<int, int>> cur_queue;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (image[i][j] != k_back && marks[i][j] == k_unnamed) {
        cur_mark += 1;
        marks[i][j] = cur_mark;
        cur_queue.push(pair<int, int>(i, j));
        while (!cur_queue.empty()) {
          pair<int, int> tmp = cur_queue.front();
          cur_queue.pop();
          if (tmp.first - 1 >= 0) {
            if (marks[tmp.first - 1][tmp.second] == k_unnamed &&
                image[tmp.first - 1][tmp.second] != k_back) {
              marks[tmp.first - 1][tmp.second] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first - 1, tmp.second));
            }
          }
          if (tmp.second - 1 >= 0) {
            if (marks[tmp.first][tmp.second - 1] == k_unnamed &&
                image[tmp.first][tmp.second - 1] != k_back) {
              marks[tmp.first][tmp.second - 1] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first, tmp.second - 1));
            }
          }
          if (tmp.first + 1 < n) {
            if (marks[tmp.first + 1][tmp.second] == k_unnamed &&
                image[tmp.first + 1][tmp.second] != k_back) {
              marks[tmp.first + 1][tmp.second] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first + 1, tmp.second));
            }
          }
          if (tmp.second + 1 < m) {
            if (marks[tmp.first][tmp.second + 1] == k_unnamed &&
                image[tmp.first][tmp.second + 1] != k_back) {
              marks[tmp.first][tmp.second + 1] = cur_mark;
              cur_queue.push(pair<int, int>(tmp.first, tmp.second + 1));
            }
          }
        }
      }
    }
  }
}

void par_marking(const int& thread_num, const int& n, const int& m,
                 int**& image, int**& marks, const int& k_unnamed) {
  const int part = n / thread_num;
  // begin of parallel section
  for (int i = 0; i < thread_num - 1; i++) {
    marking(image + part * i, part, m, marks + part * i, k_unnamed);
  }
  marking(image + part * (thread_num - 1), part + n % thread_num, m,
          marks + part * (thread_num - 1), k_unnamed);
  // end of parallel section
  // merging;
}
void create_arrays(const int& n, const int& m, int**& image, int**& marks,
                   const int& k_unnamed) {
  image = new int*[n];
  for (int i = 0; i < n; i++) {
    image[i] = new int[m];
  }
  marks = new int*[n];
  for (int i = 0; i < n; i++) {
    marks[i] = new int[m];
    for (int j = 0; j < m; j++) {
      marks[i][j] = k_unnamed;
    }
  }
}
void create_random_image(int**& image, const int& n, const int& m) {
  mt19937 engine(time(0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      image[i][j] = engine();
    }
  }
}
