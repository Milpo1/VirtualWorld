#pragma once
#include "Animal.h"
#include "World.h"
class Antelope :
    public Animal {
public:
    Antelope(World* worldPtr, Point& coords);
    void draw() override;
    void action() override;
    void collision(Fight* fight) override;
};

