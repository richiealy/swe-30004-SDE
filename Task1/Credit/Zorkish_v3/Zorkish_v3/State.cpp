#include "State.h"
#include "iostream"

using namespace std;

State::State()
{
}

State::~State()
{
}

//Input is passed to the CmdProcessor here
//Make sure both the Run in this class AND the child classes are executing
string State::Run(string input)
{
	return string();
}