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
	MOVED,
	COLLISION
};	
const char* getNameByType(Organisms type);