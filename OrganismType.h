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
const char* getNameByType(Organisms type);