#pragma once
#include "CommandProcessor.h"
#include "MessageCentre.h"

class State
{
public:
	State();
	~State();
	virtual std::string Run(std::string input);
protected:
	//Not initialised in State.cpp, but in each of the child states
	CommandProcessor* _cmdProcessor;
};

