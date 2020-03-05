#include "pch.h"
#include "Menus.h"

Menus::Menus()
{

}


Menus::Menus(HWND hwnd, HINSTANCE hInst)
{
	hWindow = hwnd;
	hInstance = hInst;


	ButtonPos = 0;
}

bool Menus::creatPushButton(int xPos, int yPos, int xSize, int ySize, int ID, LPCWSTR text)
{
	hButtons[ButtonPos] = CreateWindow(
		TEXT("button"),             // The class name required is button
		text,                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		xPos, yPos,                                  // the left and top co-ordinates
		xSize, ySize,                              // width and height
		hWindow,                                 // parent window handle
		(HMENU)ID,					// the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	if (hButtons[ButtonPos] == NULL)
	{
		MessageBox(NULL, L"Button failed",
			L"Error", MB_OK);
		return false;
	}

	ButtonPos++;

	return true;
}


// Creats menu with many buttons
bool Menus::creatMenu(button Buttons[MAXBUTTONS], int buttons)
{
	for (int i = 0; i < buttons; i++)
	{
		hButtons[ButtonPos] = CreateWindow(
			TEXT("button"),             // The class name required is button
			Buttons[i].name,                  // the caption of the button
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
			Buttons[i].xPos, Buttons[i].yPos,                                  // the left and top co-ordinates
			Buttons[i].xSize, Buttons[i].ySize,                              // width and height
			hWindow,                                 // parent window handle
			(HMENU)Buttons[i].ID,					// the ID of your button
			hInstance,                            // the instance of your application
			NULL);

		if (hButtons[ButtonPos] == NULL)
		{
			MessageBox(NULL, L"Button failed",
				L"Error", MB_OK);
			return false;
		}

		ButtonPos++;
	}

	return true;
}

bool Menus::clearMenu()
{
	for (int i = 0; i < ButtonPos; i++)
	{
		DestroyWindow(hButtons[i]);
	}
	return true;
}
