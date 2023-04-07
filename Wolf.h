#pragma once
#include "Animal.h"
class Wolf :
    public Animal {
public:
    void draw();
    Wolf(World* worldPtr, Point& coords);
};

