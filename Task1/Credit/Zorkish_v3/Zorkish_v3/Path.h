#pragma once
#include <map>
#include "Location.h"

class Location; // forward declaration

class Path
{
public:
	Path();
	Path(Location* location1, Location* location2, std::string directionL1, std::string directionL2);
	~Path();
	Location* GoThrough(Location* currentLoc);
private:
	std::map<Location*, Location*> _connectedLocations;
};

