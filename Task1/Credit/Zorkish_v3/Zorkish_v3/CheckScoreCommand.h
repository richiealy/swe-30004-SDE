#pragma once
#include "Command.h"
#include "IHaveChannel.h"
class CheckScoreCommand :
	public Command, public IHaveChannel
{
public:
	CheckScoreCommand();
	~CheckScoreCommand();
	std::string Execute(Player* p, std::vector<std::string> input);
	void HandleMessages();
	void AddChannel(Channel* toAdd);
};

