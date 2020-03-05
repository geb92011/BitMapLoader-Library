#pragma once
#include "Dependencies.h"
class Menus
{
public:
	bool creatPushButton(int, int, int, int, int, LPCWSTR);
	bool creatMenu(button[MAXBUTTONS], int);
	bool clearMenu();
	Menus(HWND, HINSTANCE);
	Menus();
private:
	HWND hWindow;
	HINSTANCE hInstance;

	// Button stuff
	int ButtonPos;
	HWND hButtons[MAXBUTTONS];
};

