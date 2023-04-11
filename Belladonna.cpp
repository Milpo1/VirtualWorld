#include "Belladonna.h"
#include "World.h"
Belladonna::Belladonna(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::BELLADONNA;
	this->initiative = (int)Initiative::BELLADONNA;
	this->type = Organisms::BELLADONNA;
	this->flag = Flag::ADULT;
}

void Belladonna::draw() {
	std::cout << (char)this->type;
}

void Belladonna::collision(Fight* fight) {
	Fight::Side side = fight->getSide(this);
	fight->setWinner(side);
	fight->addStrenght(side, this->strength);
}