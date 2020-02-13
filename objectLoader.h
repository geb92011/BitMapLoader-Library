#pragma once
#include "Dependencies.h"
class objectLoader
{
public:
	bool bitMapLoader(int, int);
	bool bitMapRender();
	bool bitMapMove(int, int);

	objectLoader(LPCWSTR, HDC);
	// Int must not be 0 or NULL
	objectLoader(LPCWSTR, HDC, int);

	int getID();
	LPCWSTR getFile();

private:
	LPCWSTR FileName;
	BITMAP qBitmap;
	HDC hLocalDC;

	HDC winDC;
	int ID;

	int xCord;
	int yCord;
};

