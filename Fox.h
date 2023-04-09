#pragma once
#include "Animal.h"

class Fox :
    public Animal {
public:
    Fox(World* worldPtr, Point& coords);
    void draw() override;
    void action() override;
};

