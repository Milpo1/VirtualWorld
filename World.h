#pragma once
#include "Organism.h"

class World {
	int n, m;
	OrganismList organisms;
	Organism*** grid;
public:
	World(int n, int m);

	// Getters
	Organism*** getGrid(); 
	Organism* getGridPtr(int x, int y);

	// Setters

	// Other
	void makeTurn();
	void drawWorld();
	void instanceCreate(Organisms type, int x, int y);

	~World();
};

