#include "MoveCommand.h"

using namespace std;

MoveCommand::MoveCommand():IdentifiableObject(vector<string>{"move","go","head","leave"})
{
}


MoveCommand::~MoveCommand()
{
}

std::string MoveCommand::Execute(Player * p, vector<string> input)
{
	if (p->GetLocation()->EnterPath(input[1]) != nullptr)
	{
		p->SetLocation(p->GetLocation()->EnterPath(input[1]));
		for each (Channel* c in _channels)
		{
			c->Send(new Message(vector<string>{"blackboard", "score"}, 1));
		}
		return "You are in: " + p->GetLocation()->FullDescription();
	}
	else
	{
		return "This is not a valid place to move";
	}

}

void MoveCommand::HandleMessages()
{
}

void MoveCommand::AddChannel(Channel * toAdd)
{
	_channels.push_back(toAdd);
}
