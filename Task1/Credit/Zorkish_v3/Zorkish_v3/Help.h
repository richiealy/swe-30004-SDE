#pragma once
#include "State.h"

class Help :
	public State
{
public:
	Help();
	~Help();
	std::string Run(std::string input);

};

