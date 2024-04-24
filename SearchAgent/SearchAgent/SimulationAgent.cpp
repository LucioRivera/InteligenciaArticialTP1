#include "SimulationAgent.h"
#include "Action.h"
#include <cassert>

#include <iostream> // sacar despues

SimulationAgent::SimulationAgent(int initialEnergy, int initialCrewmates, std::set<int> sabotages, Strategy* strategy) {
    this->skeld = Skeld(initialCrewmates);
    this->impostor = Impostor(skeld.getAgentRoom(), initialEnergy, this->skeld.getCrewmates(), sabotages, strategy);
}

void SimulationAgent::simulate() {
    this->skeld.printState();
    this->impostor.printState();
    std::cout << '\n';
    int step = 0;
    while (step < 100) {
        std::vector<int> perception = this->skeld.getPerception();
        this->impostor.see(perception);
        Action* action = this->impostor.selectAction();
        if (action == nullptr) {
            assert(0);
            break;
        }
        action->update(this->skeld, this->impostor);
        if (action->usesTime()) {
            this->skeld.updateCrewmates();
        }
        if (this->impostor.succeeded() or this->impostor.failed())
            break;
        step++;
        delete action;
        this->skeld.printState();
        this->impostor.printState();
        std::cout << '\n';
    }
    std::cout << step << std::endl;
    if (this->impostor.succeeded())
        std::cout << "GANO" << std::endl;
    else if (this->impostor.failed())
        std::cout << "Perdio pepoSad" << std::endl;
    else
        std::cout << "Ni gano ni perdio" << std::endl;
}