#include "Gameplay.h"

using namespace std;
using namespace nlohmann;

void Gameplay::LoadMap(string input)
{
	// read inputFile into map variable
	ifstream inputFile(input);
	json load(inputFile);

	// loading vectors and variables
	vector<Bag*> bags;
	vector<Item*> items;
	vector<Path*> paths;
	Location* location1;
	Location* location2;

	// iterators
	int bagIt = 0;
	int playerIt = 0;
	int locIt = 0;

	// load items into vector
	for (auto& i : load["items"])
		items.push_back(new Item(vector<string> { i["name"] }, i["name"], i["description"]));

	// load bags into vector
	for (auto& i : load["bags"])
	{
		bags.push_back(new Bag(vector<string> { i["name"] }, i["name"], i["description"]));
		for (int j = 0; j < items.size(); j++)
		{
			for (auto& k : i["inventory"])
			{
				if (items[j]->Name() == k["item"])
					bags[bagIt]->GetInventory()->Put(items[j]);
			}
		}
		bagIt++;
	}

	// load locations + inventory
	for (auto& i : load["locations"])
	{
		_locations.push_back(new Location(vector<string> { i["name"] }, i["name"], i["description"]));
		for (int j = 0; j < items.size(); j++)
		{
			for (auto& k : i["inventory"])
			{
				if (items[j]->Name() == k["item"])
					_locations[locIt]->GetInventory()->Put(items[j]);
			}
		}

		for (int j = 0; j < bags.size(); j++)
		{
			for (auto& k : i["inventory"])
			{
				if (bags[j]->Name() == k["bag"])
					_locations[locIt]->GetInventory()->Put(bags[j]);
			}
		}

		locIt++;
	}

	// load paths
	for (auto& i : load["paths"])
	{
		for (int j = 0; j < _locations.size(); j++)
		{
			if (_locations[j]->Name() == i["location1"])
			{ 
				location1 = _locations[j];
			}
		}

		for (int j = 0; j < _locations.size(); j++)
		{
			if (_locations[j]->Name() == i["location2"])
			{
				location2 = _locations[j];
			}
		}
		paths.push_back(new Path(location1, location2, i["direction1"], i["direction2"]));
	}

	// load player's bags and items
	_player = new Player("me", "inventory", _locations[0]);
	for (auto& i : load["player"]["inventory"])
	{
		if (items[playerIt]->Name() == i["item"])
			_player->GetInventory()->Put(items[playerIt]);

		if (bags[playerIt]->Name() == i["bag"])
			_player->GetInventory()->Put(bags[playerIt]);

		playerIt++;
	}
}

Gameplay::Gameplay(string input, MessageCentre* msgCentre)
{
	//Initialise the commands (currently: back and check)
	BackCommand* backCmd = new BackCommand();
	CheckScoreCommand* checkCmd = new CheckScoreCommand();
	MoveCommand* moveCmd = new MoveCommand();
	new Channel(msgCentre, backCmd, vector<string>{"backcommand","messagecentre"});
	new Channel(msgCentre, checkCmd, vector<string>{"checkcommand","messagecentre"});
	new Channel(msgCentre, moveCmd, vector<string>{"movecommand", "messagecentre"});

	LoadMap(input);

	_cmdProcessor = new CommandProcessor(vector<Command*>{backCmd, checkCmd, moveCmd});
}

Gameplay::Gameplay()
{
	LoadMap("test.json");
}

Gameplay::~Gameplay()
{
}

string Gameplay::Run(string input)
{
	string title = "Zorkish :: Gameplay \n" + string(57, '=') + "\n\n";
	string content = "You have started a new game \n\nType 'Continue' to add a new High Score\nType 'back' to return to the previous menu\n";
	return title + content + _cmdProcessor->CmdCall(_player, input);
}