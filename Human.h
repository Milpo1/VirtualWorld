#pragma once
#include "Animal.h"
class Human :
	public Animal {

public:
	Human(World* worldPtr, Point& coords);
	void draw() override;
};

