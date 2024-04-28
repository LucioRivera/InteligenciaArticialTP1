#pragma once
#include "SkeldStructure.h"
#include "Action.h"
#include <vector>
#include <set>

class Action;

class Node{
public:
	Node();
	Node(int, int, std::vector<int>, std::set<int>);
	bool isGoal();
	std::vector<Node> expandNode(const SkeldStructure& map);
	bool operator<(const Node&) const;
	bool operator==(const Node&) const;
	bool operator!=(const Node&) const;
	static Action* getAction(Node, Node);
	int heuristic() const;
private:
	int crewmatesLeft() const;
	int room, energy;
	std::vector<int> crewmates;
	std::set<int> sabotagesLeft;
};