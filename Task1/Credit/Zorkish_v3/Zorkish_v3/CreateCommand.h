#pragma once
#include "Command.h"
#include "IHaveChannel.h"
class CreateCommand :
	public Command, IHaveChannel
{
public:
	CreateCommand();
	~CreateCommand();
	std::string Execute(Player* p, std::vector<std::string> input);
	void HandleMessages();
	void AddChannel(Channel* toAdd);
};

