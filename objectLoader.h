#pragma once
#include "Dependencies.h"
class objectLoader
{
public:
	bool bitMapLoader(int, int);
	bool bitMapRender();
	bool bitMapMove(int, int);

	objectLoader(LPCWSTR, HWND);
	// Int must not be 0 or NULL
	objectLoader(LPCWSTR, HWND, int);

	// Default constructor
	objectLoader();

	int getID();
	LPCWSTR getFile();

private:
	LPCWSTR FileName;
	BITMAP qBitmap;
	HDC hLocalDC;

	HWND hWnd;
	int ID;

	int xCord;
	int yCord;
};

