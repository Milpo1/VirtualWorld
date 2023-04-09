#pragma once
#include "Plant.h"
class Belladonna :
    public Plant {
public:
    void draw() override;
    void collision(Fight* fight) override;
    Belladonna(World* worldPtr, Point& coords);
};

