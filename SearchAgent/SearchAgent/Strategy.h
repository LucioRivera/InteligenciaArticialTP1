#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H

#include "Action.h"
#include<vector>
#include<set>
#include "Node.h"

class Action;
class Node;

class Strategy{
public:
	virtual Action* selectAction(Node) = 0;
private:
};

#endif
