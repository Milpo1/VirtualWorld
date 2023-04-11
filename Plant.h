#pragma once
#include "Organism.h"
class Plant :
    public Organism {
public:
    void action() override;
    void collision(Fight* fight) override;
    void sow();
    virtual void draw() = 0;
    void killMsg();
};
