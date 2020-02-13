#pragma once
#include "objectLoader.h"
#include <vector>
class bitScreen
{
public:
	bitScreen(HDC);

	/**
	This adds a bmp to the scene 
	@param LPCWSTR the name of the .bmp
	@param int,int the initial x,y cordinates of the .bmp 
	*/
	bool addObject(int, LPCWSTR, int, int);

	/**
	This changes the position of a .bmp in the current scene
	@param LPCWSTR the name of the .bmp
	@param int,int the new x,y cordinates of the .bmp
	@param First int is the "ID" of the bmp in the scene
		The function will use which ever finding strategy is NOT NULL
	*/
	bool changePosition(int, LPCWSTR, int, int);

	// Refreshes the screen for this scene
	void refreshScreen();

private:
	// The DC of the parent window
	HDC hWinDC;
	// A vector of all the objects
	std::vector<objectLoader> bmps;

	// THe current position in the bmp "array"
	int pos;
};

