#pragma once
#include "SkeldStructure.h"
#include "Action.h"
#include <vector>
#include <set>
#include <string>

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
	static void printTransition(Node, Node);
	std::string getFormattedState();
	int getSabotagesLeft() const;
	int getCrewmatesLeft() const;
private:
	int room, energy;
	std::vector<int> crewmates;
	std::set<int> sabotagesLeft;
};