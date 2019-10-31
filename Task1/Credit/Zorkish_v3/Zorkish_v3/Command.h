#pragma once
#include "ConvertLower.h"
#include "IdentifiableObject.h"
#include "Player.h"
//REMINDER: delete <vector> from CommandProcessor
class Command :
	public virtual IdentifiableObject
{
public:
	Command();
	~Command();
	virtual std::string Execute(Player* p, std::vector<std::string> input) = 0;
};

