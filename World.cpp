#include "World.h"
#include <iostream>
using namespace std;
World::World(int n, int m) {
	this->n = n;
	this->m = m;

	this->grid = new Organism * *[n];
	for (int i = 0; i < n; i++) {
		this->grid[i] = new Organism * [m];
		for (int j = 0; j < m; j++) this->grid[i][j] = nullptr;
	}
}

bool World::isValid(Point point) {
	int x = point.getX(), y = point.getY();
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}

Grid World::getGrid() {
	return this->grid;
}

Organism* World::getInstanceAt(Point point) {
	if (!this->isValid(point)) return nullptr;
	return this->grid[point.getX()][point.getY()];
}

void World::setInstanceAt(Point point, Organism* organism)
{
	if (!this->isValid(point)) return;
	this->grid[point.getX()][point.getY()] = organism;
}

void World::makeTurn() {
}

void World::drawWorld() {
}

void World::instanceCreate(Organisms type, int x, int y) {
	Point point(x, y);
	Organism* ptr = nullptr;
	switch (type) {
	case Organisms::HUMAN:
		ptr = new Human(this, point);
		break;
	default:
		break;
	}
	if (ptr == nullptr) return;
	this->setInstanceAt(point, ptr);
	this->organisms.add(ptr);
}
Response World::moveInstance(Organism* instanceAtSource, Organism* instanceAtDest) {
	if (instanceAtSource == nullptr) return Response::NULL_SOURCE;
	if (instanceAtDest != nullptr) return Response::COLLISION;
	cout << "Organism " << getNameByType(instanceAtSource->getType())
		<< " moved from " << instanceAtSource->coords << " to " << instanceAtDest->coords << endl;
	setInstanceAt(instanceAtDest->coords, instanceAtSource);
	setInstanceAt(instanceAtSource->coords, nullptr);
	return Response::MOVED;
}
Response World::moveInstance(Point source, Point dest) {
	if (!isValid(dest) || !isValid(source)) return Response::POINT_INVALID;
	Organism* instanceAtSource = getInstanceAt(source);
	Organism* instanceAtDest = getInstanceAt(dest);
	return moveInstance(instanceAtDest, instanceAtDest);
}

Response World::collideInstances(Point source, Point dest) {
	if (!isValid(dest) || !isValid(source)) return Response::POINT_INVALID;
	Organism* instanceAtSource = getInstanceAt(source);
	Organism* instanceAtDest = getInstanceAt(dest);
	if (instanceAtSource == nullptr || instanceAtDest == nullptr) return Response::NO_COLLISION;
	Fight fight(instanceAtSource, instanceAtDest);
	instanceAtSource->collision(&fight);
	instanceAtDest->collision(&fight);
	this->kill(fight.getLoser());
	this->moveInstance(instanceAtSource,instanceAtDest);
	return Response();
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
	return this->participant[getWinnerSide()];
}
Organism* Fight::getLoser() const {
	return this->participant[(getWinnerSide()+1)%TIE];
}
World::~World() {
	for (int i = 0; i < this->n; i++) {
		delete[] this->grid[i];
	}
	delete[] this->grid;
}

void Fight::addStrenght(Side side, int strength) {
	if (this->participant[side] == nullptr) return;
	if (side == ATTACKER) this->netStrength += strength;
	if (side == VICTIM) this->netStrength -= strength;
}
bool Fight::isComplete() {
	if (this->participant[ATTACKER] == nullptr || this->participant[VICTIM] == nullptr) return false;
	return true;
}

