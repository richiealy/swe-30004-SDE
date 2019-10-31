#include "About.h"

using namespace std;

About::About()
{
}

About::~About()
{
}

string About::Run(string input)
{
	string title = "Zorkish :: About \n" + string(57, '=') + "\n\n";
	string content = "Written by: Richard Alysandratos and Robert Bagnato \n\nPress ESC or Enter to return to the Main Menu\n";
	return title + content;
}
