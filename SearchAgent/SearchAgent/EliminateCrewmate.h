#pragma once
#include "Action.h"

class EliminateCrewmate : public Action{
public:
	EliminateCrewmate(int);
	void update(Skeld&, Impostor&) override;
	bool usesEnergy() override;
	void printType() override;
private:
	int crewmateIdx;
};
