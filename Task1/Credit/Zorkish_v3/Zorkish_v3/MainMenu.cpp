#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

string MainMenu::Run(string input)
{
	string title = "Zorkish :: Main Menu \n" + string(57, '=') + "\n\n";
	string content = "Welcome to Zorkish Adventures\n\n \t 1. Select Adventure and Play\n\t 2. Hall of Fame\n\t 3. Help\n\t 4. About \n\t 5. Quit \n\nSelect 1-5:> ";

	return title + content;
}
