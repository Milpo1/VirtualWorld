#include "Cybersheep.h"
#include "World.h"

Cybersheep::Cybersheep(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::CYBER_SHEEP;
	this->initiative = (int)Initiative::CYBER_SHEEP;
	this->type = Organisms::CYBER_SHEEP;
	this->flag = Flag::ADULT;
}

void Cybersheep::draw() {
	std::cout << (char)this->type;
}

void Cybersheep::action() {
	Point source = this->coords;
	Point dest, vector;
	Organism* instance = this->worldPtr->getClosestInstanceByType(this->coords, Organisms::SOSNOWSKY);
	if (instance == nullptr) {
		Animal::action();
		return;
	}
	int difX = instance->getCoords().getX() - source.getX();
	int difY = instance->getCoords().getY() - source.getY();
	if (abs(difX) >= abs(difY)) {
		vector = Point(1, 0) * sign(difX);
	}
	else {
		vector = Point(0, 1) * sign(difY);
	}
	dest = source + vector;
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}

void Cybersheep::collision(Fight* fight) {
	this->mating(fight);
	Fight::Side side = fight->getSide(this);
	Organism* enemy = fight->getEnemy(this);
	if (enemy->getType() == Organisms::SOSNOWSKY) {
		fight->setWinner(side);
	}
	fight->addStrenght(side, this->strength);
}