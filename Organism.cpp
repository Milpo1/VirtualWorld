#include "Organism.h"

Organisms Organism::getType() const {
	return this->type;
}

Point& Organism::getCoords() {
	return this->coords;
}

int Organism::getStrength() const {
	return this->strength;
}

int Organism::getInitiative() const {
	return this->initiative;
}

void Organism::setStrength(int strength)  {
	this->strength = strength;
}

void OrganismList::add(Organism* organism) {
	if (organism == nullptr) return;
	organism->next = nullptr;
	organism->prev = nullptr;
	Organism* ptr = this->head;
	if (ptr == nullptr) {
		this->head = organism;
		size++;
		return;
	}
	if (ptr->getInitiative() < organism->getInitiative()) {
		this->insertAtPrev(ptr, organism);
		return;
	}
	while (ptr->next != nullptr) {
		if (ptr->next->getInitiative() < organism->getInitiative()) {
			this->insertAtNext(ptr,organism);
			return;
		}
		ptr = ptr->next;
	}
	ptr->next = organism;
	ptr->next->prev = ptr;
	this->size++;
}

OrganismList::OrganismList() {
	this->size = 0;
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

Organism* OrganismList::getHead() const {
	return this->head;
}

Organism* OrganismList::getTail() const {
	Organism* ptr = this->head;
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	return ptr;
}

void OrganismList::empty(){
	Organism* ptr = this->head, * nextPtr = nullptr;
	while (ptr != nullptr) {
		nextPtr = ptr->next;
		delete ptr;
		ptr = nextPtr;
	}
	this->head = nullptr;
}

void OrganismList::deleteNode(Organism* organism)
{
	if (this->head == organism) {
		this->head = organism->next;
		this->head->prev = nullptr;
	}
	if (organism->next != nullptr) organism->next->prev = organism->prev;
	if (organism->prev != nullptr) organism->prev->next = organism->next;
	delete organism;
	this->size--;
}

void OrganismList::insertAtPrev(Organism* at, Organism* toBeInserted) {
	if (at == nullptr || toBeInserted == nullptr) return;
	toBeInserted->next = nullptr;
	toBeInserted->prev = nullptr;
	if (at->prev == nullptr) {
		at->prev = toBeInserted;
		this->head = toBeInserted;
		toBeInserted->next = at;
		size++;
		return;
	}
	toBeInserted->prev = at->prev;
	toBeInserted->next = at;
	at->prev->next = toBeInserted;
	at->prev = toBeInserted;
	this->size++;
}
void OrganismList::insertAtNext(Organism* at, Organism* toBeInserted) {
	if (at == nullptr || toBeInserted == nullptr) return;
	toBeInserted->next = nullptr;
	toBeInserted->prev = nullptr;
	if (at->next == nullptr) {
		at->next = toBeInserted;
		toBeInserted->prev = at;
		size++;
		return;
	}
	toBeInserted->next = at->next;
	toBeInserted->prev = at;
	at->next->prev = toBeInserted;
	at->next = toBeInserted;
	this->size++;
}

Fight::Fight(Organism* attacker, Organism* victim) {
	this->netStrength = 0;
	this->winner = Fight::NEITHER;
	this->participant[ATTACKER] = attacker;
	this->participant[VICTIM] = victim;
}

Fight::Side Fight::getSide(Organism* organism) const {
	if (this->participant[ATTACKER] == organism) return ATTACKER;
	if (this->participant[VICTIM] == organism) return VICTIM;

	return NEITHER;
}

Fight::Side Fight::getWinnerSide() const {
	if (this->winner != NEITHER) return this->winner;
	if (netStrength >= 0) return ATTACKER;

	return VICTIM;
}

Organism* Fight::getWinner() const {
	if (this->winner == TIE) return nullptr;
	return this->participant[getWinnerSide()];
}

Organism* Fight::getLoser() const {
	return this->getEnemy(getWinner());
}

Organism* Fight::getEnemy(Organism* participant) const {
	if (participant == nullptr) return nullptr;
	if (!this->isComplete()) return nullptr;

	return this->participant[(getSide(participant) + 1) % TIE];
}

void Fight::addStrenght(Side side, int strength) {
	if (this->participant[side] == nullptr) return;
	if (side == ATTACKER) this->netStrength += strength;
	if (side == VICTIM) this->netStrength -= strength;
}

void Fight::setWinner(Side side) {
	this->winner = side;
}

bool Fight::isComplete() const {
	if (this->participant[ATTACKER] == nullptr || this->participant[VICTIM] == nullptr) return false;

	return true;
}

bool Fight::isReady() const {
	return (this->winner == TIE && this->isComplete());
}
