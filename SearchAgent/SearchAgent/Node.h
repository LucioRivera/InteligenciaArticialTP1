#pragma once
#ifndef NODE_H
#define NODE_H
#include <vector>
#include <set>
#include "SkeldStructure.h"
#include "Action.h"

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

/*
struct Node {
	int room, energy;
	std::vector<int> crewmates;
	std::set<int> sabotagesLeft;
	Node* parent;
};
*/
#endif