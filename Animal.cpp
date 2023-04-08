#include "Animal.h"
#include "World.h"

void Animal::action() {
	int dx = 0, dy = 0;
	if (chooseRand()) dx = chooseRand(-1, 1);
	else dy = chooseRand(-1, 1);
	Point vector(dx, dy);
	Point source = this->coords;
	Point dest = source + vector;
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}

void Animal::collision(Fight* fight) {
	if (!fight->isComplete()) return;
	Fight::Side side = fight->getSide(this);
	fight->addStrenght(side, this->strength);
}
