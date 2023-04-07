#include "Human.h"

Human::Human(World* worldPtr, Point& coords)
{
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = 5;
	this->initiative = 4;
}

void Human::draw()
{
}
