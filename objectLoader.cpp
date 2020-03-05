#include "pch.h"
#include "objectLoader.h"


// Default constructor
objectLoader::objectLoader()
{
	FileName = NULL;
	qBitmap;
	hLocalDC = NULL;

	hWnd = NULL;
	ID = NULL;

	xCord = NULL;
	yCord = NULL;
}



// Item with no ID
objectLoader::objectLoader(LPCWSTR file, HWND hwnd)
{
	ID = NULL;
	FileName = file;
	qBitmap ;
	hLocalDC;
	hWnd = hwnd;

}

// Provides a second constructor for id number
objectLoader::objectLoader(LPCWSTR file, HWND hwnd, int ID)
{
	this->ID = ID;
	FileName = file;
	qBitmap;
	hLocalDC;
	hWnd = hwnd;

}


int objectLoader::getID()
{
	return ID;
}
// Returns the file name/path
LPCWSTR objectLoader::getFile()
{
	return FileName;
}



bool objectLoader::bitMapLoader(int xCord, int yCord)
{
	this->xCord = xCord;
	this->yCord = yCord;
	// Load image file
	HBITMAP hBitmap;
	hBitmap = (HBITMAP)::LoadImage(NULL, FileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	// Error check for NULL bmp value
	if (hBitmap == NULL)
	{
		MessageBox(NULL, L"LoadImage failed to load a defined .bmp file",
			L"Error", MB_OK);
		return false;
	}

	// Creats a device context that is compatible with this window

	hLocalDC = ::CreateCompatibleDC(GetDC(hWnd));
	// Verify the DC was created
	if (hLocalDC == NULL)
	{
		MessageBox(NULL, L"Local DC failed to create",
			L"Error", MB_OK);
		return false;
	}

	// Verify the bmp's get
	int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP),
		reinterpret_cast<LPVOID>(&qBitmap));
	if (!iReturn)
	{
		MessageBox(NULL, L"Get bmp failed",
			L"Error", MB_OK);
		return false;
	}

	// Select the loaded bitmap into the device context
	HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL)
	{
		MessageBox(NULL, L"Select BMP failed",
			L"Error", MB_OK);
		return false;
	}

	return true;
}

bool objectLoader::bitMapRender()
{
	// Move the dc that holds the windows dc to the window dc

	BOOL qRetBlit = BitBlt(GetDC(hWnd), xCord, yCord, qBitmap.bmWidth, qBitmap.bmHeight,
		hLocalDC, 0, 0, SRCCOPY);

	if (!qRetBlit)
	{
		MessageBox(NULL, L"bmp blit failed",
			L"Error", MB_OK);
		return false;
	}
	return true;
}



bool objectLoader::bitMapMove(int xPos, int yPos)
{
	xCord = xPos;
	yCord = yPos;
	return true;
}
