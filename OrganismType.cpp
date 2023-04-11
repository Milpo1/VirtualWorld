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
Strength getStrengthTypeByType(Organisms type) {

	switch (type) {
	case Organisms::HUMAN:
		return Strength::HUMAN;
	case Organisms::WOLF:
		return Strength::WOLF;
	case Organisms::SHEEP:
		return Strength::SHEEP;
	case Organisms::FOX:
		return Strength::FOX;
	case Organisms::TURTLE:
		return Strength::TURTLE;
	case Organisms::ANTELOPE:
		return Strength::ANTELOPE;
	case Organisms::GRASS:
		return Strength::GRASS;
	case Organisms::CYBER_SHEEP:
		return Strength::CYBER_SHEEP;
	case Organisms::SOW_THISTLE:
		return Strength::SOW_THISTLE;
	case Organisms::GUARANA:
		return Strength::GUARANA;
	case Organisms::BELLADONNA:
		return Strength::BELLADONNA;
	case Organisms::SOSNOWSKY:
		return Strength::SOSNOWSKY;
	default:
		return Strength::NONE;
	}
}
int getStrengthByType(Organisms type) {
	return (int)getStrengthTypeByType(type);
}

Initiative getInitiativeTypeByType(Organisms type) {

	switch (type) {
	case Organisms::HUMAN:
		return Initiative::HUMAN;
	case Organisms::WOLF:
		return Initiative::WOLF;

	case Organisms::SHEEP:
		return Initiative::SHEEP;
	case Organisms::FOX:
		return Initiative::FOX;
	case Organisms::TURTLE:
		return Initiative::TURTLE;
	case Organisms::ANTELOPE:
		return Initiative::ANTELOPE;
	case Organisms::GRASS:
		return Initiative::GRASS;
	case Organisms::CYBER_SHEEP:
		return Initiative::CYBER_SHEEP;
	case Organisms::SOW_THISTLE:
		return Initiative::SOW_THISTLE;
	case Organisms::GUARANA:
		return Initiative::GUARANA;
	case Organisms::BELLADONNA:
		return Initiative::BELLADONNA;
	case Organisms::SOSNOWSKY:
		return Initiative::SOSNOWSKY;
	default:
		return Initiative::NONE;
	}
}
int getInitiativeByType(Organisms type) {
	return (int)getInitiativeTypeByType(type);
}