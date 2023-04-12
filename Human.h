#pragma once
#include "Animal.h"
class Human :
	public Animal {

public:
	Human(World* worldPtr, Point& coords);
	void action() override;
	void draw() override;

};

