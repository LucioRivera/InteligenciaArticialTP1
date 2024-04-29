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
	bool operator>(const Node&) const;
	bool operator==(const Node&) const;
	bool operator!=(const Node&) const;
	static Action* getAction(Node, Node);
	static void resetIds();
	int getSabotagesLeft() const;
	int getCrewmatesLeft() const;
	int getId() const; //Para debugear nomas
private:
	int room, energy;
	//unsigned long long id;
	//static unsigned long long lastUsedId; 
	std::vector<int> crewmates;
	std::set<int> sabotagesLeft;
};