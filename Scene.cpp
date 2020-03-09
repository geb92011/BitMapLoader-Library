#include "pch.h"
#include "Scene.h"

Scene::Scene()
{
	screen = bitScreen();
	menu = Menus();
}


Scene::Scene(bitScreen newScreen, Menus newMenu)
{
	this->screen = newScreen;
	this->menu = newMenu;
}


// Returns the containing items
bitScreen Scene::getScreen()
{
	return screen;
}
Menus Scene::getMenu()
{
	return menu;
}
