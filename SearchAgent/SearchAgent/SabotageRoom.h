#pragma once
#ifndef SABOTAGE_ROOM_H
#define SABOTAGE_ROOM_H
#include "Action.h"

class SabotageRoom : public Action{
public:
	SabotageRoom(int);
	void update(Skeld&, Impostor&) override;
	bool usesTime() override;
private:
	int sabotageRoom;
};

#endif