#ifndef __ELLYZ__RL_PONG__SIZES__
#define __ELLYZ__RL_PONG__SIZES__

#include <raylib.h>

Vector2 upperBoundaryPosition(int borderPadding);
Vector2 upperBoundarySize(int borderPadding, int thickness);
Vector2 lowerBoundaryPosition(int borderPadding, int thickness);
Vector2 lowerBoundarySize(int borderPadding, int thickness);
Vector4 playableAreaCoordinates(int borderPadding, int thickness);
int playableAreaWidth(int borderPadding, int thickness);
int playableAreaHeight(int borderPadding, int thickness);
Vector2 leftScorePosition(int borderPadding, int thickness, float proportion);
Vector2 rightScorePosition(int borderPadding, int thickness, float proportion);
int scoreFontSize(int borderPadding, int thickness, float proportion);
Vector2 player1Position(int borderPadding, int thickness, float positionProportion, float sizeProportion);
Vector2 player2Position(int borderPadding, int borderThickness, float positionProportion, float sizeProportion, int playerThickness);
Vector2 playerSize(int borderPadding, int borderThickness, float sizeProportion, int playerThickness);

#endif//__ELLYZ__RL_PONG__SIZES__
