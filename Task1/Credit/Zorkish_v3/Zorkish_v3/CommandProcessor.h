#pragma once
#include "LookCommand.h"
#include "TransferCommand.h"
#include "MoveCommand.h"
#include "BackCommand.h"
#include "CheckScoreCommand.h"
#include "CreateCommand.h"
#include "MessageCentre.h"
#include <vector>
#include <sstream>

class CommandProcessor
{
public:
	CommandProcessor();
	CommandProcessor(std::vector<Command*> cmdList);
	std::string CmdCall(Player* p, std::string input);
	~CommandProcessor();
private:
	std::vector<Command*> _cmdList;
};

