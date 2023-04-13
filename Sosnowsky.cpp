#include "Sosnowsky.h"
#include "World.h"

Sosnowsky::Sosnowsky(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::SOSNOWSKY;
	this->initiative = (int)Initiative::SOSNOWSKY;
	this->type = Organisms::SOSNOWSKY;
	this->flag = Flag::ADULT;
}

void Sosnowsky::draw() {
	std::cout << (char)this->type;
}

void Sosnowsky::action() {
	Organism* instances[NO_DIR_VECTORS];
	Point dest;
	int noOfInstances = 0;
	for (int i = 0; i < NO_DIR_VECTORS; i++) {
		dest = this->coords + this->worldPtr->dirVectors[i];
		Organism* instance = this->worldPtr->getInstanceAt(dest);
		if (instance == nullptr) continue;
		if (instance->getInitiative() == 0) continue;
		if (instance->getType() == Organisms::CYBER_SHEEP) continue;
		instances[noOfInstances++] = instance;
	}
	for (int i = 0; i < noOfInstances; i++) {
		this->worldPtr->killInstance(instances[i]);
	}
	this->sow();
}

void Sosnowsky::collision(Fight* fight) {
	Organism* enemy = fight->getEnemy(this);
	if (enemy->getType() == Organisms::CYBER_SHEEP) return;
	fight->setWinner(fight->getSide(this));
}