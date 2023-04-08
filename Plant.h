#pragma once
#include "Organism.h"
#include "World.h"

class Plant :
    public Organism {
public:
    void action() override;
    void collision(Fight* fight) override;
    virtual void draw() = 0;
};

