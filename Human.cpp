#include "Human.h"
#include "World.h"

Human::Human(World* worldPtr, Point& coords)
{
	this->worldPtr = worldPtr;
	this->coords = coords;
	this->strength = (int)Strength::HUMAN;
	this->initiative = (int)Initiative::HUMAN;
	this->type = Organisms::HUMAN;
	this->flag = Flag::ADULT;
}

void Human::action() {
	Point source = this->coords;
	Point dest, vector;
	switch (this->worldPtr->input) {
	case KEY_UP:
		vector = Point(0, -1);
		break;
	case KEY_DOWN:
		vector = Point(0, 1);
		break;
	case KEY_LEFT:
		vector = Point(-1, 0);
		break;
	case KEY_RIGHT:
		vector = Point(1, 0);
		break;
	default:
		return;
	}
	dest = source + vector;
	Response response = this->worldPtr->moveInstance(source, dest);
	switch (response) {
	case Response::COLLISION:
		this->worldPtr->collideInstances(source, dest);
		break;
	}
}

void Human::draw()
{
	std::cout << (char)this->type;
}







