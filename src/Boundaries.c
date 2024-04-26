#include "Boundaries.h"
#include "Sizes.h"
#include "Constants.h"
#include <raylib.h>
#include <stdio.h>

void setBoundaries(int borderPadding) {
  Vector2 upperPos = upperBoundaryPosition(borderPadding),
          upperSize = upperBoundarySize(borderPadding, BOUNDARY_THICKNESS),
          lowerPos = lowerBoundaryPosition(borderPadding, BOUNDARY_THICKNESS),
          lowerSize = lowerBoundarySize(borderPadding, BOUNDARY_THICKNESS);

  DrawRectangleV(upperPos, upperSize, BOUNDARY_COLOR);
  DrawRectangleV(lowerPos, lowerSize, BOUNDARY_COLOR);
}
