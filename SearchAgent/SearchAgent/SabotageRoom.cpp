#include "SabotageRoom.h"

SabotageRoom::SabotageRoom(int sabotageRoom) {
	this->sabotageRoom = sabotageRoom;
}

void SabotageRoom::update(Skeld& skeld, Impostor& impostor) {
	impostor.sabotage(this->sabotageRoom);
}

bool SabotageRoom::usesTime() {
	return true;
}