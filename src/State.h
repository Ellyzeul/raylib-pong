#ifndef __ELLYZ__RL_PONG__STATE__
#define __ELLYZ__RL_PONG__STATE__

#include <raylib.h>

typedef struct {
  int boundaryPadding;
  int boundaryThickness;
  short boundaryGrowing;
  int boundaryIncreaseRate;
  Color boundaryColor;
  Vector2 upperBoundaryPosition;
  Vector2 upperBoundarySize;
  Vector2 lowerBoundaryPosition;
  Vector2 lowerBoundarySize;

  Vector2 score;
  Color scoreColor;
  float scoreSizeProportion;
  int scoreFontSize;
  Vector2 leftScorePosition;
  Vector2 rightScorePosition;
} State;

State stateInit(void);

#endif//__ELLYZ__RL_PONG__STATE__
