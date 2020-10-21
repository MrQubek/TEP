#pragma once

#include "const.h"

#include <cstdlib>
#include <iostream>

void allocTableAdd5(int tabSize);

bool allocTable2Dim(int**& tab, int xDim, int yDim);

bool deallocTable2Dim(int**& tab, int xDim, int yDim);