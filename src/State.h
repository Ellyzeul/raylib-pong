#ifndef __ELLYZ__RL_PONG__STATE__
#define __ELLYZ__RL_PONG__STATE__

#include <raylib.h>

typedef struct {
  float positionProportion;
  float sizeProportion;
  float velocity;
  int upButton;
  int downButton;
  short movementDirection;
  int dashButton;
  short dashing;
  float dashCooldown;
} Player;

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

  Player player1;
  Player player2;
  int playerThickness;
  float playerDashVelocity;
  float playerDashCooldown;
  float playerDashDuration;
} State;

State stateInit(void);

#endif//__ELLYZ__RL_PONG__STATE__
