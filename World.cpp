#include "World.h"
#include <iostream>
using namespace std;

void error(const char* message) {
	cout << "ERROR: " << message << endl;
}

World::World(int n, int m) {
	this->n = n;
	this->m = m;

	this->grid = new Organism * *[n];
	for (int i = 0; i < n; i++) {
		this->grid[i] = new Organism * [m];
		for (int j = 0; j < m; j++) this->grid[i][j] = nullptr;
	}
	Point tempdirVectors[] = { Point(0,1), Point(0,-1), Point(-1,0), Point(1,0) };
	this->dirVectors = new Point[NO_DIR_VECTORS];
	for (int i = 0; i < NO_DIR_VECTORS; i++) {
		dirVectors[i] = tempdirVectors[i];
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
	if (this->grid == nullptr) return error("Empty grid pointer");
	Organism* ptr = this->organisms.getHead();
	if (ptr == nullptr) return error("Empty organism list");
	while (ptr != nullptr) {
		ptr->action();
		ptr = ptr->next;
	}
}

void World::drawWorld() {
	if (this->grid == nullptr) return error("Empty grid pointer");
	cout << endl;
	for (int i = 0; i < this->m + 2; i++) cout << HOR_BORDER;
	cout << endl;
	for (int i = 0; i < this->n; i++) {
		cout << VER_BORDER;
		for (int j = 0; j < this->m; j++) {
			Organism* instance = this->grid[i][j];
			if (instance == nullptr) {
				cout << WORLD_EMPTY;
				continue;
			}
			instance->draw();
		}
		cout << VER_BORDER;
		cout << endl;
	}
	for (int i = 0; i < this->m + 2; i++) cout << HOR_BORDER;
	cout << endl;
}

Organism* World::instanceCreate(Organisms type, int x, int y) {
	Point point(x, y);
	Organism* ptr = nullptr;
	switch (type) {
	case Organisms::HUMAN:
		ptr = new Human(this, point);
		break;
	default:
		break;
	}
	if (ptr == nullptr) return nullptr;
	this->setInstanceAt(point, ptr);
	this->organisms.add(ptr);
	return ptr;
}

Response World::moveInstance(Organism* instanceAtSource, Organism* instanceAtDest) {


	return Response::MOVED;
}

Response World::moveInstance(Point source, Point dest) {
	if (!isValid(dest) || !isValid(source)) return Response::POINT_INVALID;
	Organism* instanceAtSource = getInstanceAt(source);
	Organism* instanceAtDest = getInstanceAt(dest);
	if (instanceAtSource == nullptr) return Response::NULL_SOURCE;
	if (instanceAtDest != nullptr) return Response::COLLISION;
	instanceAtSource->coords = dest;
	setInstanceAt(dest, instanceAtSource);
	setInstanceAt(source, nullptr);
	
	cout << "Organism " << getNameByType(instanceAtSource->getType())
		<< " moved from " << source << " to " << dest << endl;
	return Response::MOVED;
}

Response World::collideInstances(Point source, Point dest) {
	if (!isValid(dest) || !isValid(source)) return Response::POINT_INVALID;
	Organism* instanceAtSource = getInstanceAt(source);
	Organism* instanceAtDest = getInstanceAt(dest);
	if (instanceAtSource == nullptr || instanceAtDest == nullptr) return Response::NO_COLLISION;

	Fight fight(instanceAtSource, instanceAtDest);
	instanceAtSource->collision(&fight);
	instanceAtDest->collision(&fight);
	this->killInstance(fight.getLoser());
	this->moveInstance(instanceAtSource,instanceAtDest);

	return Response::COLLIDED;
}

void World::killInstance(Organism* instance) {
	this->setInstanceAt(instance->coords, nullptr);
	this->organisms.deleteNode(instance);
}

World::~World() {
	delete[] dirVectors;
	for (int i = 0; i < this->n; i++) {
		delete[] this->grid[i];
	}
	delete[] this->grid;
}