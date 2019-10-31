#include "TransferCommand.h"

using namespace std;

TransferCommand::TransferCommand():IdentifiableObject(vector<string>{"put","take"})
{
}


TransferCommand::~TransferCommand()
{
}

string TransferCommand::Execute(Player* p, vector<string> input)
{
	IHaveInventory* container = nullptr;

	if ((((input.size() == 2) && (input.at(0) == "take")) || ((input.size() == 4) && ((input.at(0)) == "put") | (input.at(0) == "take"))) == false)
	{
		return "Invalid transfer command";
	}

	if ((input.at(0) == "put") && (input.at(2) != "in"))
	{
		return "Where would you like to put this?";
	}

	if ((input.at(0) == "take") && (input.size() == 4) && (input.at(2) != "from"))
	{
		return "I don't know where you're trying to take this from";
	}

	if ((input.size() == 4) && (input.at(2) == "from"))
	{
		container = dynamic_cast<IHaveInventory*>(p->Locate(input.at(3)));
		p->GetInventory()->Put(container->GetInventory()->Take(input.at(1)));
		return "You have taken " + input.at(1) + " from " + input.at(3);
	}

	if (p->Locate(input.at(1)) == nullptr)
	{
		return "I cannot find " + input.at(1);
	}

	if (input.at(0) == "put")
	{
		container = dynamic_cast<IHaveInventory*>(p->Locate(input.at(3)));
		//GetInventory->Take may have to be changed to "TakeItem" once location is added
		container->GetInventory()->Put(p->GetInventory()->Take(input.at(1)));
		return "You have put " + input.at(1) + " in " + input.at(3);
	}
	else
	{
		//GetInventory->Take may have to be changed to "TakeItem" once location is added
		p->GetInventory()->Put(p->GetInventory()->Take(input.at(1)));
		return "You have taken " + input.at(1);
	}
}
