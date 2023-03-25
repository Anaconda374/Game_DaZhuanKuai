#pragma once

#include "ExCommon.h"
class ExBall{
public:
	int x;
	int y;
	int radius;

	//the infinitesimal change of the coordinates of the ball when it's moving.
	int dx;
	int dy;
	COLORREF color;
};

void initBall(class ExBall* pBall);

void drawBall(class ExBall Ball);