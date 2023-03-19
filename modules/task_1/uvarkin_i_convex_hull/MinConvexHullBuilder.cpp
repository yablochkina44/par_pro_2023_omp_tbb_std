// Copyright 2023 Ilya Uvarkin
#include "MinConvexHullBuilder.h"

std::vector<Vector> MinConvexHullBuilder::getMinConvexHull(std::vector<Vector> points) {
  auto firstPoint = getFirstPoint(points);
  auto sortPoints = sortPointByPolarAngle(points, firstPoint);
  auto hullPoint = deletePointNotIncludeToMCH(sortPoints);

  return hullPoint;
}

Vector MinConvexHullBuilder::getFirstPoint(const std::vector<Vector> &points) {
  if (points.empty()) {
    return Vector{-1, -1};
  }

  auto firstPoint = points[0];

  for (const auto &point : points) {
    if (point.x < firstPoint.x ||
        (point.x == firstPoint.x && point.y < firstPoint.y)) {
      firstPoint = point;
    }
  }

  return firstPoint;
}

std::vector<Vector> MinConvexHullBuilder::sortPointByPolarAngle(std::vector<Vector> points, Vector firstPoint) {
  std::sort(points.begin(), points.end(), [&](Vector a, Vector b) {
    return a == firstPoint || crossProduct(a - firstPoint, b - firstPoint) > 0;
  });

  return points;
}

std::vector<Vector> MinConvexHullBuilder::deletePointNotIncludeToMCH(const std::vector<Vector> &points) {
  std::vector<Vector> hull;

  for (const auto &point : points) {
    while (hull.size() >= 2) {
      Vector newVector = point - hull.back();
      Vector lastVector = hull.back() - hull[hull.size() - 2];

      if (crossProduct(newVector, lastVector) <= 0) {
        break;
      }

      hull.pop_back();
    }

    hull.push_back(point);
  }

  return hull;
}
