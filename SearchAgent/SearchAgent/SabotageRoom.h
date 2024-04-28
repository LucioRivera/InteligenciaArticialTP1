#pragma once
#include "Action.h"

class SabotageRoom : public Action{
public:
	SabotageRoom(int);
	void update(Skeld&, Impostor&) override;
	bool usesTime() override;
	bool usesEnergy() override;
private:
	int sabotageRoom;
};
