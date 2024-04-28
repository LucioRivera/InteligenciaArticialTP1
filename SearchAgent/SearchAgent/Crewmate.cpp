#include "Crewmate.h"

Crewmate::Crewmate() {
    this->actualRoom = 0;
    this->moveTimer = 0;
}

Crewmate::Crewmate(int actualRoom) {
    this->actualRoom = actualRoom;
    this->moveTimer = 0;// 1 + rand() % 4;
}

int Crewmate::getRoom() const {
    return this->actualRoom;
}

int Crewmate::getMoveTimer() const {
    return this->moveTimer;
}

bool Crewmate::isEliminated() const {
    return this->actualRoom == -1;
}

void Crewmate::eliminate() {
    this->actualRoom = -1;
}

void Crewmate::takeAction(const SkeldStructure& map) {
    if (this->moveTimer == 0) {
        std::vector<int> neighbors = map.getNeighbors(this->actualRoom);
        this->actualRoom = neighbors[rand() % neighbors.size()];
        this->moveTimer = 1 + rand() % 4;
    }
    else {
        this->moveTimer--;
    }
}
