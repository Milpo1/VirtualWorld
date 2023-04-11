#include "Wolf.h"
Wolf::Wolf(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::WOLF;
	this->initiative = (int)Initiative::WOLF;
	this->type = Organisms::WOLF;
	this->flag = Flag::ADULT;
}
void Wolf::draw() {
	std::cout << (char)this->type;
}
