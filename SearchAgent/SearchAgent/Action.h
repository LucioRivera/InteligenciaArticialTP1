#pragma once
#include "Skeld.h"
#include "Impostor.h"

class Impostor;

class Action{
public:
    virtual void update(Skeld&, Impostor&) = 0;
    virtual bool usesTime() = 0;
	virtual bool usesEnergy() = 0;
};
