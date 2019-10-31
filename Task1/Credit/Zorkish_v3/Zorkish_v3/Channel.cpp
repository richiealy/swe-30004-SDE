#include "Channel.h"
#include "MessageCentre.h"
using namespace std;

Channel::Channel()
{
}

Channel::Channel(IHaveChannel* msgCentre, IHaveChannel* objOwner, vector<string> idents):IdentifiableObject(idents)
{
	_objOwner = objOwner;
	_msgCentre = msgCentre;

	_objOwner->AddChannel(this);
	_msgCentre->AddChannel(this);
}

Channel::~Channel()
{
}

void Channel::Send(Message* newMessage)
{
	if (newMessage->AreYou(FirstID()))
	{
		_inbox.push_back(newMessage);
	}
	else
	{
		_outbox.push_back(newMessage);
	}
}

Message* Channel::Listen(string listenFor)
{
	for each (Message* m in dynamic_cast<MessageCentre*>(_msgCentre)->Blackboard())
	{
		if (m->AreYou(listenFor))
		{
			return m;
		}
	};
}

std::vector<Message*> Channel::RetrieveInbox()
{
	vector<Message*> toReturn = _inbox;
	_inbox.clear();
	return toReturn;
}

vector<Message*> Channel::RetrieveOutbox()
{
	vector<Message*> toReturn = _outbox;
	_outbox.clear();
	return toReturn;
}
