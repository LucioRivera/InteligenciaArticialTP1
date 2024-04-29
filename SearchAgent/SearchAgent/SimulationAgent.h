#pragma once

#include <set>
#include "Skeld.h"
#include "Impostor.h"
#include "Strategy.h"

class Skeld;
class Impostor;
class Strategy;

class SimulationAgent{
public:
    SimulationAgent(int, int, std::set<int>, Strategy*);
    void simulate();
private:
    Skeld skeld;
    Impostor impostor;
    // metrics
    int perceptionAmmount;
    int energyUsed;
    std::vector<long long> execTime;
    void printMetrics();
};