#include "Bag.h"
#include <exception>

using namespace std;

Bag::Bag()
{
}

Bag::Bag(vector<string> idents, string name, string desc):GameObject(idents,name,desc)
{
	_inventory = new Inventory();
}


Bag::~Bag()
{
}

GameObject* Bag::Locate(string id)
{
	if (AreYou(id))
	{
		return (GameObject*)this;
	}
	else
	{
		try
		{
			return  (GameObject*)GetInventory()->Fetch(id);
		}
		catch (const std::exception&)
		{
			return nullptr;
		}

	}
}

Inventory* Bag::GetInventory()
{
	return _inventory;
}

string Bag::FullDescription()
{
	return "In the " + Name() + " you can see:" + GetInventory()->ItemList();
}
