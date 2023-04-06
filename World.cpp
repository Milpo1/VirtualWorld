#include "World.h"
World::World(int n, int m) {
	this->n = n;
	this->m = m;

	this->grid = new Organism** [m];
	for (int i = 0; i < m; i++) {
		this->grid[i] = new Organism*[n];
	}
}

Organism*** World::getGrid()
{
	return this->grid;
}

Organism* World::getGridPtr(int x, int y)
{
	return this->grid[x][y];
}

void World::makeTurn() {
}

void World::drawWorld() {
}

void World::instanceCreate(Organisms type, int x, int y) {
	Organism* ptr = getGridPtr(x, y);

}

World::~World() {
	for (int i = 0; i < m; i++) {
		delete[] this->grid[i];
	}
	delete[] this->grid;
}