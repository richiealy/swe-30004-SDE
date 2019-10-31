#pragma once
#include "ConvertLower.h"
#include <vector>

class IdentifiableObject
{
public:
	IdentifiableObject();
	IdentifiableObject(std::vector<std::string> idents);
	~IdentifiableObject();
	bool AreYou(std::string id);
	std::string FirstID();
	void AddIdentifier(std::string id);

private:
	std::vector<std::string> _identifiers;
};

