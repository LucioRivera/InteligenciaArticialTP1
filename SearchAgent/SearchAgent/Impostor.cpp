#include "Impostor.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include "Node.h"

Impostor::Impostor() {
    this->map = SkeldStructure();
    this->actualRoom = -1;
    this->energy = 0;
    this->crewmates = std::vector<int>();
    this->sabotagesLeft = std::set<int>();
}

Impostor::Impostor(int initialRoom, int energy, std::vector<int> crewmates, std::set<int> sabotages, Strategy *searchStrategy) {
    this->map = SkeldStructure();
    this->actualRoom = initialRoom;
    this->energy = energy;
    this->crewmates = crewmates;
    this->sabotagesLeft = sabotages;
    this->strategy = searchStrategy;
}

void Impostor::see(std::vector<int> perception) {
    for (int i = 0;i < perception.size();i++) {
        if (perception[i] != -1 and this->crewmates[i] != -1) {
            this->crewmates[i] = perception[i];
        }
    }
}

Action* Impostor::selectAction() {
    return this->strategy->selectAction(Node(this->actualRoom, this->energy, this->crewmates, this->sabotagesLeft));
}

bool Impostor::succeeded() {
    return this->energy > 0 and std::all_of(this->crewmates.begin(), this->crewmates.end(), [](int c) {return c == -1;}) and sabotagesLeft.empty();
}

bool Impostor::failed() {
    // revisar si no hay que poner "and not this->succeeded()";
    return this->energy == 0;
}

void Impostor::move(int transitionRoom) {
    assert(this->energy > 0);
    this->actualRoom = transitionRoom;
    this->energy--;
}

void Impostor::sabotage(int sabotageRoom) {
    assert(this->sabotagesLeft.count(sabotageRoom));
    this->sabotagesLeft.erase(sabotageRoom);
}

void Impostor::eliminateCrewmate(int crewmateIdx) {
    assert(crewmateIdx >= 0 and crewmateIdx < crewmates.size());
    this->crewmates[crewmateIdx] = -1;
}

void Impostor::printState() {
    std::cout << "-- ESTADO DEL IMPOSTOR --- \n";
    std::cout << "Habitacion actual: " << this->actualRoom << '\n';
    std::cout << "Energia actual: " << this->energy << '\n';
    std::cout << "Crewmates restantes: ";
    for (const int& c : this->crewmates) std::cout << c << ' ';
    std::cout << '\n';
    std::cout << "Sabotajes restantes: ";
    for (const int& s : this->sabotagesLeft) std::cout << s << ' ';
    std::cout << "\n--- FIN ESTADO ---\n";
}