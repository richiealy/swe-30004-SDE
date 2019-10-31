#pragma once
#include "GameObject.h"
class Item :
	virtual public GameObject
{
public:
	Item();
	Item(std::vector<std::string> idents, std::string name, std::string desc);
	~Item();
};

