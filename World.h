#pragma once

#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"

typedef Organism*** Grid;
class World {
	int n, m;
	OrganismList organisms;
	Grid grid;
public:
	World(int n, int m);

	// Getters
	Grid getGrid();
	Organism* getInstanceAt(Point point);
	void setInstanceAt(Organism* organism, Point point);

	// Setters

	// Other
	void makeTurn();
	void drawWorld();
	void instanceCreate(Organisms type, int x, int y);
	Response moveInstance(Point source, Point dest);
	bool isValid(Point point);


	~World();
};