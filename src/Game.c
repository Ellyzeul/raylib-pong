#include "Game.h"
#include "Boundaries.h"
#include "Constants.h"
#include "Sizes.h"
#include "Score.h"
#include "Config.h"
#include <raylib.h>

int updatePadding(const int padding, int *growing, const int increaseRate) {
  if(*growing) {
    if(padding >= 99) *growing = 0;
    return padding + increaseRate;
  }

  if(padding <= 21) *growing = 1;
  return padding - increaseRate;
}

void startGame(void) {
  int padding = 20, growing = 1;
  Vector2 score = (Vector2) { 0, 0 };

  configGame();

  while(!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);
    setBoundaries(padding);
    padding = updatePadding(padding, &growing, 1);
    drawScore(score, padding);

    EndDrawing();
  }

  CloseWindow();
}
