#pragma once

#include "Dependencies.h"

class CommandBase
{
public:
	CommandBase();

	void initialize();
	void execute();

	int getID();

protected:
	int ID;
};

