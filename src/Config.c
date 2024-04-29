#include "Config.h"
#include "Constants.h"
#include <raylib.h>

void configGame(void) {
  Image icon = LoadImage("icon.png");
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(START_WIDTH, START_HEIGHT, GAME_NAME);
  SetTargetFPS(60);
  SetWindowIcon(icon);
}
