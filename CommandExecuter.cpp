#include "pch.h"
#include "CommandExecuter.h"


void CommandExecuter::createCommand(CommandBase cmd, int id)
{
	commands.push_back(cmd);
	position = 0;
}

void CommandExecuter::removeCommand(int id)
{
	for (int i = 0; i < position; i++)
	{
		if (commands[i].getID() == id)
		{
			commands.erase(commands.begin() + i);
			position++;
		}
	}
}

// Starts the process of running the command modules
void CommandExecuter::start()
{
	for (int i = 0; i < position; i++)
	{
		commands[i].initialize();
	}
}

// Runs the command modules through once
void CommandExecuter::run()
{
	for (int i = 0; i < position; i++)
	{
		commands[i].execute();
	}


}

// Stops running and prepars to dealocate memory
void CommandExecuter::stop()
{
	position = NULL;
	commands.clear();
}
