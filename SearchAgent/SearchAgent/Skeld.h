#pragma once
#ifndef SKELD_H
#define SKELD_H

#include "SkeldStructure.h"
#include <vector>
#include "Crewmate.h"

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

#endif