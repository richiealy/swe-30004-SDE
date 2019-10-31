#include "NewHighScore.h"

using namespace std;

NewHighScore::NewHighScore()
{
}

NewHighScore::~NewHighScore()
{
}

string NewHighScore::Run(string input)
{
	string title = "Zorkish :: New High Score \n" + string(57, '=') + "\n\n";
	string content = "Congratulations!\n\n You Have made it to the Zorkish Hall of Fame\n\n Adventure: Swag World\n Score: 6969\n Moves: 420\n \n\nPlease type your name and press enter:\n:> ";
	return title + content;
}
