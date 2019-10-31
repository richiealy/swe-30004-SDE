#include "CreateCommand.h"

using namespace std;

CreateCommand::CreateCommand():IdentifiableObject(vector<string>{"create"})
{
}


CreateCommand::~CreateCommand()
{
}

string CreateCommand::Execute(Player * p, vector<string> input)
{
	return "create command success";
}

void CreateCommand::HandleMessages()
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

void CreateCommand::AddChannel(Channel * toAdd)
{
	_channels.push_back(toAdd);
}
