#pragma once
#include "Organism.h"

class Animal :
    public Organism {
public:
    void action() override;
    void collision(Fight* fight) override;
    virtual void draw() = 0;
};
