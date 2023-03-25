#include "ExBoard.h"


//set the coordinates and attributes of the initial board.
void initBoard(ExBoard* pBoard)
{
 //define a board has "width = 2 * brick_width", "height = brick_height".
	pBoard->x = SCR_WIDTH / 2 - BRICK_W;
	pBoard->y = SCR_HEIGHT - BRICK_H;
	pBoard->width = BRICK_W * 2;
	pBoard->height = BRICK_H;
	pBoard->speed = 1; //the board moves 1 pixel per click.
	pBoard->color = WHITE;
}

//construct(or draw) the board according to its attributes.
void drawBoard(ExBoard Board)
{
	setfillcolor(Board.color);
	fillrectangle(Board.x, Board.y, Board.x + Board.width, Board.y + Board.height);
}

