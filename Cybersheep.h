#pragma once
#include "Animal.h"
class Cybersheep :
    public Animal {
public:
    Cybersheep(World* worldPtr, Point& coords);
    void draw() override;
    void action() override;
    void collision(Fight* fight) override;
};

