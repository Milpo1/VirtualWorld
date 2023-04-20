#pragma once
#include "Organism.h"
///Out of 100
#define SOW_CHANCE 10

class Plant :
    public Organism {
public:
    void action() override;
    void collision(Fight* fight) override;
    void sow();
    virtual void draw() = 0;
    void killMsg();
};
