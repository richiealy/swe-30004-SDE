#pragma once
#include "IHaveInventory.h"
#include "Path.h"

class Path; // forward declaration

class Location :
	virtual public IHaveInventory
{
public:
	Location();
	Location(std::vector<std::string> idents, std::string name, std::string desc);
	~Location();
	GameObject* Locate(std::string id);
	Inventory* GetInventory();
	void LinkToPath(std::string direction, Path* pathToLink);
	Location* EnterPath(std::string direction);
private:
	Inventory* _inventory;
	std::map<std::string, Path*> _availablePaths;
};

