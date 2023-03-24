//a common header file consists of "standard libraries" and "common marcos".
#pragma once //a macro has the similar functionality as the #ifndef HEADER_NAME #define HEADER_NAME ...

//common libraries:
#include <iostream>
#include <easyx.h>
#include <time.h> //time control function library.
#include <stdbool.h> //boolean library.
#include <conio.h> // stands for "console input-output". it has many built-in functions that generally perform input/output on the window console.

//common marcos:
//set the width and height of bricks;
#define BRICK_W 100 
#define BRICK_H 25

//set the size of map(table) of bricks;
#define ROW 5
#define COLOMN 8

//set the size of console;
#define SCR_WIDTH 800
#define SCR_HEIGHT 800