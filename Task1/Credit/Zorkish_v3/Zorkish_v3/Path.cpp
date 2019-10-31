#include "Path.h"

using namespace std;

Path::Path()
{
}

Path::Path(Location* location1, Location* location2, string directionL1, string directionL2)
{
	_connectedLocations[location1] = location2;
	_connectedLocations[location2] = location1;

	location1->LinkToPath(directionL1, this);
	location2->LinkToPath(directionL2, this);
}

Path::~Path()
{
}

Location* Path::GoThrough(Location* currentLoc)
{
	try
	{
		return _connectedLocations[currentLoc];
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}