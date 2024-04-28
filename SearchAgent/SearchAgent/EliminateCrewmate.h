#pragma once
#include "Action.h"

class EliminateCrewmate : public Action{
public:
	EliminateCrewmate(int);
	void update(Skeld&, Impostor&) override;
	bool usesTime() override;
	bool usesEnergy() override;
private:
	int crewmateIdx;
};
