#include "Score.h"
#include "Sizes.h"
#include "Constants.h"
#include <raylib.h>

void drawScore(Vector2 score, int borderPadding) {
  Vector3 left = leftScorePositionAndSize(borderPadding, BOUNDARY_THICKNESS, SCORE_SIZE_PROPORTION),
          right = rightScorePositionAndSize(borderPadding, BOUNDARY_THICKNESS, SCORE_SIZE_PROPORTION);

  DrawText(TextFormat("%d", (int) score.x), left.x, left.y, left.z, SCORE_COLOR);
  DrawText(TextFormat("%d", (int) score.y), right.x, right.y, right.z, SCORE_COLOR);
}
