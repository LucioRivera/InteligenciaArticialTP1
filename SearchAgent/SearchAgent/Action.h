#pragma once
#include "Skeld.h"
#include "Impostor.h"
#include <iostream>

class Impostor;

class Action{
public:
    virtual void update(Skeld&, Impostor&) = 0;
	virtual bool usesEnergy() = 0;
	virtual void printType() = 0;
};
