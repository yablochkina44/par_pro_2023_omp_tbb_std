// Copyright 2023 Ilya Uvarkin
#pragma once
#include "Vector.h"
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

class MinConvexHullBuilder {
 public:
  std::vector<Vector> getMinConvexHull(std::vector<Vector> points);

 private:
  FRIEND_TEST(uvarkin_min_hull_convex, test2);
  FRIEND_TEST(uvarkin_min_hull_convex, test3);
  FRIEND_TEST(uvarkin_min_hull_convex, test4);
  FRIEND_TEST(uvarkin_min_hull_convex, test5);

  Vector getFirstPoint(const std::vector<Vector> &points);
  std::vector<Vector> sortPointByPolarAngle(std::vector<Vector> points, Vector firstPoint);
  std::vector<Vector> deletePointNotIncludeToMCH(const std::vector<Vector> &points);
};
