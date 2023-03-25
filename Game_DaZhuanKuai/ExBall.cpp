#include "ExBall.h"

void initBall(ExBall* pBall)
{
	//initialize the ball at the center of the screen.
	pBall->x = SCR_WIDTH/2;
	pBall->y = SCR_HEIGHT/2;
	pBall->radius = 10;

	//make the ball moves to the top-left direction at the beginning of game.
	pBall->dx = 5;
	pBall->dy = -5;
	pBall->color = LIGHTGRAY;

}

void drawBall(ExBall Ball)
{
	setfillcolor(Ball.color);
	fillcircle(Ball.x, Ball.y, Ball.radius);
}
