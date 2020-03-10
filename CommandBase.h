#pragma once

#include "Dependencies.h"

class CommandBase
{
public:
	CommandBase(int);

	void initialize();
	void execute();

	int getID();

protected:
	int ID;
};

