#include "ExMap.h"

void initMap(ExMap* pMap)
{
//make each brick with a random color of 3 different colors by using fucntions 'rand(int num)' to initialize the 2-dimensional array with random numbers.
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COLOMN; ++j) {
			pMap->twoDimArr[i][j] = rand() % 3 + 1;
		}
	}
}
//'rand()' returns a pseudo-random integral number in the range between 0 and RAND_MAX(library-dependent,at least 32767 ).
//'rand() % 3' returns a random number among 0~2, 'rand() % 3 +1 returns a random number among 1~3.


void drawMap(ExMap Map)
{
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COLOMN; ++j) {

			int x = j * BRICK_W; //x-coordinate = #colomn * brick_width
			int y = i * BRICK_H; //y-coordinate = #row * brick_height
			switch (Map.twoDimArr[i][j]) {
			case 1: 
				setfillcolor(RED);
				fillrectangle(x, y, x + BRICK_W, y + BRICK_H);
				break;
			case 2:
				setfillcolor(GREEN);
				fillrectangle(x, y, x + BRICK_W, y + BRICK_H);
				break;
			case 3:
				setfillcolor(BLUE);
				fillrectangle(x, y, x + BRICK_W, y + BRICK_H);
				break;
			
			//'if twoDimArr[i][j] = 0' , then not draw the brick,  for the brick is eliminated.
			case 0:
				break;
			}

		
		}
	}
}
