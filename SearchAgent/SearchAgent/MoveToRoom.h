#pragma once
#ifndef MOVE_TO_ROOM_H
#define MOVE_TO_ROOM_H

#include "Action.h"

class MoveToRoom : public Action{
public:
	MoveToRoom(int);
	void update(Skeld&, Impostor&) override;
	bool usesTime() override;
private:
	int transitionRoom;
};

#endif