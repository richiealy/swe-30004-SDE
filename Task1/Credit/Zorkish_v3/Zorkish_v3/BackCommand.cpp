#include "BackCommand.h"

using namespace std;

BackCommand::BackCommand() :IdentifiableObject(vector<string>{"back"})
{
}

BackCommand::~BackCommand()
{
}

string BackCommand::Execute(Player * p, vector<std::string> input)
{
	
	for each (Channel* c in _channels)
	{
		if (c->AreYou("messagecentre"))
		{
			//c->Send(new Message(vector<string>{"gamestatemanager"}, "back"));
			c->Send(new Message(vector<string>{"state"}, "back"));
		}
	}
	return "back command fail";
}

void BackCommand::HandleMessages()
{
	vector<Message*> myMessages;
	for each (Channel* c in _channels)
	{
		 myMessages = c->RetrieveInbox();
		 for each (Message* m in myMessages)
		 {
			 m->~Message();
		 }
	}
}

void BackCommand::AddChannel(Channel * toAdd)
{
	_channels.push_back(toAdd);
}
