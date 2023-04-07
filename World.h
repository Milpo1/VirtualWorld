#pragma once
#include "Human.h"
typedef Organism*** Grid;
class World {
	int n, m;
	OrganismList organisms;
	Grid grid;
public:
	World(int n, int m);

	// Getters
	Grid getGrid();
	Organism* getPtrAt(Point& point);

	// Setters

	// Other
	void makeTurn();
	void drawWorld();
	void instanceCreate(Organisms type, int x, int y);
	bool isValid(Point& point);

	~World();
};

