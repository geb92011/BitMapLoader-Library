#pragma once

#include "Dependencies.h"
#include <vector>

#include "CommandBase.h"
class CommandExecuter
{
public:

	void createCommand(CommandBase, int);

	void removeCommand(int);

	// Starts the process of running the command modules
	void start();

	// Runs the command modules through once
	void run();

	// Stops running and prepars to dealocate memory
	void stop();

private:
	std::vector<CommandBase> commands;

	int position;

	bool winHandleIND;

};

