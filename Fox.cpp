#include "Fox.h"
#include "World.h"

Fox::Fox(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::FOX;
	this->initiative = (int)Initiative::FOX;
	this->type = Organisms::FOX;
	this->flag = Flag::ADULT;
}

void Fox::draw() {
	std::cout << (char)this->type;
}

void Fox::action() {
	Point source = this->coords;
	Point vectors[NO_DIR_VECTORS];
	Point dest;
	int avaibleFields = 0;
	for (int i = 0; i < NO_DIR_VECTORS; i++) {
		dest = source + this->worldPtr->dirVectors[i];
		if (this->worldPtr->isValid(dest)) {
			Organism* instance = this->worldPtr->getInstanceAt(dest);
			if (instance != nullptr && instance->getStrength() > this->strength) continue;
			vectors[avaibleFields++] = this->worldPtr->dirVectors[i];
		}
	}
	if (avaibleFields == 0) {
		return;
	}
	dest = source + vectors[intRandRange(0, avaibleFields - 1)];
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}
