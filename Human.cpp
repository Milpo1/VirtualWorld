#include "Human.h"
#include "World.h"
#include <iostream>
Human::Human(World* worldPtr, Point& coords)
{
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->specialPowerCooldown = 0;
	this->strength = (int)Strength::HUMAN;
	this->initiative = (int)Initiative::HUMAN;
	this->type = Organisms::HUMAN;
	this->flag = Flag::ADULT;
}

void Human::action() {
	if (this->worldPtr->specialPowerCooldown == 0 && this->worldPtr->input == ' ') {
		std::cout << HUMAN_POWER_ACTIVATE;
		this->worldPtr->specialPowerCooldown = SPECIALPOWER_COOLDOWN;

	}
	if (this->worldPtr->specialPowerCooldown > SPECIALPOWER_THRESHOLD) {
		std::cout << HUMAN_POWER_REPORT;
		Organism* instances[NO_DIR_VECTORS];
		Point dest;
		int noOfInstances = 0;
		for (int i = 0; i < NO_DIR_VECTORS; i++) {
			dest = this->coords + this->worldPtr->dirVectors[i];
			Organism* instance = this->worldPtr->getInstanceAt(dest);
			if (instance == nullptr) continue;
			instances[noOfInstances++] = instance;
		}
		for (int i = 0; i < noOfInstances; i++) {
			this->worldPtr->killInstance(instances[i]);
		}
	}
	if (this->worldPtr->specialPowerCooldown > 0) this->worldPtr->specialPowerCooldown--;
	Point source = this->coords;
	Point dest, vector;
	switch (this->worldPtr->input) {
	case KEY_UP:
		vector = Point(0, -1);
		break;
	case KEY_DOWN:
		vector = Point(0, 1);
		break;
	case KEY_LEFT:
		vector = Point(-1, 0);
		break;
	case KEY_RIGHT:
		vector = Point(1, 0);
		break;
	default:
		return;
	}
	dest = source + vector;
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}

void Human::collision(Fight* fight) {
	this->mating(fight);
	Fight::Side side = fight->getSide(this);
	fight->addStrenght(side, this->strength);
}

void Human::draw()
{
	std::cout << (char)this->type;
}







