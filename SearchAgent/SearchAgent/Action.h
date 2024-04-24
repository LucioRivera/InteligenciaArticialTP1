#pragma once
#ifndef ACTION_H
#define ACTION_H

#include "Skeld.h"
#include "Impostor.h"

class Skeld;
class Impostor;

class Action{
public:
    virtual void update(Skeld&, Impostor&) = 0;
    virtual bool usesTime() = 0;
};

#endif