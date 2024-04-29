#pragma once
#include "Action.h"

class MoveToRoom : public Action{
public:
	MoveToRoom(int);
	void update(Skeld&, Impostor&) override;
	bool usesEnergy() override;
private:
	int transitionRoom;
};
