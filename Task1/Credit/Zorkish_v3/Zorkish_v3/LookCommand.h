#pragma once
#include "Command.h"
#include "IHaveInventory.h"
#include <exception>

class LookCommand :
	public Command
{
public:
	LookCommand();
	~LookCommand();
	std::string Execute(Player* p, std::vector<std::string> input);
	IHaveInventory* FetchContainer(Player* p, std::string containerID);
	std::string LookAtIn(std::string thingID, IHaveInventory* container);
};

