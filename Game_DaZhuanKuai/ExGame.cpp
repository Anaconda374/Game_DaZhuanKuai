#include "ExGame.h"
//define a function as 'static', so that only the statement inside this file can call it.


//define the board movement function:
static void keyClick(ExGame* Game) {
	//when click 'a' or 'Left' keys, moves the board to the left until the board reach the left border of the screen.
	if ((GetAsyncKeyState('a') || GetAsyncKeyState(VK_LEFT)) && Game->board.x > 0) {
		Game->board.x = Game->board.x - Game->board.speed;
	
	}
	//when click 'd' or 'right' keys, moves the board to the right until the board reach the border bar of the screen.
	if ((GetAsyncKeyState('d') || GetAsyncKeyState(VK_RIGHT)) 
					&& Game->board.x + Game->board.width < SCR_WIDTH) {
		
		Game->board.x = Game->board.x + Game->board.speed;
	}
}

//define the ball movement function when it hits the bricks:
static int hitBrick(ExGame* pGame) {
	//find #ROW and #COLOMN of the brick that hitted by the ball using the coordinates of ball.
	//NOTE: first dimension index is derived by the height. 
	int i = (pGame->ball.y - pGame->ball.radius) / BRICK_H;
	int j = pGame->ball.x / BRICK_W;
	
	//if the ball hits the brick, eliminate that brick and return 'true'(for reflection).
	if ( (i < ROW) && (j< COLOMN) && (pGame->map.twoDimArr[i][j] != 0)) {
		pGame->map.twoDimArr[i][j] = 0;
		return 1;
	}
	return 0;
}


//define the ball movement function when it hits the board:
static int hitBoard(ExGame* pGame) {
	//if the ball hits the board, return 'true'.
	if (pGame->ball.y + pGame->ball.radius == pGame->board.y) {
		if ((pGame->ball.x >= pGame->board.x) && (pGame->ball.x <= pGame->board.x + pGame->board.width))
			
			return 1;
	}
	return 0;
}



//define the ball movement function when it hits the screen borders:
static void moveBall(ExGame* pGame) {
//according to the physical reflection, if ball reaches the left or right border,the movement of the ball changes in horizontal direction .
	if (pGame->ball.x - pGame->ball.radius <= 0 || pGame->ball.x + pGame->ball.radius >= SCR_WIDTH) {
		pGame->ball.dx = -pGame->ball.dx;
	}
	//if ball hits 'up_border' or 'board' or 'brick', the movement of the ball changes in vertical direction .
	if (pGame->ball.y - pGame->ball.radius <= 0 || hitBoard(pGame) || hitBrick(pGame)) {
		pGame->ball.dy = -pGame->ball.dy;
	}
	 
	pGame->ball.x += pGame->ball.dx;
	pGame->ball.y += pGame->ball.dy;
}


static int GameOver(ExGame Game){
	if (Game.ball.y - Game.ball.radius >= SCR_HEIGHT) {
		return 1;
	}
	return 0;
}

static int GameWin(ExGame Game) {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COLOMN; ++j) {
			if (Game.map.twoDimArr[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

void initGame(ExGame* pGame)
{
	initMap(&pGame->map);
	initBoard(&pGame->board);
	initBall(&pGame->ball);
}

void loopGame(ExGame Game)
{
	//create the ambient screen
	HWND hwnd = initgraph(SCR_WIDTH, SCR_HEIGHT);
	IMAGE background;
	loadimage(&background, "./background.jpg", SCR_WIDTH, SCR_HEIGHT);//load image in given size.

	BeginBatchDraw();
//the whole game environment is maintained in a 'while(1)' loop.
	while (1) {
		putimage(0, 0, &background);
		drawMap(Game.map);
		keyClick(&Game);//before drawing the board, call 'keyClick()' to refresh the board coordinates.
		drawBoard(Game.board);
		drawBall(Game.ball);
		
		//check if win the game:
		if (GameWin(Game)) {
			MessageBox(hwnd, "you win the game", "CONGRATULATIONS", MB_OK);
			break;
		}
		//ball moves once(with 'dx', 'dy') per 20 milliseconds.
		if (timer(20,0)) {
			moveBall(&Game);
		}

		//check if lose the game:
		if (GameOver(Game)) {
			MessageBox(hwnd, "you lose the game", "GAMEOVER", MB_OK);
			break;
		}
		FlushBatchDraw();
	}
	closegraph();
}
		