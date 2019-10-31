#include "IdentifiableObject.h"

using namespace std;

IdentifiableObject::IdentifiableObject()
{
}

IdentifiableObject::IdentifiableObject(vector<string> idents)
{
	for (string s : idents)
	{
		AddIdentifier(s);
	}
}

IdentifiableObject::~IdentifiableObject()
{
}

bool IdentifiableObject::AreYou(string id)
{
	for (string s : _identifiers)
	{
		if (ConvertLower(id) == s)
		{
			return true;
		}
	}
	return false;
}

string IdentifiableObject::FirstID()
{
	return _identifiers.at(0);
}

void IdentifiableObject::AddIdentifier(string id)
{
	_identifiers.push_back(ConvertLower(id));
}
