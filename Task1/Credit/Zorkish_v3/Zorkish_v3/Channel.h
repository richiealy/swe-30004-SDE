#pragma once
#include "Message.h"
#include "IHaveChannel.h"
#include <vector>

class IHaveChannel; // forward declaration

class Channel :
	public IdentifiableObject
{
public:
	Channel();
	Channel(IHaveChannel* msgCentre, IHaveChannel* objOwner, std::vector<std::string> idents);
	~Channel();
	void Send(Message* newMessage);
	Message* Listen(std::string listenFor);
	std::vector<Message*> RetrieveInbox();
	std::vector<Message*> RetrieveOutbox();
private:
	IHaveChannel* _msgCentre;
	IHaveChannel* _objOwner;
	std::vector<Message*> _inbox;
	std::vector<Message*> _outbox;
};

