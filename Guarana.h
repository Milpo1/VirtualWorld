#pragma once
#include "Plant.h"
class Guarana :
    public Plant {
public:
    void draw() override;
    void collision(Fight* fight) override;
    Guarana(World* worldPtr, Point& coords);
};

