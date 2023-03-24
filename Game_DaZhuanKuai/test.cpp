

/*
Modular Development--To build this project in sevaral modules. 
1.map(table) of bricks;
2.bricks;
3.ball;
4.interact functions.
*/


/*
Graphical functions are used in this project:
1.void rectangle(int left, int top, int right, int bottom);
2.void circle(int x, int y, int radius);


3.setfillcolor(RGB(int r, int g, int b)); or setfillcolor(char[] green);
setlinecolor(RGB(int r, int g, int b)); or setlinecolor(char[] green);
4.void fillrectangle(int left, int top, int right, int bottom);
5.void solidrectangle(int left, int top, int right, int bottom);
6.void fillcircle(int x, int y, int radius);
7.void solidcircle(int x, int y, int radius);


Upload image steps:
1.create a IMAGE(class defined in easyx.h) object: IMAGE img1;
2.load image from the actual path: loadimage(&img1, "img_path(url)");
3.print image: putimage(int x_co, int y_co, &img1);

*/
#include "ExCommon.h"


int main(){

	//create a screen
	initgraph(SCR_WIDTH, SCR_HEIGHT);
	IMAGE background;
	loadimage(&background, "./background.jpg", SCR_WIDTH, SCR_HEIGHT);//load image in given size.
	
	putimage(0, 0, &background); 

	//use fucntions 'srand(int num)' and 'time(NULL)' to initialize the 2-dimensional array with random numbers.

	setfillcolor(RGB(110, 11, 113));
	solidcircle(100, 100, 20);


	getchar();

	closegraph();
	return 0;
}