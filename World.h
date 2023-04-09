#pragma once

#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Cybersheep.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Guarana.h"
#include "Sosnowsky.h"

#define WORLD_EMPTY '.'
#define HOR_BORDER '|'
#define VER_BORDER '|'
#define NO_DIR_VECTORS 4
#define ALLOW_TAKEN_FIELDS true
#define FORBID_TAKEN_FIELDS false

typedef Organism*** Grid;
class World {
	int n, m;
	OrganismList organisms;
	Grid grid;
public:
	Point* dirVectors;
	World(int n, int m);
	// Getters
	Grid getGrid();

	// Setters

	// Other
	void makeTurn();
	void drawWorld();
	void setInstanceAt(Point point, Organism* organism);
	Organism* getInstanceAt(Point point);
	Organism* instanceCreate(Organisms type, int x, int y, Flag flag = Flag::ADULT);
	Response moveInstance(Point source, Point dest);
	Response collideInstances(Point source, Point dest);
	void killInstance(Organism* instance);
	bool isValid(Point point);
	Point getAvaibleField(Point& source, bool allowTaken);

	~World();
};