
#include <iostream>
#include <easyx.h>

/*
Graphical functions are used in this project:
1.void rectangle(int left, int top, int right, int bottom);
2.void circle(int x, int y, int radius);

3.setfillcolor(RGB(int r, int g, int b)); or setfillcolor(char[] green);
4.void fillrectangle(int left, int top, int right, int bottom);
5.void solidrectangle(int left, int top, int right, int bottom);
6.void fillcircle(int x, int y, int radius);
7.void solidcircle(int x, int y, int radius);

*/


int main(){

	initgraph(800, 600);
	setfillcolor(RGB(110, 11, 113));
	solidcircle(100, 100, 20);


	getchar();

	closegraph();
	return 0;
}