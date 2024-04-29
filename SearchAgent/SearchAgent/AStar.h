#pragma once
#include "Strategy.h"

class AStar : public Strategy{
public:
	Action* selectAction(Node) override;
private:
};
