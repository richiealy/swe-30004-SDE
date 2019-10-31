#pragma once
#include "State.h"

class HallOfFame :
	public State
{
public:
	HallOfFame();
	~HallOfFame();
	std::string Run(std::string input);
};

