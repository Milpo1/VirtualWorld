#pragma once

#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"

typedef Organism*** Grid;
class World {
	int n, m;
	OrganismList organisms;
	Grid grid;
	Organism* getInstanceAt(Point point);
	void setInstanceAt(Point point, Organism* organism);
public:
	World(int n, int m);
	// Getters
	Grid getGrid();

	// Setters

	// Other
	void makeTurn();
	void drawWorld();
	void instanceCreate(Organisms type, int x, int y);
	Response moveInstance(Organism* instanceAtSource, Organism* instanceAtDest);
	Response moveInstance(Point source, Point dest);
	Response collideInstances(Point source, Point dest);
	bool isValid(Point point);


	~World();
};

class Fight {
	enum Side {
		ATTACKER,
		VICTIM,
		TIE,
		NEITHER
	};
	Side winner;
	Organism* participant[TIE];
	int netStrength;
public:
	Fight(Organism* attacker, Organism* victim);
	Side getSide(Organism* participant) const;
	Side getWinnerSide() const;
	Organism* getWinner() const;
	Organism* getLoser() const;
	void addStrenght(Side side, int strength);
	bool isComplete();
};