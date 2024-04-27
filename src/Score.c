#include "Score.h"
#include "Sizes.h"
#include "Constants.h"
#include "State.h"
#include <raylib.h>
#include <stdio.h>

void drawScoreSide(int points, Vector2 pos, int fontSize, Color color) {
  DrawText(TextFormat("%d", points), pos.x, pos.y, fontSize, color);
}

void drawScore(State state) {
  drawScoreSide((int) state.score.x, state.leftScorePosition, state.scoreFontSize, state.scoreColor);
  drawScoreSide((int) state.score.y, state.rightScorePosition, state.scoreFontSize, state.scoreColor);
}

State updateScoreSize(State state) {
  state.leftScorePosition = leftScorePosition(state.boundaryPadding, state.boundaryThickness, state.scoreSizeProportion);
  state.rightScorePosition = rightScorePosition(state.boundaryPadding, state.boundaryThickness, state.scoreSizeProportion);
  state.scoreFontSize = scoreFontSize(state.boundaryPadding, state.boundaryThickness, state.scoreSizeProportion);

  return state;
}
