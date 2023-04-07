#pragma once
#include "OrganismType.h"
#include "Point.h"
class World;

class Organism {
public:
	Organism* next, *prev;
	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void draw() = 0;
protected:
	World* worldPtr;
	int strength, initiative;
	Point coords;
};
class OrganismList {
	Organism* head;
public:
	OrganismList();
	void add(Organism* organism);

	~OrganismList();
};	