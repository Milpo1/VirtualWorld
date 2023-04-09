#pragma once
enum class Organisms:char {
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