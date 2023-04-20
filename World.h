#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>

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

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define REPORT_DRAW_X 0
#define REPORT_DRAW_Y 2
#define WORLD_DRAW_X 35
#define WORLD_DRAW_Y 3

#define MAX_PROB 100

typedef Organism*** Grid;
class World {
	int n, m;
	int turnCounter;
	OrganismList organisms;
	Grid grid;
public:
	int input;
	Point* dirVectors;
	World(int n, int m);
	// Getters
	Grid getGrid();

	// Setters

	// Other
	void makeTurn();
	void drawWorld();
	void saveGame();
	void loadGame();
	void setInput(int c);
	int getInput();
	void setInstanceAt(Point point, Organism* organism);
	Organism* getInstanceAt(Point point);
	Organism* getClosestInstanceByType(Point source, Organisms type);
	Organism* instanceCreate(Organisms type, int x, int y, Flag flag = Flag::ADULT);
	Response moveInstance(Point source, Point dest);
	Response collideInstances(Point source, Point dest);
	void killInstance(Organism* instance);
	bool isValid(Point point);
	Point getAvaibleField(Point& source, bool allowTaken);

	~World();
};
