#include "CheckScoreCommand.h"

using namespace std;

CheckScoreCommand::CheckScoreCommand():IdentifiableObject(vector<string>{"check","score"})
{
}


CheckScoreCommand::~CheckScoreCommand()
{
}

string CheckScoreCommand::Execute(Player * p, vector<string> input)
{
	string result;
	for each (Channel* c in _channels)
	{
		result = to_string(c->Listen("score")->IntContents());
	}
	return result;
	//return "check score command success";
}

void CheckScoreCommand::HandleMessages()
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

void CheckScoreCommand::AddChannel(Channel * toAdd)
{
	_channels.push_back(toAdd);
}
