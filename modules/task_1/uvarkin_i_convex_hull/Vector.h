// Copyright 2023 Ilya Uvarkin
#pragma once
#include <ostream>

class Vector {
 public:
  int x, y;

  explicit Vector(int _x = 0, int _y = 0);
  Vector operator+(Vector const &vector) const;
  Vector operator-(Vector const &vector) const;

  friend std::ostream &operator<<(std::ostream &out, const Vector &vector);
  friend bool operator==(const Vector &vector1, const Vector &vector2);
};

int crossProduct(const Vector &a, const Vector &b);
