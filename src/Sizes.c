#include "Sizes.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RL_PONG_MIN(x, y) (x < y ? x : y)

Vector2 upperBoundaryPosition(int borderPadding) {
  return (Vector2) { borderPadding, borderPadding };
}

Vector2 upperBoundarySize(int borderPadding, int thickness) {
  return (Vector2) { GetScreenWidth() - 2 * borderPadding, thickness };
}

Vector2 lowerBoundaryPosition(int borderPadding, int thickness) {
  return (Vector2) { borderPadding, GetScreenHeight() - borderPadding - thickness };
}

Vector2 lowerBoundarySize(int borderPadding, int thickness) {
  return upperBoundarySize(borderPadding, thickness);
}

Vector4 playableAreaCoordinates(int borderPadding, int thickness) {
  Vector2 upperPos = upperBoundaryPosition(borderPadding),
          lowerPos = lowerBoundaryPosition(borderPadding, thickness),
          lowerSize = lowerBoundarySize(borderPadding, thickness);
  
  return (Vector4) { upperPos.x, upperPos.y + thickness, lowerPos.x + lowerSize.x, lowerPos.y };
}

int areaWidth(Vector4 coords) {
  return coords.z - coords.x;
}

int areaHeight(Vector4 coords) {
  return coords.w - coords.y;
}

Vector4 leftScoreCoordinates(int borderPadding, int thickness) {
  Vector4 coords = playableAreaCoordinates(borderPadding, thickness);
  int halfWidth = areaWidth(coords) / 2;

  return (Vector4) { coords.x, coords.y, coords.z - halfWidth, coords.w };
}

Vector4 rightScoreCoordinates(int borderPadding, int thickness) {
  Vector4 coords = playableAreaCoordinates(borderPadding, thickness);
  int halfWidth = areaWidth(coords) / 2;

  return (Vector4) { coords.x + halfWidth, coords.y, coords.z, coords.w };
}

void validateProportionRate(float proportion) {
  if(proportion < 0 || proportion > 1) {
    perror("Invalid proportion rate value...");
    exit(EXIT_FAILURE);
  }
}

Vector2 scorePosition(Vector4 coords, int halfWidth, int halfHeight, float proportion) {
  int drawX = round(coords.x + halfWidth - (halfWidth * proportion)) + halfWidth/4,
      drawY = round(coords.y + halfHeight - (halfHeight * proportion)) + halfHeight/8;

  return (Vector2) { drawX, drawY };
}

Vector2 leftScorePosition(int borderPadding, int thickness, float proportion) {
  validateProportionRate(proportion);

  Vector4 coords = leftScoreCoordinates(borderPadding, thickness);
  int halfWidth = areaWidth(coords) / 2,
      halfHeight = areaHeight(coords) / 2;

  return scorePosition(coords, halfWidth, halfHeight, proportion);
}

Vector2 rightScorePosition(int borderPadding, int thickness, float proportion) {
  validateProportionRate(proportion);

  Vector4 coords = rightScoreCoordinates(borderPadding, thickness);
  int halfWidth = areaWidth(coords) / 2,
      halfHeight = areaHeight(coords) / 2;

  return scorePosition(coords, halfWidth, halfHeight, proportion);
}

int scoreFontSize(int borderPadding, int thickness, float proportion) {
  validateProportionRate(proportion);

  Vector4 coords = rightScoreCoordinates(borderPadding, thickness);
  int halfWidth = areaWidth(coords) / 2,
      halfHeight = areaHeight(coords) / 2;

  return round(RL_PONG_MIN(halfWidth, halfHeight) * 2 * proportion);
}

Vector2 player1Position(int borderPadding, int thickness, float positionProportion, float sizeProportion) {
  Vector4 coords = playableAreaCoordinates(borderPadding, thickness);
  int height = areaHeight(coords);

  return (Vector2) { coords.x, coords.y + (height * (1 - sizeProportion) * positionProportion) };
}

Vector2 player2Position(int borderPadding, int borderThickness, float positionProportion, float sizeProportion, int playerThickness) {
  Vector4 coords = playableAreaCoordinates(borderPadding, borderThickness);
  int height = areaHeight(coords),
      width = areaWidth(coords);

  return (Vector2) { coords.x + width - playerThickness, coords.y + (height * (1 - sizeProportion) * positionProportion) };
}

Vector2 playerSize(int borderPadding, int borderThickness, float sizeProportion, int playerThickness) {
  Vector4 coords = playableAreaCoordinates(borderPadding, borderThickness);
  int height = areaHeight(coords);

  return (Vector2) { playerThickness, height * sizeProportion };
}
