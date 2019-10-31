#pragma once
#include "Item.h"
#include "IHaveInventory.h"
class Bag :
	public Item, public IHaveInventory
{
public:
	Bag();
	Bag(std::vector<std::string> idents, std::string name, std::string desc);
	~Bag();
	GameObject* Locate(std::string id);
	Inventory* GetInventory();
	std::string FullDescription() override;
private:
	Inventory* _inventory;
};

