#include "Animal.h"
#include "World.h"

void Animal::action() {
	Point source = this->coords;
	Point dest = this->worldPtr->getAvaibleField(source, ALLOW_TAKEN_FIELDS);
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}

void Animal::collision(Fight* fight) {
	if (this->type == fight->getEnemy(this)->getType()) {
		if (fight->getWinnerSide() == Fight::TIE) {
			Point avaibleField = this->worldPtr->getAvaibleField(this->coords, FORBID_TAKEN_FIELDS);
			if (!this->worldPtr->isValid(avaibleField)) {
				avaibleField = this->worldPtr->getAvaibleField(fight->getEnemy(this)->getCoords(), false);
				if (!this->worldPtr->isValid(avaibleField)) {
					return;
				}
			}
			Organism* newBorn = this->worldPtr->instanceCreate(this->type, avaibleField.getX(), avaibleField.getY(), Flag::NEWBORN);
			std::cout << MATING_REPORT;
			return;
		}
		fight->setWinner(Fight::TIE);
		return;
	}
	Fight::Side side = fight->getSide(this);
	fight->addStrenght(side, this->strength);
}
