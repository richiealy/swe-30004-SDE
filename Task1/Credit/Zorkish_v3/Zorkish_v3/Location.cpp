#include "Location.h"

using namespace std;

Location::Location()
{
}

Location::Location(vector<string> idents, string name, string desc):GameObject(idents, name, desc)
{
	_inventory = new Inventory();
}

Location::~Location()
{
}

GameObject * Location::Locate(string id)
{
	if (AreYou(id))
	{
		return dynamic_cast<GameObject*>(this);
	}
	else
	{
		try
		{
			return (GameObject*)GetInventory()->Fetch(id);
		}
		catch (const std::exception&)
		{
			return nullptr;
		}

	};
}

Inventory * Location::GetInventory()
{
	return _inventory;
}

void Location::LinkToPath(string direction, Path* pathToLink)
{
	_availablePaths[direction] = pathToLink;
}

Location* Location::EnterPath(string direction)
{
	if (_availablePaths.count(direction)==1)
	{
		return _availablePaths[direction]->GoThrough(this);
	}
	else
	{
		return nullptr;
	}

	try
	{
		return _availablePaths[direction]->GoThrough(this);
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
	
}
