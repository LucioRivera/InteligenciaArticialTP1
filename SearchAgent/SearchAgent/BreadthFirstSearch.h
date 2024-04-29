#pragma once
#include "Strategy.h"

class BreadthFirstSearch : public Strategy{
public:
	Action* selectAction(Node) override;
private:
};