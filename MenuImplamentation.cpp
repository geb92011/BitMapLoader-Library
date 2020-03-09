#include "MenuImplamentation.h"

MenuImplamentation::MenuImplamentation()
{
	handle = NULL;
	screen = Scene();
}


MenuImplamentation::MenuImplamentation(Scene scene)
{
	handle = NULL;
	this->screen = scene;
}

WPARAM MenuImplamentation::getKey()
{
	return handle;
}

void MenuImplamentation::setHandle(WPARAM wParam)
{
	handle = wParam;
}


void MenuImplamentation::passScene(Scene scene)
{
	screen = scene;
}


WPARAM MenuImplamentation::callIDHandle()
{

	return NULL;
}