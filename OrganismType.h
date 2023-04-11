#pragma once
enum class Organisms : char {
	HUMAN = '@',
	WOLF = 'W',
	SHEEP = 'o',
	FOX = 'F',
	TURTLE = 'T',
	ANTELOPE = 'L',
	CYBER_SHEEP = '0',
	GRASS = '\"',
	SOW_THISTLE = '%',
	GUARANA = '*',
	BELLADONNA = '$',
	SOSNOWSKY = '#'
};
enum class Strength {
	HUMAN = 5,
	WOLF = 9,
	SHEEP = 4,
	FOX = 3,
	TURTLE = 2,
	ANTELOPE = 4,
	CYBER_SHEEP = 11,
	GRASS = 0,
	SOW_THISTLE = 0,
	GUARANA = 0,
	BELLADONNA = 99,
	SOSNOWSKY = 10
};
enum class Initiative {
	HUMAN = 4,
	WOLF = 5,
	SHEEP = 4,
	FOX = 7,
	TURTLE = 1,
	ANTELOPE = 4,
	CYBER_SHEEP = 4,
	GRASS = 0,
	SOW_THISTLE = 0,
	GUARANA = 0,
	BELLADONNA = 0,
	SOSNOWSKY = 0
};
enum class Response {
	POINT_INVALID,
	NULL_SOURCE,
	MOVED,
	COLLISION,
	NO_COLLISION,
	COLLIDED
};	
enum class Flag {
	ADULT,
	NEWBORN,
	EMPTY
};
const char* getNameByType(Organisms type);

/// Text pack
#define EMPTY_GRID_ERR "Empty grid pointer"
#define EMPTY_ORG_LIST "Empty organism list"
#define MOVE_REPORT getNameByType(instanceAtSource->getType()) << " moved from " << source << " to " << dest << endl
#define KILL_REPORT '\t' << getNameByType(loser->getType()) << " " << loser->coords << " gets killed!" << endl
#define ATTACK_REPORT getNameByType(instanceAtSource->getType()) << " " << source << " colllides " << getNameByType(instanceAtDest->getType()) << " " << dest << "!\n"
#define MATING_REPORT '\t' << getNameByType(this->type) << " " << avaibleField << " was born!\n"