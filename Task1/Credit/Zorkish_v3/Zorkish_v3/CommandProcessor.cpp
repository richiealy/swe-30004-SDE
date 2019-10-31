#include "CommandProcessor.h"

using namespace std;

CommandProcessor::CommandProcessor()
{
	_cmdList.push_back(new LookCommand());
	_cmdList.push_back(new TransferCommand());
	_cmdList.push_back(new MoveCommand());
	_cmdList.push_back(new BackCommand());
	_cmdList.push_back(new CreateCommand());
	_cmdList.push_back(new CheckScoreCommand());
}

CommandProcessor::CommandProcessor(vector<Command*> cmdList)
{
	for each (Command* c in cmdList)
	{
		_cmdList.push_back(c);
	}
}

CommandProcessor::~CommandProcessor()
{
}

string CommandProcessor::CmdCall(Player* p, string input)
{

	stringstream sstream(input);
	string buffer;
	vector<string> inputVector;

	while (sstream >> buffer) 
		inputVector.push_back(buffer);

	for each (Command* c in _cmdList)
	{
		// try-catch prevents keys such as enter from crashing the game, 
		// processes them as invalid input instead.
		try 
		{
			if (c->AreYou(inputVector.at(0)))
			{
				return c->Execute(p, inputVector) + "\nPlease input a valid command:> ";
			}
		}
		catch (const exception&)
		{
			return "Please input a valid command:> ";
		}
	}

	return "Please input a valid command:> ";
}
