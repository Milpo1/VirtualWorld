#pragma once
#include "Animal.h"
class Sheep :
    public Animal {
public:
    void draw();
    Sheep(World* worldPtr, Point& coords);
};

