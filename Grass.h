#pragma once
#include "Plant.h"
class Grass :
    public Plant
{
public:
    void draw() override;
    Grass(World* worldPtr, Point& coords);
};

