#pragma once
#include "State.h"

class About :
	public State
{
public:
	About();
	~About();
	std::string Run(std::string input);
};

