#include "Help.h"

using namespace std;

Help::Help()
{
}

Help::~Help()
{
}

string Help::Run(string input)
{
	string title = "Zorkish :: Help \n" + string(57, '=') + "\n\n";
	string content = "The following commands are supported:\n\n \t quit,\n\t hiscore (for testing) \n\nPress ESC or Enter to return to the Main Menu\n";
	return title + content;
}
