#pragma once
#include "IdentifiableObject.h"

class GameObject :
	public IdentifiableObject
{
public:
	GameObject();
	GameObject(std::vector<std::string> idents, std::string name, std::string desc);
	~GameObject();
	std::string Name();
	std::string ShortDescription();
	virtual std::string FullDescription();

private:
	std::string _name;
	std::string _description;
};

