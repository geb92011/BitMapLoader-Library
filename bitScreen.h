#pragma once
#include "objectLoader.h"
#include <vector>
class bitScreen
{
public:
	bitScreen();
	// File is background file name or directory
	bitScreen(HWND, LPCWSTR);

	// Changes the background of the scene
	void changeBackGround(LPCWSTR);

	/**
	This adds a bmp to the scene 
	@param LPCWSTR the name of the .bmp
	@param int,int the initial x,y cordinates of the .bmp 
	*/
	bool addObject(int, LPCWSTR, int, int);

	/*
	Removes an object from the scene
	@param int this is the ID, if this is NULL it will use the file name to remove the object
	@param the LPCWSTR this is the file name if it is left NULL it will default to the ID
	*/
	bool removeObject(int, LPCWSTR);

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

	// Gets if the screen has been changes since the last refresh
	bool getChanged();

private:
	// The DC of the parent window
	HWND hWnd;
	// A vector of all the objects
	std::vector<objectLoader> bmps;
	
	// Background
	objectLoader backGround;

	// THe current position in the bmp "array"
	int pos;


	// Holds the changed variable
	bool changed;
};

