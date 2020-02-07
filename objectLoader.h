#pragma once
#include "Dependencies.h"
class objectLoader
{
public:
	bool bitMapLoader();
	bool bitMapRender(int, int);
	bool bitMapMove(int, int);

	objectLoader(LPCWSTR, HDC);

private:
	LPCWSTR FileName;
	BITMAP qBitmap;
	HDC hLocalDC;

	HDC winDC;

};

