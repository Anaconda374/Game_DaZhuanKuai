
//encapsulate all modules and gaming functions in a game class(or structure), such that the main function can look more succinct.

#pragma once
#include "ExCommon.h"
#include "ExMap.h"
#include "ExBoard.h"
#include "ExBall.h"
#include "ExTimer.h"

class ExGame {
public:
	ExMap map;
	ExBoard board;
	ExBall ball;
};

//the ide 'Visual Studio' will automatically link the external definitions with these function declarations. 
void initGame(ExGame* pGame);

void loopGame(ExGame Game);

