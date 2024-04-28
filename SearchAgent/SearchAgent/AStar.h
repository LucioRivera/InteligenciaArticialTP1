#pragma once
#ifndef A_STAR_H
#define A_STAR_H

#include "Strategy.h"

class AStar : public Strategy{
public:
	Action* selectAction(Node) override;
private:
};

#endif
