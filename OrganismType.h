#pragma once
enum class Organisms {
	HUMAN,
	WOLF,
	SHEEP,
	FOX,
	TURTLE,
	ANTELOPE,
	GRASS,
	CYBER_SHEEP,
	SOW_THISTLE,
	GUARANA,
	BELLADONNA,
	SOSNOWSKY
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