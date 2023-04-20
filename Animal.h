#pragma once
#include "Organism.h"
///Out of 100
#define MATING_CHANCE 20
class Animal :
    public Organism {
public:
    void action() override;
    void collision(Fight* fight) override;
    void mating(Fight* fight);
    void killMsg();
};
