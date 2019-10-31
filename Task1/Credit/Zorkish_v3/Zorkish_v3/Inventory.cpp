#include "Inventory.h"

using namespace std;

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

bool Inventory::HasItem(string id)
{
	for (Item* i : _items)
	{
		if (i->AreYou(id))
		{
			return true;
		}
	}
	return false;
}

void Inventory::Put(Item* itm)
{
	_items.push_back(itm);
}

Item* Inventory::Take(string id)
{
	Item* result = nullptr;
	for (int i = 0; i < _items.size(); i++)
	{
		if (_items.at(i)->AreYou(id))
		{
			result = _items.at(i);
			_items.erase(_items.begin() + i);
		}
	}
	
	return result;
}

Item* Inventory::Fetch(string id)
{
	for (Item* i : _items)
	{
		if (i->AreYou(id))
		{
			return i;
		}
	}
	return nullptr;
}

string Inventory::ItemList()
{
	string result = "";
	for (Item* i : _items)
	{
		result = result + "\n" + i->ShortDescription();
	}
	return result;
}
