#include "MessageCentre.h"
#include <iostream>
using namespace std;

MessageCentre::MessageCentre()
{
	_announcementSystems.push_back(new AnnounceSys(vector<string>{"state"}));
}


MessageCentre::~MessageCentre()
{
}

std::vector<Message*> MessageCentre::Blackboard()
{
	return _blackboard;
}

vector<AnnounceSys*> MessageCentre::AnnouncementSystems()
{
	//this getter MAY not actually be relevant OR changed to a simple function
	//that loops through all announce systems, telling them to HandleMessages()
	return _announcementSystems;
}

void MessageCentre::HandleMessages()
{
	vector<Message*> myMessages;
	for each (Channel* c in _channels)
	{
		myMessages = c->RetrieveOutbox();
		for each (Message* m in myMessages)
		{	
			if (m->AreYou("blackboard"))
			{
				for each (Message* b in _blackboard)
				{
					if (m->AreYou(b->FirstID()))
					{
						
						if (m->AreYou("score"))
						{
							//cout << m->IntContents();
							int newScore = b->IntContents() + m->IntContents();
							//_blackboard.pop_back();
							b = new Message(vector<string>{b->FirstID()}, newScore);
						}
					}
				}
				if (m->AreYou("add"))
				{
					_blackboard.push_back(new Message(vector<string>{m->StrContents()}, 0));
				}
			}
			//Subscribes objects to an announcement system
			if (m->AreYou("subscribe"))
			{
				for each (AnnounceSys* a in _announcementSystems)
				{
					if (m->AreYou(a->FirstID()))
					{
						a->AddSubscriber(m->ObjContents(), c->FirstID());
					}
				}
			}
			//Sends any messages that need to be announced to the correct system
			else
			{
				for each (AnnounceSys* a in _announcementSystems)
				{
					if (m->AreYou(a->FirstID()))
					{
						a->AddAnnouncement(m);
					}
				}
			}
			
			
			//Sends directed messages to channels via 1 to 1 messaging
			for each (Channel* c in _channels)
			{
				if (c->AreYou(m->FirstID()))
				{
					c->Send(m);
				}
			}
		}
		c->RetrieveOutbox().clear();
	}

	for each (AnnounceSys* a in _announcementSystems)
	{
		a->HandleMessages();
	}
}
void MessageCentre::AddChannel(Channel* toAdd)
{
	_channels.push_back(toAdd);
}

