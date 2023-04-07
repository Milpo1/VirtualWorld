#include "Organism.h"

Point::Point() {
	this->x = -1;
	this->y = -1;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::getX()
{
	return this->x;
}

int Point::getY()
{
	return this->y;
}

void Point::setCoords(int x, int y)
{
	if (x != -1) this->x = x;
	if (y != -1) this->y = y;
}

/*Organism::Organism(Organism*** worldPtr, Point coords, int strength, int initiative) {
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = strength;
	this->initiative = initiative;
	this->next = nullptr;
	this->prev = nullptr;
}

Organism::Organism(Organism& organism) {
	*this = organism;
	this->next = nullptr;
	this->prev = nullptr;
}

Organism::~Organism() {
	if (this->next != nullptr) this->next->prev = this->prev;
	if (this->prev != nullptr) this->prev->next = this->next;
	this->worldPtr[this->coords.getX()][this->coords.getY()] = nullptr;
}*/

void OrganismList::add(Organism* organism) {
	if (organism == nullptr) return;
	organism->next = nullptr;
	organism->prev = nullptr;
	Organism* ptr = this->head;
	if (ptr == nullptr) {
		this->head = organism;
		return;
	}
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	ptr->next = organism;
	ptr->next->prev = ptr;
}

OrganismList::OrganismList() {
	this->head = nullptr;
}

OrganismList::~OrganismList() {
	Organism* ptr = this->head, *nextPtr = nullptr;
	while (ptr != nullptr) {
		nextPtr = ptr->next;
		delete ptr;
		ptr = nextPtr;
	}
}
