#include "Human.h"

Human::Human(World* worldPtr, Point& coords)
{
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::HUMAN;
	this->initiative = (int)Initiative::HUMAN;
	this->type = Organisms::HUMAN;
	this->flag = Flag::ADULT;
}

void Human::action()
{
}

void Human::draw()
{
	std::cout << (char)this->type;
}







