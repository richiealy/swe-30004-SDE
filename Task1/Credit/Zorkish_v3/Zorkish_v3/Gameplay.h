#pragma once
#include <fstream>
#include "State.h"
#include "Player.h"
#include "Item.h"
#include "Bag.h"
#include "json.hpp"

class Gameplay :
	public State
{
private:
	Player* _player;
	std::vector<Location*> _locations;
public:
	void LoadMap(std::string input);
	Gameplay();
	Gameplay(std::string input, MessageCentre* msgCentre);
	~Gameplay();
	std::string Run(std::string input);
};

