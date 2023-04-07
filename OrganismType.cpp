#include "OrganismType.h"
const char* getNameByType(Organisms type) {
	switch (type) {
	case Organisms::HUMAN:
		return "Human";
	case Organisms::WOLF:
		return "Wolf";
	case Organisms::SHEEP:
		return "Sheep";
	case Organisms::FOX:
		return "Fox";
	case Organisms::TURTLE:
		return "Turtle";
	case Organisms::ANTELOPE:
		return "Antelope";
	case Organisms::GRASS:
		return "Grass";
	case Organisms::CYBER_SHEEP:
		return "Cyber-sheep";
	case Organisms::SOW_THISTLE:
		return "Sow thistle";
	case Organisms::GUARANA:
		return "Guarana";
	case Organisms::BELLADONNA:
		return "Belladonna";
	case Organisms::SOSNOWSKY:
		return "Sosnowsky";
	default:
		return "Unknown";
	}
}