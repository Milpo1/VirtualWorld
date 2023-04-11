#include "Antelope.h"
Antelope::Antelope(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::ANTELOPE;
	this->initiative = (int)Initiative::ANTELOPE;
	this->type = Organisms::ANTELOPE;
	this->flag = Flag::ADULT;
}

void Antelope::draw() {
	std::cout << (char)this->type;
}

void Antelope::action() {
	Point source = this->coords;
	Point dest = this->worldPtr->getAvaibleField(source, ALLOW_TAKEN_FIELDS);
	if (chooseRand(0, 1)) {
		dest =((dest - source) * 2) + source;
	}
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}

void Antelope::collision(Fight* fight) {
	this->mating(fight);
	if (chooseRand(0, 1)) {
		fight->setWinner(Fight::TIE);
		Point avaibleField = this->worldPtr->getAvaibleField(this->coords, FORBID_TAKEN_FIELDS);
		if (this->worldPtr->isValid(avaibleField)) {
			this->worldPtr->moveInstance(this->coords, avaibleField);
		}
		return;
	}
	Fight::Side side = fight->getSide(this);
	fight->addStrenght(side, this->strength);
}
