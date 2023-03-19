// Copyright 2023 Ilya Uvarkin
#include "Converter.h"
#include <string>

std::vector<Vector> Converter::convertMatrixToSTDVector(std::vector<std::vector<int>> matrix,
                                                        int width, int height) {
  std::vector<Vector> res;

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      auto elem = matrix[i][j];

      if (elem != 0) {
        res.emplace_back(j, height - 1 - i);
      }
    }
  }

  return res;
}

std::vector<std::vector<int>> Converter::convertSTDVectorToMatrix(const std::vector<Vector> &vector,
                                                                  int width, int height) {
  std::vector<std::vector<int>> res;

  res.resize(height);
  for (auto &item : res) {
    item.resize(width);
  }

  for (const auto &item : vector) {
    res[item.y][item.x] = 1;
  }
  return res;
}

std::string Converter::convertVectorToString(const std::vector<Vector> &vectors) {
  std::stringstream ss;
  for (auto it = vectors.begin(); it != vectors.end(); it++) {
    if (it != vectors.begin() && it != vectors.end()) {
      ss << ", ";
    }
    ss << *it;
  }

  return ss.str();
}
