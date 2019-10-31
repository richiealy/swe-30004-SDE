#include "LookCommand.h"
#include <iostream>
using namespace std;

LookCommand::LookCommand():IdentifiableObject(vector<string>{"look"})
{
}


LookCommand::~LookCommand()
{
}

string LookCommand::Execute(Player* p, vector<string> input)
{
	IHaveInventory* container = nullptr;

	if ((input.size() != 3) & (input.size() != 5))
	{
		return "I don't know how to look at that";
	}

	if ((input.size() == 5) && (input.at(3) != "in"))
	{
		return "What do you want to look in?";
	}

	if (input.at(1) != "at")
	{
		return "What do you want me to look at?";
	}

	if (input.size() == 3)
	{
		container = dynamic_cast<IHaveInventory*>(p);
		//container = FetchContainer(p, input.at(2));
	}

	if (input.size() == 5)
	{
		container = FetchContainer(p, input.at(4));
		if (container == nullptr)
		{
			return "Cannot find the " + input.at(4);
		}
	}

	if (LookAtIn(input.at(2), container) == "") 
	{
		return "Cannot find the " + input.at(2) + " in " + container->Name();
	}
	else
	{
		return LookAtIn(input.at(2), container);
	}

}

IHaveInventory* LookCommand::FetchContainer(Player* p, string containerID)
{
	IHaveInventory* result = nullptr;
	try
	{
		result = dynamic_cast<IHaveInventory*>(p->Locate(containerID));
	}
	catch (const exception&)
	{
		return nullptr;
	}
	
	return result;
}

string LookCommand::LookAtIn(string thingID, IHaveInventory* container)
{
	//container->Locate(thingID)->FullDescription();
    //return container->Locate(thingID)->FullDescription();
	if (container->Locate(thingID) != nullptr)
	{
		return container->Locate(thingID)->FullDescription();	
	}
	else
	{
		return "";
	}
}
