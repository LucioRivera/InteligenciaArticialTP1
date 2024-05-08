#include "SabotageRoom.h"

SabotageRoom::SabotageRoom(int sabotageRoom) {
	this->sabotageRoom = sabotageRoom;
}

void SabotageRoom::update(Skeld& skeld, Impostor& impostor) {
	impostor.sabotage(this->sabotageRoom);
}

bool SabotageRoom::usesEnergy() {
	return false;
}

void SabotageRoom::printType() {
	std::cout << "Se sabotea la maquina del Room #" << sabotageRoom << '\n';
}