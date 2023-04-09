#include "Plant.h"
#include "World.h"
void Plant::action() {
	Point avaibleField = this->worldPtr->getAvaibleField(this->coords, FORBID_TAKEN_FIELDS);
	if (this->worldPtr->isValid(avaibleField)) {
		this->worldPtr->instanceCreate(this->type,avaibleField.getX(),avaibleField.getY(),Flag::NEWBORN);
	}
}

void Plant::collision(Fight* fight) {
	Fight::Side side = fight->getSide(this);
	fight->addStrenght(side, this->strength);
}