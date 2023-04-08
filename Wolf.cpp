#include "Wolf.h"
Wolf::Wolf(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = 9;
	this->initiative = 5;
	this->type = Organisms::WOLF;
}
void Wolf::draw() {
	std::cout << (char)this->type;
}
