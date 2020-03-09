#pragma once
#include "Scene.h"
// Must include all of the button / param IDs
// Parent (REQUIRES CHILD TO WORK PROPERLY)
class MenuImplamentation
{
public:
	MenuImplamentation();

	MenuImplamentation(Scene);

	WPARAM getKey();

	void setHandle(WPARAM);

	WPARAM callIDHandle();

	// Gets the new updated scene
	void passScene(Scene);

	WPARAM handle;

	Scene screen;
};

