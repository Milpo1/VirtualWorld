#pragma once

#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"

#define WORLD_EMPTY ' '
#define HOR_BORDER '|'
#define VER_BORDER '|'
#define NO_DIR_VECTORS 4
typedef Organism*** Grid;
class World {
	int n, m;
	OrganismList organisms;
	Grid grid;
	Organism* getInstanceAt(Point point);
	void setInstanceAt(Point point, Organism* organism);
public:
	Point* dirVectors;
	World(int n, int m);
	// Getters
	Grid getGrid();

	// Setters

	// Other
	void makeTurn();
	void drawWorld();
	Organism* instanceCreate(Organisms type, int x, int y);
	Response moveInstance(Organism* instanceAtSource, Organism* instanceAtDest);
	Response moveInstance(Point source, Point dest);
	Response collideInstances(Point source, Point dest);
	void killInstance(Organism* instance);
	bool isValid(Point point);


	~World();
};