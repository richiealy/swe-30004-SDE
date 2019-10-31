#include "HallOfFame.h"

using namespace std;

HallOfFame::HallOfFame()
{
}

HallOfFame::~HallOfFame()
{
}

string HallOfFame::Run(string input)
{
	string title = "Zorkish :: Hall of Fame \n" + string(57, '=') + "\n\n";
	string content = "Top 10 Zorkish Adventure Champions\n\n 1. Swaglord, Swag World, 6969\n 2. Nob, Nob World, -9001 \n\nPress ESC or Enter to return to the Main Menu\n";
	return title + content;
}
