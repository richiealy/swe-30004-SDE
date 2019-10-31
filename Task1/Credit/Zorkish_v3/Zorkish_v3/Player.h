#pragma once
#include "IHaveInventory.h"
#include "Item.h"
#include "Location.h"

class Player :
	virtual public IHaveInventory
{
public:
	Player();
	Player(std::string name, std::string desc, Location* loc);
	~Player();
	GameObject* Locate(std::string id);
	Inventory* GetInventory();
	Location* GetLocation();
	void SetLocation(Location* newLoc);
	std::string FullDescription() override;
private:
	Inventory* _inventory;
	Location* _location;
};

