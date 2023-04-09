// Copyright 2023 Kosterin Alexey
#ifndef MODULES_TASK_1_KOSTERIN_A_JARVIS_JARVIS_H_
#define MODULES_TASK_1_KOSTERIN_A_JARVIS_JARVIS_H_

#include <vector>

struct SPoint;
struct SVector;
int Cross(SVector a, SVector b);
std::vector<SPoint> CreateArray(int size);
void Swap(SPoint &arr1, SPoint &arr2);
std::vector<SPoint> DoJarvis(std::vector<SPoint> arr, int size);
bool ChekJarvis(std::vector<SPoint> jarArr);

#endif  // MODULES_TASK_1_KOSTERIN_A_JARVIS_JARVIS_H_
