#pragma once
#include "SkeldStructure.h"
#include "Strategy.h"
#include<vector>
#include<set>

class Action;
class Strategy;

class Impostor{
public:
    Impostor();
    Impostor(int, int, std::vector<int>, std::set<int>, Strategy*);
    void see(std::vector<int>);
    Action* selectAction();
    bool succeeded();
    bool failed();
    void move(int);
    void sabotage(int);
    void eliminateCrewmate(int);
    void printState();
private:
    SkeldStructure map;
    int energy;
    int actualRoom;
    std::vector<int> crewmates;
    std::set<int> sabotagesLeft;
    Strategy* strategy;
};