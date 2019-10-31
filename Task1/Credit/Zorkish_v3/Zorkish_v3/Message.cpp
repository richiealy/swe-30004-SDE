#include "Message.h"

using namespace std;

Message::Message()
{
}

Message::Message(vector<string> destinations, string contents):IdentifiableObject(destinations)
{
	_strContents = contents;
}

Message::Message(vector<string> destinations, IHaveChannel* contents):IdentifiableObject(destinations)
{
	_objContents = contents;
}

Message::Message(std::vector<std::string> destinations, int contents):IdentifiableObject(destinations)
{
	_intContents = contents;
}


Message::~Message()
{
}

string Message::StrContents()
{
	return _strContents;
}

IHaveChannel* Message::ObjContents()
{
	return _objContents;
}

int Message::IntContents()
{
	return _intContents;
}
