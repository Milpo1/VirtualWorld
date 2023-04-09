#pragma once
#include "Plant.h"
class Sosnowsky :
    public Plant {
public:
    void draw() override;
    void action() override;
    void collision(Fight* fight) override;
    Sosnowsky(World* worldPtr, Point& coords);
};

