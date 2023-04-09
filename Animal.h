#pragma once
#include "Organism.h"

class Animal :
    public Organism {
public:
    void action() override;
    void collision(Fight* fight) override;
    void mating(Fight* fight);
    //void draw() = 0;
};
