#pragma once
#include "OrganismType.h"
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
	Organism*** worldPtr;
	int strength, initiative;
	Point coords;
public:
	Organism* next, *prev;
	Organism(Organism*** worldPtr, Point coords, int strength, int initiative);
	Organism(Organism& organism);

	~Organism();
};
class OrganismList {
	Organism* head;
public:
	OrganismList();

	void add(Organism& organism);

	~OrganismList();
};

