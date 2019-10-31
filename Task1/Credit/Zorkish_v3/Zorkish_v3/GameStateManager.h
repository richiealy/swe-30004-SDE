#pragma once
#include "State.h"
#include "MainMenu.h"
#include "About.h"
#include "Gameplay.h"
#include "HallOfFame.h"
#include "Help.h"
#include "NewHighScore.h"
#include "SelectAdventure.h"
#include "IHaveChannel.h"
#include "Channel.h"
#include "MessageCentre.h"
#include <typeinfo.h>

class GameStateManager :
	public IHaveChannel
{
public:
	GameStateManager();
	GameStateManager(MessageCentre* msgCentre);
	~GameStateManager();
	void Draw();
	void HandleMessages();
	void AddChannel(Channel* toAdd);
private:
	State* _currentState;
	MessageCentre* _msgCentre;
	void ChangeState(std::string userInput);
};

