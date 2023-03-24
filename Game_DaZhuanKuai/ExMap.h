#pragma once

#include "ExCommon.h"

//use a two dimensional array to implement the map(or table) of bricks.  
class ExMap {
public:
	int twoDimArr[ROW][COLOMN];
};

//declare the map functions:
//initial map;
void initMap(struct Exmap* pMap);

//constuct the map of bricks
void drawMap(struct Exmap Map);