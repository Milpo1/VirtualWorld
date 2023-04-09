#include "Grass.h"
#include "World.h"

Grass::Grass(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = 0;
	this->initiative = 0;
	this->type = Organisms::GRASS;
	this->flag = Flag::ADULT;
}

void Grass::draw() {
	std::cout << (char)this->type;
}