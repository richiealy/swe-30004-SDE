#include "GameStateManager.h"

using namespace std;

GameStateManager::GameStateManager(MessageCentre* msgCentre)
{
	
	_msgCentre = msgCentre;
	_currentState = _currentState = new MainMenu();
	new Channel(msgCentre, this, vector<string>{"gamestatemanager","messagecentre"});
	for each (Channel* c in _channels)
	{
		c->Send(new Message(vector<string>{"subscribe","state"}, this));
		if (c->AreYou("messagecentre"))
		{
			c->Send(new Message(vector<string>{"blackboard", "add"}, "score"));
		}
	}
}

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::Draw()
{
	string userInput = "";
	State* lastState;
	do
	{	
		cout << _currentState->Run(userInput);
		lastState = _currentState;

		_msgCentre->HandleMessages();
		HandleMessages();

		if (lastState == _currentState) // if the state didnt change by the message handler (back command wasnt pressed)
		{
			getline(cin, userInput);
			userInput = ConvertLower(userInput);
		}

		system("CLS");

		ChangeState(userInput);
		
	} while (userInput != "quit");
}

void GameStateManager::HandleMessages()
{
	vector<Message*> myMessages;
	for each (Channel* c in _channels)
	{
		myMessages = c->RetrieveInbox();
		
		for each (Message* m in myMessages)
		{
			if (m->StrContents()=="back")
			{
				_currentState->~State();
				_currentState = new MainMenu();
			}
		}
		c->RetrieveInbox().clear();
	}
}

void GameStateManager::AddChannel(Channel * toAdd)
{
	_channels.push_back(toAdd);
}

void GameStateManager::ChangeState(string changeTo)
{
	if (typeid(*_currentState) == typeid(MainMenu))
	{

		if (changeTo == "1")
		{
			_currentState->~State();
			_currentState = new SelectAdventure();
		}

		if (changeTo == "2")
		{
			_currentState->~State();
			_currentState = new HallOfFame();
		}

		if (changeTo == "3")
		{
			_currentState->~State();
			_currentState = new Help();
		}

		if (changeTo == "4")
		{
			_currentState->~State();
			_currentState = new About();
		}
	}

	else if (typeid(*_currentState) == typeid(SelectAdventure))
	{
		if (changeTo == "1")
		{
			_currentState->~State();
			_currentState = new Gameplay("test.json", _msgCentre);
		}

		if (changeTo == "2")
		{
			_currentState->~State();
			_currentState = new Gameplay("test.json", _msgCentre);
		}

		if (changeTo == "3")
		{
			_currentState->~State();
			_currentState = new Gameplay("test.json", _msgCentre);
		}
	}

	else if (typeid(*_currentState) == typeid(Gameplay))
	{
		if (changeTo == "continue")
		{
			_currentState->~State();
			_currentState = new NewHighScore();
		}
	}
}

