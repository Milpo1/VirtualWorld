#include "Turtle.h"
#include "World.h"

Turtle::Turtle(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = 2;
	this->initiative = 1;
	this->type = Organisms::TURTLE;
	this->flag = Flag::ADULT;
}
void Turtle::draw() {
	std::cout << (char)this->type;
}

void Turtle::action() {
	if (intRandRange(0, 3) < 3) return;
	Point source = this->coords;
	Point dest = this->worldPtr->getAvaibleField(source, ALLOW_TAKEN_FIELDS);
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}

void Turtle::collision(Fight* fight) {
	this->mating(fight);
	if (fight->getSide(this) == Fight::VICTIM && fight->getEnemy(this)->getStrength() < 5) {
		fight->setWinner(Fight::TIE);
		return;
	}
	Fight::Side side = fight->getSide(this);
	fight->addStrenght(side, this->strength);
}
