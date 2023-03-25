#pragma once

#include "ExCommon.h"

class ExBoard {
public:
	int x;
	int y;
	int width;
	int height;
	int speed;
	COLORREF color;
};


void initBoard(class ExBoard* pBoard);

void drawBoard(class ExBoard Board);