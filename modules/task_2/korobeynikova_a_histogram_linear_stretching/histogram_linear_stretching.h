// Copyright 2023 Korobeynikova Alice
#pragma once
#include <vector>

typedef unsigned char Color;
typedef std::vector<Color> Image;

void sequentialLinearHistogramStretching(Image im);
void parallelLinearHistogramStretching(Image im);
