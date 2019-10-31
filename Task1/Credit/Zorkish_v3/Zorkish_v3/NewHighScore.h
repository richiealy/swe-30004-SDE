#pragma once
#include "State.h"

class NewHighScore :
	public State
{
public:
	NewHighScore();
	~NewHighScore();
	std::string Run(std::string input);

};

