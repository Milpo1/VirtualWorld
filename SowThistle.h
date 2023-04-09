#pragma once
#include "Plant.h"
class SowThistle :
    public Plant
{
public:
    void draw() override;
    void action() override;
    SowThistle(World* worldPtr, Point& coords);
};

