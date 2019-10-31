#pragma once
#include <string>
#include "Inventory.h"
#include "GameObject.h"
class IHaveInventory : virtual public GameObject
{
public:
	virtual GameObject* Locate(std::string id) = 0;
	virtual Inventory* GetInventory() = 0;
protected:
	Inventory* _inventory;
};