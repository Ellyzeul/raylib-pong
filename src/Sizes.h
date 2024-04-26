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
Vector3 leftScorePositionAndSize(int borderPadding, int thickness, float proportion);
Vector3 rightScorePositionAndSize(int borderPadding, int thickness, float proportion);

#endif//__ELLYZ__RL_PONG__SIZES__
