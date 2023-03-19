// Copyright 2023 Ilya Uvarkin
#pragma once
#include "Vector.h"
#include <sstream>
#include <vector>
#include <string>

class Converter {
 public:
  std::vector<Vector> convertMatrixToSTDVector(std::vector<std::vector<int>> matrix, int width, int height);
  std::vector<std::vector<int>> convertSTDVectorToMatrix(const std::vector<Vector> &vector, int width, int height);
  std::string convertVectorToString(const std::vector<Vector> &vector);
};
