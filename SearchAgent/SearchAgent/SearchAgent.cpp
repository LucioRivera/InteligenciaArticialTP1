#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "SimulationAgent.h"
#include "Crewmate.h"
#include "BreadthFirstSearch.h"
using namespace std;

int main(){
    int initialEnergy = 30 + rand() % 121;
    int initialCrewmates = 12;// 3 + rand() % 3;
    std::set<int> sabotages = { 9, 3, 2 }; // Electrical, reactor, weapons
    Strategy* strategy = new BreadthFirstSearch();
    SimulationAgent simAgent = SimulationAgent(initialEnergy, initialCrewmates, sabotages, strategy);
    simAgent.simulate();
}