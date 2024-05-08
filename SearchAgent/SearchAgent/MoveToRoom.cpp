#include "MoveToRoom.h"

MoveToRoom::MoveToRoom(int room) {
    this->transitionRoom = room;
}

void MoveToRoom::update(Skeld& skeld, Impostor& impostor) {
    impostor.move(this->transitionRoom);
    skeld.moveAgent(this->transitionRoom);
}

bool MoveToRoom::usesEnergy() {
	return true;
}

void MoveToRoom::printType() {
    std::cout << "Se mueve al Room #" << transitionRoom << '\n';
}