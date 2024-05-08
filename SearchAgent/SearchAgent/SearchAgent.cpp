#include <iostream>
#include <set>
#include "SimulationAgent.h"
#include "BreadthFirstSearch.h"
#include "MinimumUniformCost.h"
#include "AStar.h"
#include <tuple>
using namespace std;

int main(){
    unsigned int seeds[] = { 345, 777, 169 };
    std::pair<int, int> experimentos[] = {
        {4, 30 + rand() % 121},
        {8, 30 + rand() % 121},
        {12, 30 + rand() % 121}
    }; // initCrewmates, initEnergy
    std::set<int> sabotages = { 9, 3, 2 }; // Electrical, reactor, weapons
    Strategy* bfsStrategy = new BreadthFirstSearch();
    Strategy* mcuStrategy = new MinimumUniformCost();
    Strategy* aStarStrategy = new AStar();
    //SimulationAgent sim = SimulationAgent(50, 2, sabotages, bfsStrategy);
    //SimulationAgent sim = SimulationAgent(50, 2, sabotages, mcuStrategy);
    SimulationAgent sim = SimulationAgent(50, 2, sabotages, aStarStrategy);
    sim.simulate();
    /*
    for (const pair<int,int>& it : experimentos) {
        cout << "-----------------------------------\n";
        cout << "CREWMATES INICIALES: " << it.first << " - ENERGIA INICIAL: " << it.second << '\n';

        cout << "\n--- BREADTH FIRST SEARCH AGENT ---";
        for (const unsigned int& seed : seeds) {
            srand(seed);
            SimulationAgent simAgent = SimulationAgent(it.second, it.first, sabotages, bfsStrategy);
            simAgent.simulate();
        }

        cout << "\n--- MINIMUM UNIFORM COST SEARCH AGENT ---";
        for (const unsigned int& seed : seeds) {
            srand(seed);
            SimulationAgent simAgent = SimulationAgent(it.second, it.first, sabotages, mcuStrategy);
            simAgent.simulate();
        }

        cout << "\n--- A STAR SEARCH AGENT ---";
        for (const unsigned int& seed : seeds) {
            srand(seed);
            SimulationAgent simAgent = SimulationAgent(it.second, it.first, sabotages, aStarStrategy);
            simAgent.simulate();
        }
    }
    */
}