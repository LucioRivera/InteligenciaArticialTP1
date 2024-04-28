#pragma once

#include "SkeldStructure.h"
#include "Crewmate.h"
#include <vector>

class Skeld{
public:
	Skeld();
	Skeld(int);
	std::vector<int> getPerception();
	void updateCrewmates();
	void moveAgent(int);
	void eliminateCrewmate(int);
	int getAgentRoom(); // no usar
	std::vector<int> getCrewmates(); // no usar
	void printState();
private:
	SkeldStructure map;
	std::vector<Crewmate> crewmates;
	int agentSensorTimer;
	int agentRoom;
};