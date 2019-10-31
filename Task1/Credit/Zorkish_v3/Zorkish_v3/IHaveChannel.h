#pragma once
#include "Channel.h"

#include <vector>

class Channel; // forward declaration


class IHaveChannel
{
public:
	virtual void HandleMessages() = 0;
	virtual void AddChannel(Channel* toAdd) = 0;
protected:
	std::vector<Channel*> _channels;
};

