#include "EliminateCrewmate.h"

EliminateCrewmate::EliminateCrewmate(int crewmateIdx) {
	this->crewmateIdx = crewmateIdx;
}

void EliminateCrewmate::update(Skeld& skeld, Impostor& impostor) {
	skeld.eliminateCrewmate(this->crewmateIdx);
	impostor.eliminateCrewmate(this->crewmateIdx);
}

bool EliminateCrewmate::usesEnergy() {
	return false;
}

void EliminateCrewmate::printType() {
	std::cout << "Se elimina al crewmate #" << crewmateIdx << '\n';
}
