#pragma once
#include "IdentifiableObject.h"

class IHaveChannel;

class Message :
	public IdentifiableObject
{
public:
	Message();
	Message(std::vector<std::string> destinations, std::string contents);
	Message(std::vector<std::string> destinations, IHaveChannel* contents);
	Message(std::vector<std::string> destinations, int contents);
	~Message();
	std::string StrContents();
	IHaveChannel* ObjContents();
	int IntContents();
private:
	std::string _strContents;
	IHaveChannel* _objContents;
	int _intContents;
};

