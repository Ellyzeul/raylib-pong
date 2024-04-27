#include "State.h"
#include "Constants.h"
#include <raylib.h>

State stateInit(void) {
  State state;

  state.boundaryPadding = BOUNDARY_PADDING;
  state.boundaryThickness = BOUNDARY_THICKNESS;
  state.boundaryGrowing = 1;
  state.boundaryIncreaseRate = BOUNDARY_INCREATE_RATE;
  state.boundaryColor = BOUNDARY_COLOR;

  state.score = (Vector2) { 0, 0 };
  state.scoreColor = SCORE_COLOR;
  state.scoreSizeProportion = SCORE_SIZE_PROPORTION;

  return state;
}
