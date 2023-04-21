#include "World.h"
using namespace std;

void error(const char* message) {
	cout << "ERROR: " << message << endl;
}
void gotoxy(int a, int b)
{
	COORD coordinates;
	coordinates.X = a;
	coordinates.Y = b; 

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}
World::World(int n, int m) {
	this->n = n;
	this->m = m;
	this->turnCounter = 0;
	this->input = 0;

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

void World::setInput(int c) {
	this->input = c;
}

int World::getInput() {
	return this->input;
}

void World::makeTurn() {
	gotoxy(REPORT_DRAW_X, REPORT_DRAW_Y);
	for (int j = 0; j < this->m;j ++) {
		for (int i = 0; i < WORLD_DRAW_X; i++)
		{
			cout << ' ';
		}
		cout << endl;
	}
	gotoxy(REPORT_DRAW_X, REPORT_DRAW_Y);
	this->turnCounter++;
	if (this->grid == nullptr) return error(EMPTY_GRID_ERR);
	Organism* ptr = this->organisms.getHead();
	if (ptr == nullptr) return error(EMPTY_ORG_LIST);
	while (ptr != nullptr) {
		if (ptr->flag == Flag::NEWBORN) {
			ptr->flag = Flag::ADULT;
		}
		else if (ptr->flag != Flag::EMPTY) ptr->action();
		Organism* prev = ptr;
		ptr = ptr->next;
		if (prev != nullptr) {
			if (prev->flag == Flag::EMPTY) {
				this->organisms.deleteNode(prev);
			}
		}
	}	
}

void World::drawWorld() {
	if (this->grid == nullptr) return error(EMPTY_GRID_ERR);
	gotoxy(WORLD_DRAW_X,WORLD_DRAW_Y);
	cout << "Turn " << this->turnCounter;
	gotoxy(WORLD_DRAW_X, WORLD_DRAW_Y + 1);
	for (int i = 0; i < this->n + 2; i++) cout << HOR_BORDER;
	for (int i = 0; i < this->m; i++) {
		gotoxy(WORLD_DRAW_X, WORLD_DRAW_Y + 2 + i);
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
	}
	gotoxy(WORLD_DRAW_X, WORLD_DRAW_Y + m + 2);
	for (int i = 0; i < this->n + 2; i++) cout << HOR_BORDER;
	gotoxy(WORLD_DRAW_X, WORLD_DRAW_Y + 3 + this->m);
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
	if (!this->isValid(point)) return nullptr;
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

void World::saveGame() {
	cout << "Name your save file: ";
	char buffer[2*BUFFER_SIZE];
	scanf_s("%s",buffer, 2 * BUFFER_SIZE-1);
	sprintf_s(buffer, "%s.bin", buffer);
	fstream file;
	file.open(buffer, fstream::out);
	file.write((char*)&this->n, sizeof(int));
	file.write((char*)&this->m, sizeof(int));
	file.write((char*)&this->turnCounter, sizeof(int));
	file.write((char*)&this->organisms.size, sizeof(int));
	Organism* ptr = this->organisms.getHead();
	while (ptr != nullptr) {
		file.write((char*)ptr, sizeof(Organism));
		ptr = ptr->next;
	}

	file.close();
}

void World::loadGame() {
	cout << "Load save named: ";
	char buffer[2 * BUFFER_SIZE];
	scanf_s("%s", buffer, 2 * BUFFER_SIZE - 1);
	sprintf_s(buffer, "%s.bin", buffer);
	ifstream file;
	for (int i = 0; i < this->n; i++) {
		delete[] this->grid[i];
	}
	delete[] this->grid;

	this->organisms.empty();
	
	file.open(buffer, ios::in);
	if (!file.good()) {
		file.close();
		return;
	}
	file.read((char*)&this->n, sizeof(int));
	file.read((char*)&this->m, sizeof(int));
	file.read((char*)&this->turnCounter, sizeof(int));
	file.read((char*)&this->organisms.size, sizeof(int));

	this->grid = new Organism * *[n];
	for (int i = 0; i < n; i++) {
		this->grid[i] = new Organism * [m];
		for (int j = 0; j < m; j++) this->grid[i][j] = nullptr;
	}

	Point dummyPoint;
	int size = this->organisms.size;
	for (int i = 0; i < size; i++) {
		Organism* readOrganism = new Antelope(this,dummyPoint);
		file.read((char*)readOrganism, sizeof(Organism));
		readOrganism->worldPtr = this;
		this->organisms.add(readOrganism);
		this->setInstanceAt(readOrganism->coords, readOrganism);
	}
	this->organisms.size = size;

	file.close();
	this->drawWorld();
}

Organism* World::getClosestInstanceByType(Point source, Organisms type) {
	Organism* result = nullptr;
	Organism* ptr = this->organisms.getTail();
	int destInitiative = getInitiativeByType(type);
	int minDistance = this->n + this->m;
	while (ptr != nullptr) {
		if (ptr->getInitiative() > destInitiative) break;
		if (ptr->getType() == type) {
			int distance = pointDistance(ptr->getCoords(), source);
			if (distance < minDistance) {
				minDistance = distance;
				result = ptr;
			}
		}
		ptr = ptr->prev;
	}
	return result;
}
