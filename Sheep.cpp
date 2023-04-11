#include "Sheep.h"

Sheep::Sheep(World* worldPtr, Point& coords)
{
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::SHEEP;
	this->initiative = (int)Initiative::SHEEP;
	this->type = Organisms::SHEEP;
	this->flag = Flag::ADULT;
}
void Sheep::draw()
{
	std::cout << (char)this->type;
}