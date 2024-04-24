#pragma once
#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "Strategy.h"

class BreadthFirstSearch : public Strategy{
public:
	Action* selectAction(Node) override;
private:
};

#endif