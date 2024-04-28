#include "Skeld.h"
#include <cassert>
#include <iostream>

Skeld::Skeld() {
	this->map = SkeldStructure();
	this->agentSensorTimer = 0;
	this->agentRoom = this->map.getRandomRoom();
	this->crewmates = std::vector<Crewmate>();
}

Skeld::Skeld(int crewmateAmmount) {
	this->map = SkeldStructure();
	this->agentSensorTimer = 0;
	this->agentRoom = this->map.getRandomRoom();
	this->crewmates = std::vector<Crewmate>(crewmateAmmount);
	for (Crewmate& c : crewmates)
		c = Crewmate(this->map.getRandomRoom());
}

std::vector<int> Skeld::getPerception() {
	std::vector<int> perception;
	if (this->agentSensorTimer == 0) {
		perception = this->getCrewmates();
		this->agentSensorTimer = 3 + rand() % 3;
	}
	else {
		perception = std::vector<int>(this->crewmates.size(), -1);
		for (int i = 0;i < perception.size();i++)
			if (this->map.areNeighbors(this->agentRoom, this->crewmates[i].getRoom()))
				perception[i] = this->crewmates[i].getRoom();
		this->agentSensorTimer--;
	}
	return perception;
}

void Skeld::updateCrewmates() {
	for (Crewmate& c : this->crewmates) {
		if(not c.isEliminated())
			c.takeAction(this->map);
	}
}

void Skeld::moveAgent(int transitionRoom) {
	assert(transitionRoom >= 0 and transitionRoom < 14);
	this->agentRoom = transitionRoom;
}

void Skeld::eliminateCrewmate(int crewmateIdx) {
	assert(crewmateIdx >= 0 and crewmateIdx < crewmates.size());
	this->crewmates[crewmateIdx].eliminate();
}

int Skeld::getAgentRoom() {
	return this->agentRoom;
}

std::vector<int> Skeld::getCrewmates() {
	std::vector<int> ret;
	for (const Crewmate& c : this->crewmates) ret.push_back(c.getRoom());
	return ret;
}

void Skeld::printState() {
	std::cout << "-- ESTADO DE LA NAVE --- \n";
	std::cout << "Crewmates posiciones: ";
	for (const Crewmate& c : this->crewmates) std::cout << c.getRoom() << ' ';
	std::cout << "\nCrewmates tiempo restante: ";
	for (const Crewmate& c : this->crewmates) std::cout << c.getMoveTimer() << ' ';
	std::cout << '\n';
	std::cout << "Tiempo poder: " << this->agentSensorTimer << '\n';
	std::cout << "--- FIN ESTADO ---\n";
}