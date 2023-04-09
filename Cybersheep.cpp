#include "Cybersheep.h"
#include "World.h"

Cybersheep::Cybersheep(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = 11;
	this->initiative = 4;
	this->type = Organisms::CYBER_SHEEP;
	this->flag = Flag::ADULT;
}

void Cybersheep::draw()
{
}

void Cybersheep::action()
{
}

void Fox::draw() {
	std::cout << (char)this->type;
}