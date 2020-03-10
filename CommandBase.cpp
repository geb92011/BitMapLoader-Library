#include "pch.h"
#include "CommandBase.h"


CommandBase::CommandBase(int id)
{
	ID = id;
}

void CommandBase::initialize()
{

}

void CommandBase::execute()
{

}

int CommandBase::getID()
{
	return ID;
}
