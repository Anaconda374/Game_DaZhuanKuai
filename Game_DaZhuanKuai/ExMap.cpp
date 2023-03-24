#include "ExMap.h"

void initMap(Exmap* pMap)
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


void drawMap(Exmap Map)
{

}
