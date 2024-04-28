#include "MoveToRoom.h"

MoveToRoom::MoveToRoom(int room) {
    this->transitionRoom = room;
}

void MoveToRoom::update(Skeld& skeld, Impostor& impostor) {
    impostor.move(this->transitionRoom);
    skeld.moveAgent(this->transitionRoom);
}

bool MoveToRoom::usesTime() {
    return true;
}

bool MoveToRoom::usesEnergy() {
	return true;
}
