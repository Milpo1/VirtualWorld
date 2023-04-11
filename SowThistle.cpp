#include "SowThistle.h"
#include "World.h"
SowThistle::SowThistle(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::SOW_THISTLE;
	this->initiative = (int)Initiative::SOW_THISTLE;
	this->type = Organisms::SOW_THISTLE;
	this->flag = Flag::ADULT;
}

void SowThistle::draw() {
	std::cout << (char)this->type;
}
void SowThistle::action() {
	for (int i = 0; i < 3; i++) {
		Point avaibleField = this->worldPtr->getAvaibleField(this->coords, FORBID_TAKEN_FIELDS);
		if (this->worldPtr->isValid(avaibleField)) {
			this->worldPtr->instanceCreate(this->type, avaibleField.getX(), avaibleField.getY(), Flag::NEWBORN);
		}
		else return;
	}
}