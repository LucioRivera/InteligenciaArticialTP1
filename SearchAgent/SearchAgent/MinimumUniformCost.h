#pragma once
#include "Strategy.h"

class MinimumUniformCost : public Strategy{
public:
	Action* selectAction(Node) override;
private:
};