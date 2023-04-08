#pragma once
#include <cmath>
#include <iostream>
#define BUFFER_SIZE 32
class Point
{
	enum Dir {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	int x, y;
public:
	Point();
	Point(int x, int y);

	int getX() const;
	int getY() const;

	void setCoords(int x, int y = -1);
	Point getRandomUnitVector();

	Point operator+(Point& right);
	Point operator-(Point& right);
	Point operator*(int scale);
};
std::ostream& operator<<(std::ostream& out, const Point& point);
int intRandRange(int min, int max);
///Randomly chooses one of the arguments. 0 or 1 by default
int chooseRand(int a = 0, int b = 1);

/// Text pack
#define EMPTY_GRID_ERR "Empty grid pointer"
#define EMPTY_ORG_LIST "Empty organism list"
#define MOVE_REPORT getNameByType(instanceAtSource->getType()) << " moved from " << source << " to " << dest << endl
#define KILL_REPORT '\t' << getNameByType(loser->getType()) << " " << loser->coords << " gets killed!" << endl
#define ATTACK_REPORT '\t' << getNameByType(instanceAtSource->getType()) << " " << source << " colllides " << getNameByType(instanceAtDest->getType()) << " " << dest << "!\n"