#include "Organism.h"

Organisms Organism::getType()
{
	return this->type;
}

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
