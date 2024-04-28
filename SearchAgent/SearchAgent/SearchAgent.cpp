#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "SimulationAgent.h"
#include "Crewmate.h"
#include "BreadthFirstSearch.h"
#include "MinimumUniformCost.h"
#include "AStar.h"
using namespace std;

int main(){
    int initialEnergy = 30 + rand() % 121;
    int initialCrewmates = 12;// 3 + rand() % 3;

    cout << "ARRANCA EL MCU" << endl;
    std::set<int> sabotages = { 9, 3, 2 }; // Electrical, reactor, weapons
    Strategy* strategy = new MinimumUniformCost();
    SimulationAgent simAgent = SimulationAgent(initialEnergy, initialCrewmates, sabotages, strategy);
    simAgent.simulate();

    cout << "ARRANCA EL BFS" << endl;
    std::set<int> sabotages2 = { 9, 3, 2 }; // Electrical, reactor, weapons
    strategy = new BreadthFirstSearch();
    simAgent = SimulationAgent(initialEnergy, initialCrewmates, sabotages2, strategy);
    simAgent.simulate();

    cout << "ARRANCA EL ASTAR" << endl;
    std::set<int> sabotages3 = { 9, 3, 2 }; // Electrical, reactor, weapons
    strategy = new AStar();
    simAgent = SimulationAgent(initialEnergy, initialCrewmates, sabotages2, strategy);
    simAgent.simulate();
}
