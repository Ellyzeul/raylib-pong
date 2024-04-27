#include "Game.h"
#include "Constants.h"
#include "Config.h"
#include "State.h"
#include "Modules.h"
#include <raylib.h>

void startGame(void) {
  State state = stateInit();

  configGame();

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BACKGROUND_COLOR);

    state = update(state);
    draw(state);

    EndDrawing();
  }

  CloseWindow();
}
