#pragma once
#include "Animal.h"
class Human :
	public Animal {

	int specialPowerCooldown;
public:
	Human(World* worldPtr, Point& coords);
	void action() override;
	void collision(Fight* fight) override;
	void draw() override;

};

