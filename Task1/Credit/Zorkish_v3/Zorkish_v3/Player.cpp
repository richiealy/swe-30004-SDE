#include "Player.h"
#include <exception>

using namespace std;

Player::Player()
{
}

Player::Player(string name, string desc, Location* loc):GameObject(vector<string>{"me", "inventory"}, name, desc)
{
	_inventory = new Inventory();
	_location = loc;
}

Player::~Player()
{
}

GameObject* Player::Locate(string id)
{
	if (AreYou(id))
	{
		return dynamic_cast<GameObject*>(this);
	}

	//if (GetInventory()->Fetch(id) != nullptr)
	//modify below to contain "else - if" once locations are added, using the above statement
	else if (GetInventory()->Fetch(id) != nullptr)
	{
		try
		{
			return (GameObject*)GetInventory()->Fetch(id);
		}
		catch (const std::exception&)
		{
			return nullptr;
		}
		
	}
	else if (GetLocation()->AreYou(id))
	{
		return (GameObject*)GetLocation();
	}
	else
	{
		return  (GameObject*)GetLocation()->Locate(id);
	}

}

Inventory* Player::GetInventory()
{
	return _inventory;
}

Location* Player::GetLocation()
{
	return _location;
}

void Player::SetLocation(Location* newLoc)
{
	_location = newLoc;
}

std::string Player::FullDescription()
{
	return "You are carrying: " + GetInventory()->ItemList();
}
