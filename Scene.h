#pragma once
#include "Dependencies.h"
#include "bitScreen.h"
#include "Menus.h"
class Scene
{
public:
	Scene();

	Scene(bitScreen, Menus);


	// Returns the containing items
	bitScreen getScreen();
	Menus getMenu();

	bitScreen screen;
	Menus menu;

private:
	
};

