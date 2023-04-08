#include "Sheep.h"

Sheep::Sheep(World* worldPtr, Point& coords)
{
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = 4;
	this->initiative = 4;
	this->type = Organisms::SHEEP;
}
void Sheep::draw()
{
	std::cout << (char)this->type;
}