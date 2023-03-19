// Copyright 2023 Ilya Uvarkin
#include "Vector.h"

Vector::Vector(int _x, int _y) {
  x = _x;
  y = _y;
}

int crossProduct(Vector const &a, Vector const &b) {
  return a.x * b.y - b.x * a.y;
}

Vector Vector::operator+(const Vector &vector) const {
  return Vector(x + vector.x, y + vector.y);
}

Vector Vector::operator-(const Vector &vector) const {
  return Vector(x - vector.x, y - vector.y);
}

std::ostream &operator<<(std::ostream &out, const Vector &vector) {
  out << "(" << vector.x << ", " << vector.y << ")";

  return out;
}

bool operator==(const Vector &vector1, const Vector &vector2) {
  return vector1.x == vector2.x && vector1.y == vector2.y;
}
