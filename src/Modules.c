#include "Modules.h"
#include "State.h"
#include "Boundaries.h"
#include "Score.h"
#include "Players.h"

State update(State state) {
  state = updateBoundariesSize(state);
  state = updateScoreSize(state);
  state = updatePlayers(state);
  state = updateBoundaryPadding(state);

  return state;
}

void draw(State state) {
  drawBoundaries(state);
  drawScore(state);
  drawPlayers(state);
}
