#include "Node.h"
#include <numeric>
#include <algorithm>
#include <cassert>
#include "EliminateCrewmate.h"
#include "MoveToRoom.h"
#include "SabotageRoom.h"
#include <iostream>

Node::Node() {
	this->room = -1;
	this->energy = 0;
	this->crewmates = std::vector<int>();
	this->sabotagesLeft = std::set<int>();
}

Node::Node(int room, int energy, std::vector<int> crewmates, std::set<int> sabotages) {
	this->room = room;
	this->energy = energy;
	this->crewmates = crewmates;
	this->sabotagesLeft = sabotages;
}

int Node::getSabotagesLeft() const {
	return this->sabotagesLeft.size();
}

int Node::getCrewmatesLeft() const {
	int answer = 0;
	for(const auto& v: this->crewmates) if (v != -1) answer++;
	return answer;
}

bool Node::isGoal() {
	return this->energy > 0 and this->sabotagesLeft.empty() and this->getCrewmatesLeft() == 0;
}

std::vector<Node> Node::expandNode(const SkeldStructure& map) {
	std::vector<Node> neighbors = std::vector<Node>();
	std::vector<int>::iterator elimIter = std::find(crewmates.begin(), crewmates.end(), this->room);
	if (elimIter != this->crewmates.end()) {
		int elimPos = (int) (elimIter - this->crewmates.begin());
		std::vector<int> newCrewmates = this->crewmates;
		newCrewmates[elimPos] = -1;
		neighbors.push_back(Node(this->room, this->energy, newCrewmates, this->sabotagesLeft));
	}
	std::set<int>::iterator saboIter = this->sabotagesLeft.find(this->room);
	if (saboIter != this->sabotagesLeft.end()) {
		std::set<int> newSabotages = this->sabotagesLeft;
		newSabotages.erase(this->room);
		neighbors.push_back(Node(this->room, this->energy, this->crewmates, newSabotages));
	}
	if (this->energy > 0) {
		for (int x : map.getNeighbors(this->room)) {
			neighbors.push_back(Node(x, this->energy - 1, this->crewmates, this->sabotagesLeft));
		}
	}
	return neighbors;
}

bool Node::operator<(const Node& other) const {
	if (this->energy != other.energy)
		return this->energy < other.energy;
	if (this->room != other.room)
		return this->room < other.room;
	if (this->crewmates != other.crewmates)
		return this->crewmates < other.crewmates;
	return this->sabotagesLeft < other.sabotagesLeft;	
}

bool Node::operator==(const Node& other) const {
	return !(*this != other);
}

bool Node::operator!=(const Node& other) const {
	return this->room != other.room or this->energy != other.energy or this->crewmates != other.crewmates or this->sabotagesLeft != other.sabotagesLeft;
}

Action* Node::getAction(Node parent, Node child) {
	if (parent.energy == child.energy + 1) { // Move
		assert(parent.crewmates == child.crewmates);
		assert(parent.sabotagesLeft == child.sabotagesLeft);
		// podria chequear si son adyacentes, pero deberian serlo
		return new MoveToRoom(child.room);
	}
	else if (parent.sabotagesLeft.size() == child.sabotagesLeft.size() + 1) { // Sabotage
		assert(parent.room == child.room);
		assert(parent.energy == child.energy);
		assert(parent.crewmates == child.crewmates);
		// podria chequear que child.sabotagesLeft.insert(parent.room) == parent.sabotagesLeft
		return new SabotageRoom(parent.room);
	}
	else { // Eliminate
		assert(parent.energy == child.energy);
		assert(parent.sabotagesLeft == child.sabotagesLeft);
		assert(parent.room == child.room);
		int crewmateIdx = -1;
		for (int i = 0;i < parent.crewmates.size();i++) {
			if (parent.crewmates[i] != child.crewmates[i]) {
				assert(crewmateIdx == -1);
				assert(child.crewmates[i] == -1);
				assert(parent.crewmates[i] != -1);
				crewmateIdx = i;
			}
		}
		return new EliminateCrewmate(crewmateIdx);
	}
}

std::string Node::getFormattedState() {
	std::string state = "\"(" + std::to_string(this->room) + ", " + std::to_string(this->energy) + ", {";
	bool f = false;
	for (const int& c : this->crewmates) {
		if (f) state += ",";
		f = true;
		state += std::to_string(c);
	}
	state += "}, {";
	f = false;
	for (const int& s : this->sabotagesLeft) {
		if (f) state += ",";
		f = true;
		state += std::to_string(s);
	}
	state += "})\"";
	return state;
}

void Node::printTransition(Node begin, Node end) {
	std::cout << begin.getFormattedState() << " -> " << end.getFormattedState() << ";\n";
}