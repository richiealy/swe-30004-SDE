#pragma once
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	bool HasItem(std::string id);
	void Put(Item* itm);
	Item* Take(std::string id);
	Item* Fetch(std::string id);
	std::string ItemList();

private:
	std::vector<Item*> _items;
};

