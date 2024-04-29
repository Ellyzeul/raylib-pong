#include "Players.h"
#include "State.h"
#include "Sizes.h"
#include <raylib.h>

void drawPlayers(const State state) {
  Vector2 p1Pos = player1Position(state.boundaryPadding, state.boundaryThickness, state.player1.positionProportion, state.player1.sizeProportion),
          p1Size = playerSize(state.boundaryPadding, state.boundaryThickness, state.player1.sizeProportion, state.playerThickness),
          p2Pos = player2Position(state.boundaryPadding, state.boundaryThickness, state.player2.positionProportion, state.player2.sizeProportion, state.playerThickness),
          p2Size = playerSize(state.boundaryPadding, state.boundaryThickness, state.player2.sizeProportion, state.playerThickness);
  
  DrawRectangleV(p1Pos, p1Size, state.boundaryColor);
  DrawRectangleV(p2Pos, p2Size, state.boundaryColor);
}

Player updatePlayerDashing(Player player, int pressed, float dashDuration, float cooldown) {
  if(player.dashing = 1) {
    player.dashing = cooldown - player.dashCooldown >= dashDuration ? 0 : player.dashing;
  }
  if(pressed == player.dashButton && !player.dashCooldown && player.movementDirection != 0) {
    player.dashing = 1;
  }

  return player;
}

State updatePlayersDashing(State state, int pressed) {
  state.player1 = updatePlayerDashing(state.player1, pressed, state.playerDashDuration, state.playerDashCooldown);
  state.player2 = updatePlayerDashing(state.player2, pressed, state.playerDashDuration, state.playerDashCooldown);

  return state;
}

Player updatePlayerDashCooldown(Player player, float cooldown) {
  if(player.dashCooldown > 0.0f) {
    player.dashCooldown -= GetFrameTime();
    player.dashCooldown = player.dashCooldown < 0.0f ? 0.0f : player.dashCooldown;
  }

  if(player.dashing && player.dashCooldown == 0.0f) player.dashCooldown = cooldown;

  return player;
}

State updatePlayersDashCooldown(State state) {
  state.player1 = updatePlayerDashCooldown(state.player1, state.playerDashCooldown);
  state.player2 = updatePlayerDashCooldown(state.player2, state.playerDashCooldown);

  return state;
}

Player updatePlayerMovementDirection(Player player, const int pressed) {
  if(pressed == player.upButton) {
    player.movementDirection = -1;
    player.dashing = 0;
  }
  else if(pressed == player.downButton) {
    player.movementDirection = 1;
    player.dashing = 0;
  }
  else if(IsKeyReleased(player.upButton)) {
    player.movementDirection = IsKeyDown(player.downButton) ? 1 : 0;
    player.dashing = 0;
  }
  else if(IsKeyReleased(player.downButton)) {
    player.movementDirection = IsKeyDown(player.upButton) ? -1 : 0;
    player.dashing = 0;
  }
  else if(IsKeyUp(player.upButton) && IsKeyUp(player.downButton)) {
    player.movementDirection = 0;
  }

  return player;
}

State updatePlayersMovementDirection(State state, const int pressed) {
  state.player1 = updatePlayerMovementDirection(state.player1, pressed);
  state.player2 = updatePlayerMovementDirection(state.player2, pressed);

  return state;
}

Player updatePlayerPositionProportion(Player player, float dashVelocity) {
  player.positionProportion += player.movementDirection * (player.velocity + player.dashing * dashVelocity);

  player.positionProportion = player.positionProportion < 0.0f ? 0.0f : player.positionProportion;
  player.positionProportion = player.positionProportion > 1.0f ? 1.0f : player.positionProportion;

  return player;
}

State updatePlayersPositionProportion(State state, const int pressed) {
  state.player1 = updatePlayerPositionProportion(state.player1, state.playerDashVelocity);
  state.player2 = updatePlayerPositionProportion(state.player2, state.playerDashVelocity);
  
  return state;
}

State updatePlayers(State state) {
  int pressed = GetKeyPressed();

  state = updatePlayersDashCooldown(state);

  do {
    state = updatePlayersMovementDirection(state, pressed);
    state = updatePlayersDashing(state, pressed);

    pressed = GetKeyPressed();
  } while(pressed != 0);

  state = updatePlayersPositionProportion(state, pressed);

  return state;
}
