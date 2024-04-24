#pragma once
#ifndef SKELD_STRUCTURE_H
#define SKELD_STRUCTURE_H

#include <vector>

class SkeldStructure {
public:
	SkeldStructure();
	std::vector<int> getNeighbors(int) const;
	bool areNeighbors(int, int);
	int getRandomRoom();
private:
	std::vector<std::vector<int>> map;
	void addEdge(int, int);
};

#endif