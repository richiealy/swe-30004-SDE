#include "GameObject.h"

using namespace std;

GameObject::GameObject()
{
}

GameObject::GameObject(vector<string> idents, string name, string desc):IdentifiableObject(idents)
{
	_name = name;
	_description = desc;
}

GameObject::~GameObject()
{
}

string GameObject::Name()
{
	return _name;
}

string GameObject::ShortDescription()
{
	return Name() + " (" + FirstID() + ")";
}

string GameObject::FullDescription()
{
	return _description;
}
