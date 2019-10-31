#pragma once
#include "Command.h"
class TransferCommand :
	public Command
{
public:
	TransferCommand();
	~TransferCommand();
	std::string Execute(Player* p, std::vector<std::string> input);
};

