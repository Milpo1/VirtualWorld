#include "Cybersheep.h"
#include "World.h"

Cybersheep::Cybersheep(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::CYBER_SHEEP;
	this->initiative = (int)Initiative::CYBER_SHEEP;
	this->type = Organisms::CYBER_SHEEP;
	this->flag = Flag::ADULT;
}

void Cybersheep::draw() {
	std::cout << (char)this->type;
}

void Cybersheep::action() {
	this->worldPtr->getClosestInstanceByType(this->coords, Organisms::CYBER_SHEEP);
}