#include "AnnounceSys.h"
#include <iostream>

using namespace std;

AnnounceSys::AnnounceSys()
{
}

AnnounceSys::AnnounceSys(std::vector<std::string> type):IdentifiableObject(type)
{
}


AnnounceSys::~AnnounceSys()
{
}

void AnnounceSys::AddSubscriber(IHaveChannel* newSubscriber, string name)
{
	new Channel(this, newSubscriber, vector<string>{name});
}

void AnnounceSys::HandleMessages()
{
	//Sends (announced) any messages it contains to all connected channels
	for each (Channel* c in _channels)
	{
		//Make a variable to store messages that need to be announced and send all at once
		for each (Message* m in _announcements)
		{
			c->Send(new Message(vector<string>{c->FirstID()}, m->StrContents()));
		}
	}
	_announcements.clear();
}

void AnnounceSys::AddChannel(Channel* toAdd)
{
	_channels.push_back(toAdd);
}

//May be redudant -> delete?
std::vector<Message*> AnnounceSys::Announcements()
{
	return _announcements;
}

void AnnounceSys::AddAnnouncement(Message * msg)
{
	_announcements.push_back(msg);
}
