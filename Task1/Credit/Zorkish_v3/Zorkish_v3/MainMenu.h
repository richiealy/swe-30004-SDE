#pragma once
#include "State.h"
#include <iostream>

class MainMenu :
	public State
{
public:
	MainMenu();
	~MainMenu();
	std::string Run(std::string input);

};

