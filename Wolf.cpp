#include "Wolf.h"
Wolf::Wolf(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = 9;
	this->initiative = 5;
}
void Wolf::draw() {
	// TODO: Add your implementation code here.
}
