#pragma once
#include "State.h"

class SelectAdventure :
	public State
{
public:
	SelectAdventure();
	~SelectAdventure();
	std::string Run(std::string input);

};

