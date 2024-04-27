#include "Boundaries.h"
#include "Sizes.h"
#include "Constants.h"
#include "State.h"
#include <raylib.h>
#include <stdio.h>

void drawBoundaries(State state) {
  DrawRectangleV(state.upperBoundaryPosition, state.upperBoundarySize, state.boundaryColor);
  DrawRectangleV(state.lowerBoundaryPosition, state.lowerBoundarySize, state.boundaryColor);
}

State updateBoundariesSize(State state) {
  state.upperBoundaryPosition = upperBoundaryPosition(state.boundaryPadding);
  state.upperBoundarySize = upperBoundarySize(state.boundaryPadding, state.boundaryThickness);
  state.lowerBoundaryPosition = lowerBoundaryPosition(state.boundaryPadding, state.boundaryThickness);
  state.lowerBoundarySize = lowerBoundarySize(state.boundaryPadding, state.boundaryThickness);

  return state;
}

State updateBoundaryPadding(State state) {
  if(state.boundaryGrowing) {
    if(state.boundaryPadding >= 99) state.boundaryGrowing = 0;

    state.boundaryPadding += state.boundaryIncreaseRate;
    return state;
  }

  if(state.boundaryPadding <= 21) state.boundaryGrowing = 1;

  state.boundaryPadding -= state.boundaryIncreaseRate;
  return state;
}
