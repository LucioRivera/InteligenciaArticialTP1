#pragma once

#include "SkeldStructure.h"

class Crewmate{
public:
    Crewmate();
    Crewmate(int);
    int getRoom() const;
    int getMoveTimer() const;
    bool isEliminated() const;
    void eliminate();
    void takeAction(const SkeldStructure&);
private:
    int actualRoom;
    int moveTimer;
};