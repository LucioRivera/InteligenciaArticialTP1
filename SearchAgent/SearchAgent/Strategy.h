#pragma once
#include "Action.h"
#include "Node.h"

class Action;
class Node;

class Strategy{
public:
	virtual Action* selectAction(Node) = 0;
protected:
	SkeldStructure map = SkeldStructure();
};

