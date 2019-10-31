#include "Item.h"

using namespace std;

Item::Item()
{
}

Item::Item(vector<string> idents, string name, string desc):GameObject(idents, name, desc)
{
}

Item::~Item()
{
}
