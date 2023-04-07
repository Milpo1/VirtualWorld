#include "World.h"
#include <iostream>
using namespace std;
World::World(int n, int m) {
	this->n = n;
	this->m = m;

	this->grid = new Organism * *[m];
	for (int i = 0; i < m; i++) {
		this->grid[i] = new Organism * [n];
	}
}

bool World::isValid(Point& point) {
	int x = point.getX(), y = point.getY();
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}

Grid World::getGrid() {
	return this->grid;
}

Organism* World::getInstanceAt(Point& point) {
	if (!this->isValid(point)) return nullptr;
	return this->grid[point.getX()][point.getY()];
}

void World::setInstanceAt(Organism* organism, Point& point)
{
	if (!this->isValid(point) || organism == nullptr) return;
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
	this->organisms.add(ptr);
}

int World::moveInstance(Point& source, Point& dest)
{
	if (!isValid(dest)) return;
	Organism* instanceAtSource = getInstanceAt(source);
	Organism* instanceAtDest = getInstanceAt(dest);
	if (instanceAtDest == nullptr) {
		instanceAtDest = instanceAtSource;
		instanceAtSource = nullptr;
	}
}



World::~World() {
	for (int i = 0; i < m; i++) {
		delete[] this->grid[i];
	}
	delete[] this->grid;
}