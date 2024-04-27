#include "Modules.h"
#include "State.h"
#include "Boundaries.h"
#include "Score.h"
#include "Goalkeepers.h"

State update(State state) {
  state = updateBoundariesSize(state);
  state = updateScoreSize(state);

  state = updateBoundaryPadding(state);

  return state;
}

void draw(State state) {
  drawBoundaries(state);
  drawScore(state);
}
