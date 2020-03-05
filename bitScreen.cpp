#include "pch.h"
#include "bitScreen.h"

bitScreen::bitScreen()
{

}


objectLoader newObject(HWND tWnd)
{
	return objectLoader(L"C:/Users/geb92/source/repos/Library tester/DEFAULTBACKGROUND.bmp", tWnd);
}
bitScreen::bitScreen(HWND hWnd, LPCWSTR background)
{
	if (background == NULL)
	{
		backGround = newObject(hWnd);
	}
	else
	{
		// Specified background
		objectLoader backGround(background,hWnd); // = newObject(hWnd, background);
	}
	backGround.bitMapLoader(0, 0);

	this->hWnd = hWnd;
	pos = 0;

	changed = true;
}

// Changes the background of the scene
void bitScreen::changeBackGround(LPCWSTR)
{

}


/**
This adds a bmp to the scene
@param LPCWSTR the name of the .bmp
@param int,int the initial x,y cordinates of the .bmp
*/
bool bitScreen::addObject(int ID, LPCWSTR file, int initx, int inity)
{
	if (ID == NULL)
	{
		bmps.push_back(objectLoader(file, hWnd));
	}
	else
	{
		bmps.push_back(objectLoader(file, hWnd, ID));
	}
	bmps[pos].bitMapLoader(initx, inity);
	pos++;
	return true;

	changed = true;
}



/*
Removes an object from the scene
@param int this is the ID, if this is NULL it will use the file name to remove the object
@param the LPCWSTR this is the file name if it is left NULL it will default to the ID
*/
bool bitScreen::removeObject(int ID, LPCWSTR file)
{
	int pos = this->pos + 10;
	if (ID == NULL)
	{
		for (int i = 0; i < this->pos; i++)
		{
			if (bmps[i].getFile() == file)
			{
				pos = i;
			}
		}
	}
	else
	{
		for (int i = 0; i < this->pos; i++)
		{
			if (bmps[i].getID() == ID)
			{
				pos = i;
			}
		}
	}
	if (pos = this->pos + 10)
	{
		return false;
	}
	else
	{
		bmps.erase(bmps.begin() + pos);
		this->pos--;
		return true;
	}

	changed = true;
}

/**
This changes the position of a .bmp in the current scene
@param LPCWSTR the name of the .bmp
@param int,int the new x,y cordinates of the .bmp
@param First int is the "ID" of the bmp in the scene
	The function will use which ever finding strategy is NOT NULL
*/
bool bitScreen::changePosition(int ID, LPCWSTR file, int xPos, int yPos)
{
	int bmpPos;
	if (ID == NULL)
	{
		for (int i = 0; i < pos; i++)
		{
			if (bmps[i].getFile() == file)
			{
				bmpPos = i;
			}
		}
	}
	else if (file == NULL)
	{
		for (int i = 0; i < pos; i++)
		{
			if (bmps[i].getID() == ID)
			{
				bmpPos = i;
			}
		}
	}
	else
	{
		return false;
	}

	bmps[bmpPos].bitMapMove(xPos, yPos);

	changed = true;

	return true;
}

// gets the changed variable to check for refresh
bool bitScreen::getChanged()
{
	return changed;
}


// Refreshes the screen for this scene
void bitScreen::refreshScreen()
{
	backGround.bitMapRender();
	for (int i = 0; i < pos; i++)
	{
		bmps[i].bitMapRender();
	}
	changed = false;
}
