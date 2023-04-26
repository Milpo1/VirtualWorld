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
	SOW_THISTLE = '^',
	GUARANA = '*',
	BELLADONNA = '$',
	SOSNOWSKY = '#'
};
enum class Strength {
	NONE = 0,
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
	NONE = 0,
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
int getStrengthByType(Organisms type);
int getInitiativeByType(Organisms type);
/// Text pack
#define EMPTY_GRID_ERR "Empty grid pointer"
#define EMPTY_ORG_LIST "Empty organism list"
#define MOVE_REPORT ' ' << getNameByType(instanceAtSource->getType()) << " moved from " << source << " to " << dest << std::endl
#define KILL_REPORT ' ' << getNameByType(this->getType()) << " " << this->coords << " gets killed!" << std::endl
#define EAT_REPORT ' ' << getNameByType(this->getType()) << " " << this->coords << " gets eaten!" << std::endl
#define ATTACK_REPORT ' ' << getNameByType(instanceAtSource->getType()) << " " << source << " colllides " << getNameByType(instanceAtDest->getType()) << " " << dest << "!\n" << std::endl
#define MATING_REPORT ' ' << getNameByType(this->type) << " " << avaibleField << " was born!" << std::endl
#define GROW_REPORT ' ' << getNameByType(this->type) << " " << avaibleField << " has grown!" << std::endl
#define HUMAN_POWER_REPORT "Power cooldown: " << this->worldPtr->specialPowerCooldown << " turns left!" << std::endl
#define HUMAN_POWER_ACTIVATE "Human activated purification!" << std::endl