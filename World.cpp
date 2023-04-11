#include "World.h"
#include <iostream>
using namespace std;

void error(const char* message) {
	cout << "ERROR: " << message << endl;
}

World::World(int n, int m) {
	this->n = n;
	this->m = m;
	this->turnCounter = 0;

	this->grid = new Organism **[n];
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

void World::makeTurn(int c) {
	this->input = c;
	this->turnCounter++;
	if (this->grid == nullptr) return error(EMPTY_GRID_ERR);
	Organism* ptr = this->organisms.getHead();
	if (ptr == nullptr) return error(EMPTY_ORG_LIST);
	while (ptr != nullptr) {
		if (ptr->prev != nullptr) {
			if (ptr->prev->flag == Flag::EMPTY) {
				this->organisms.deleteNode(ptr->prev);
			}
		}
		if (ptr->flag == Flag::NEWBORN) {
			ptr->flag = Flag::ADULT;
		}
		else if (ptr->flag != Flag::EMPTY) ptr->action();
		ptr = ptr->next;
	}	
}

void World::drawWorld() {
	if (this->grid == nullptr) return error(EMPTY_GRID_ERR);
	cout << endl;
	cout << "Turn " << this->turnCounter << endl;
	for (int i = 0; i < this->n + 2; i++) cout << HOR_BORDER;
	cout << endl;
	for (int i = 0; i < this->m; i++) {
		cout << VER_BORDER;
		for (int j = 0; j < this->n; j++) {
			Organism* instance = this->grid[j][i];
			if (instance == nullptr) {
				cout << WORLD_EMPTY;
				continue;
			}
			instance->draw();
		}
		cout << VER_BORDER;
		cout << endl;
	}
	for (int i = 0; i < this->n + 2; i++) cout << HOR_BORDER;
	cout << endl;
}

Point World::getAvaibleField(Point& source, bool allowTaken) {
	Point vectors[NO_DIR_VECTORS];
	Point dest;
	int avaibleFields = 0;
	for (int i = 0; i < 4; i++) {
		dest = source + this->dirVectors[i];
		if (this->isValid(dest) && (allowTaken || this->getInstanceAt(dest) == nullptr)) {
			vectors[avaibleFields++] = this->dirVectors[i];
		}
	}
	if (avaibleFields == 0) {
		return Point();
	}
	dest = source + vectors[intRandRange(0, avaibleFields - 1)];
	return dest;
}

Organism* World::instanceCreate(Organisms type, int x, int y, Flag flag) {
	Point point(x, y);
	Organism* ptr = nullptr;
	switch (type) {
	case Organisms::HUMAN:
		ptr = new Human(this, point);
		break;
	case Organisms::WOLF:
		ptr = new Wolf(this, point);
		break;
	case Organisms::SHEEP:
		ptr = new Sheep(this, point);
		break;
	case Organisms::FOX:
		ptr = new Fox(this, point);
		break;
	case Organisms::TURTLE:
		ptr = new Turtle(this, point);
		break;
	case Organisms::ANTELOPE:
		ptr = new Antelope(this, point);
		break;
	case Organisms::CYBER_SHEEP:
		ptr = new Cybersheep(this, point);
		break;
	case Organisms::GRASS:
		ptr = new Grass(this, point);
		break;
	case Organisms::SOW_THISTLE:
		ptr = new SowThistle(this, point);
		break;
	case Organisms::GUARANA:
		ptr = new Guarana(this, point);
		break;
	case Organisms::BELLADONNA:
		ptr = new Belladonna(this, point);
		break;
	case Organisms::SOSNOWSKY:
		ptr = new Sosnowsky(this, point);
		break;
	default:
		break;
	}
	if (ptr == nullptr) return nullptr;
	if (this->getInstanceAt(point) != nullptr) return nullptr;
	this->setInstanceAt(point, ptr);
	this->organisms.add(ptr);
	ptr->flag = flag;
	return ptr;
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
	
	//cout << MOVE_REPORT;
	return Response::MOVED;
}

Response World::collideInstances(Point source, Point dest) {
	if (!isValid(dest) || !isValid(source)) return Response::POINT_INVALID;
	Organism* instanceAtSource = getInstanceAt(source);
	Organism* instanceAtDest = getInstanceAt(dest);
	if (instanceAtSource == nullptr || instanceAtDest == nullptr) return Response::NO_COLLISION;

	Fight fight(instanceAtSource, instanceAtDest);
	//cout << ATTACK_REPORT;
	instanceAtSource->collision(&fight);
	instanceAtDest->collision(&fight);
	Organism* loser = fight.getLoser();
	if (loser == nullptr) {
		return Response::COLLIDED;
	}
	this->killInstance(loser);
	this->moveInstance(source,dest);

	return Response::COLLIDED;
}

void World::killInstance(Organism* instance) {
	this->setInstanceAt(instance->coords, nullptr);
	instance->killMsg();
	instance->flag = Flag::EMPTY;
	//this->organisms.deleteNode(instance);
}

World::~World() {
	delete[] dirVectors;
	for (int i = 0; i < this->n; i++) {
		delete[] this->grid[i];
	}
	delete[] this->grid;
}

Organism* World::getClosestInstanceByType(Point source, Organisms type) {
	Organism* result = nullptr;
	Organism* ptr = this->organisms.getHead();
	int destInitiative = getInitiativeByType(type);
	int minDistance = this->n + this->m;
	while (ptr != nullptr) {
		if (ptr->getInitiative() > destInitiative) break;
		if (ptr->getType() != type) continue;
		int distance = pointDistance(ptr->getCoords(), source);
		if (distance > minDistance) continue;
		minDistance = distance;
		result = ptr;
	}
	return result;
}
