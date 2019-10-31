#pragma once
#include "Channel.h"
#include "AnnounceSys.h"
#include "Message.h"
#include <vector>

class MessageCentre :
	public virtual IHaveChannel
{
public:
	MessageCentre();
	~MessageCentre();
	std::vector<Message*> Blackboard();
	std::vector<AnnounceSys*> AnnouncementSystems();
	void HandleMessages();
	void AddChannel(Channel* toAdd);
private:
	std::vector<Message*> _blackboard;
	std::vector<AnnounceSys*> _announcementSystems;
};

