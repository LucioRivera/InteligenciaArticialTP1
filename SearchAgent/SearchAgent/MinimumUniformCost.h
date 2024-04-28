#pragma once
#ifndef MINIMUM_UNIFORM_COST_H
#define MINIMUM_UNIFORM_COST_H

#include "Strategy.h"

class MinimumUniformCost : public Strategy{
public:
	Action* selectAction(Node) override;
private:
};

#endif
