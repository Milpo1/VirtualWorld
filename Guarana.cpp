#include "Guarana.h"
#include "World.h"
Guarana::Guarana(World* worldPtr, Point& coords) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::GUARANA;
	this->initiative = (int)Initiative::GUARANA;
	this->type = Organisms::GUARANA;
	this->flag = Flag::ADULT;
}

void Guarana::draw() {
	std::cout << (char)this->type;
}
void Guarana::collision(Fight* fight) {
	Organism* enemy = fight->getEnemy(this);
	enemy->setStrength(enemy->getStrength() + 3);
}