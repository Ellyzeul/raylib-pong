#include "State.h"
#include "Constants.h"
#include <raylib.h>

float playerPositionProportion(float sizeProportion) {
  return (1 - sizeProportion) / 2;
}

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

  state.player1.sizeProportion = PLAYER_SIZE_PROPORTION;
  state.player1.positionProportion = playerPositionProportion(state.player1.sizeProportion);
  state.player1.velocity = PLAYER_VELOCITY;
  state.player1.upButton = KEY_W;
  state.player1.downButton = KEY_S;
  state.player1.movementDirection = 0;
  state.player1.dashButton = KEY_SPACE;
  state.player1.dashing = 0;
  state.player1.dashCooldown = 0.0f;

  state.player2.sizeProportion = PLAYER_SIZE_PROPORTION;
  state.player2.positionProportion = playerPositionProportion(state.player2.sizeProportion);
  state.player2.velocity = PLAYER_VELOCITY;
  state.player2.upButton = KEY_UP;
  state.player2.downButton = KEY_DOWN;
  state.player2.movementDirection = 0;
  state.player2.dashButton = KEY_ENTER;
  state.player2.dashing = 0;
  state.player2.dashCooldown = 0.0f;

  state.playerThickness = PLAYER_THICKNESS;
  state.playerDashVelocity = PLAYER_DASH_VELOCITY;
  state.playerDashCooldown = PLAYER_DASH_COOLDOWN;
  state.playerDashDuration = PLAYER_DASH_DURATION;

  return state;
}
