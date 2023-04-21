#include "Plant.h"
#include "World.h"
void Plant::action() {
	this->sow();
}

void Plant::collision(Fight* fight) {
	Fight::Side side = fight->getSide(this);
	fight->addStrenght(side, this->strength);
}

void Plant::sow() {
	if (rand() % MAX_PROB < SOW_CHANCE) {
		Point avaibleField = this->worldPtr->getAvaibleField(this->coords, FORBID_TAKEN_FIELDS);
		if (this->worldPtr->isValid(avaibleField)) {
			this->worldPtr->instanceCreate(this->type, avaibleField.getX(), avaibleField.getY(), Flag::NEWBORN);
			std::cout << GROW_REPORT;
		}
	}
}

void Plant::killMsg() {
	std::cout << EAT_REPORT;
}