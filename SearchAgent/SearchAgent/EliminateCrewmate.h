#pragma once
#ifndef ELIMINATE_CREWMATE_H
#define ELIMINATE_CREWMATE_H

#include "Action.h"
class EliminateCrewmate : public Action{
public:
	EliminateCrewmate(int);
	void update(Skeld&, Impostor&) override;
	bool usesTime() override;
private:
	int crewmateIdx;
};

#endif