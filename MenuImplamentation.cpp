#include "MenuImplamentation.h"

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