#include "SimulationAgent.h"
#include "Action.h"
#include <cassert>
#include <chrono>
#include <iostream> // sacar despues

SimulationAgent::SimulationAgent(int initialEnergy, int initialCrewmates, std::set<int> sabotages, Strategy* strategy) {
    this->perceptionAmmount = 0;
    this->energyUsed = 0;
    this->execTime = std::vector<long long>();
    this->skeld = Skeld(initialCrewmates);
    this->impostor = Impostor(skeld.getAgentRoom(), initialEnergy, this->skeld.getCrewmates(), sabotages, strategy);
}

void SimulationAgent::simulate() {
    //this->skeld.printState();
    //this->impostor.printState();
    while (this->perceptionAmmount < 10'000) {
        this->perceptionAmmount++;
        std::vector<int> perception = this->skeld.getPerception();
        this->impostor.see(perception);
        auto start = std::chrono::high_resolution_clock::now();
        Action* action = this->impostor.selectAction();
        auto end = std::chrono::high_resolution_clock::now();
        if (action == nullptr) {
            assert(0);
            break;
        }
        action->update(this->skeld, this->impostor);
        if (action->usesTime()) {
            this->skeld.updateCrewmates();
        }
        this->energyUsed += action->usesEnergy();
        this->execTime.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
        if (this->impostor.succeeded() or this->impostor.failed())
            break;
        delete action;
        //this->skeld.printState();
        //this->impostor.printState();
    }
    std::cout << '\n';
    if (this->impostor.succeeded())
        std::cout << "El agente gano" << std::endl;
    else if (this->impostor.failed())
        std::cout << "El agente perdio" << std::endl;
    else
        std::cout << "Ni gano ni perdio" << std::endl;
    this->printMetrics();
}

void SimulationAgent::printMetrics() {
    std::cout << "--- METRICAS ---\n";
    std::cout << "Cantidad de ciclos de percepciones: " << this->perceptionAmmount << '\n';
    std::cout << "Cantidad de energia gastada: " << this->energyUsed << '\n';
    std::cout << "Tiempos de ejecución:";
    double avg = 0;
    for (const long long& t : this->execTime) {
        avg += t;
        std::cout << ' ' << t;
    }
    std::cout << "\nTiempo promedio de ejecución: " << avg / this->execTime.size() << "\n --- ---\n";
}