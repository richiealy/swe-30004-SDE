#pragma once
#include "Command.h"
#include "IHaveChannel.h"
class MoveCommand :
	public Command, public IHaveChannel
{
public:
	MoveCommand();
	~MoveCommand();
	std::string Execute(Player* p, std::vector<std::string> input);
	void HandleMessages();
	void AddChannel(Channel* toAdd);
};

