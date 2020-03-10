#pragma once

#include <Windows.h>


#define MAXBUTTONS			100

//utility things
//Menu generation
struct button
{
	int xPos;
	int yPos;
	int xSize;
	int ySize;
	int ID;
	LPCWSTR name;
};
