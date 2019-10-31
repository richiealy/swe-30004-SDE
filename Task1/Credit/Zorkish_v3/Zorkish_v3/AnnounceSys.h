#pragma once
#include "IHaveChannel.h"
class AnnounceSys :
	public IHaveChannel, public IdentifiableObject
{
public:
	AnnounceSys();
	AnnounceSys(std::vector<std::string> type);
	~AnnounceSys();
	void AddSubscriber(IHaveChannel* newSubscriber, std::string name);
	void HandleMessages();
	void AddChannel(Channel* toAdd);
	std::vector<Message*> Announcements();
	void AddAnnouncement(Message* msg);
private:
	std::vector<Message*> _announcements;
};

