#pragma once
#include "Command.h"
#include "IHaveChannel.h"
class BackCommand :
	public Command, public IHaveChannel
{
public:
	BackCommand();
	~BackCommand();
	std::string Execute(Player* p, std::vector<std::string> input);
	void HandleMessages();
	void AddChannel(Channel* toAdd);
};

