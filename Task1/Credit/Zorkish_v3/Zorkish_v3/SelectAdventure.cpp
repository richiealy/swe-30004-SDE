#include "SelectAdventure.h"

using namespace std;

SelectAdventure::SelectAdventure()
{
}

SelectAdventure::~SelectAdventure()
{
}

string SelectAdventure::Run(string input)
{
	string title = "Zorkish :: Select Adventure \n" + string(57, '=') + "\n\n";
	string content = "Choose your adventure:\n\n \t 1. Mountain World\n\t 2. Water World\n\t 3. Box World \n\nSelect 1-3:> ";
	return content;
}
