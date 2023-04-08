#include "Animal.h"
#include "World.h"

void Animal::action() {
	Point source = this->coords;
	Point vectors[NO_DIR_VECTORS];
	int avaibleFields = 0;
	for (int i = 0; i < 4; i++) {
		if (this->worldPtr->isValid(source + this->worldPtr->dirVectors[i])) {
			vectors[avaibleFields++] = this->worldPtr->dirVectors[i];
		}
	}
	Point dest = source + vectors[intRandRange(0, avaibleFields - 1)];
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
