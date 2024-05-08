#pragma once
#include "Action.h"

class SabotageRoom : public Action{
public:
	SabotageRoom(int);
	void update(Skeld&, Impostor&) override;
	bool usesEnergy() override;
	void printType() override;
private:
	int sabotageRoom;
};
