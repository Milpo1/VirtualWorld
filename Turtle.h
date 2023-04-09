#pragma once
#include "Animal.h"
class Turtle :
    public Animal {
public:
    Turtle(World* worldPtr, Point& coords);
    void draw() override;
    void action() override;
    void collision(Fight* fight) override;
};

