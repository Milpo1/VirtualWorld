#pragma once
#include "OrganismType.h"
class World;

class Point {
	int x, y;
public:
	Point();
	Point(int x, int y);

	int getX();
	int getY();

	void setCoords(int x, int y = -1);
};

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