#include "Grass.h"
#include "World.h"

Grass::Grass(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::GRASS;
	this->initiative = (int)Initiative::GRASS;
	this->type = Organisms::GRASS;
	this->flag = Flag::ADULT;
}

void Grass::draw() {
	std::cout << (char)this->type;
}