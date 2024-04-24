#include "SkeldStructure.h"
#include <algorithm>

SkeldStructure::SkeldStructure(){
    this->map = std::vector<std::vector<int>>(14);
    this->addEdge(7, 6);
    this->addEdge(7, 2);
    this->addEdge(7, 13);
    this->addEdge(6, 2);
    this->addEdge(6, 13);
    this->addEdge(2, 13);
    this->addEdge(2, 1);
    this->addEdge(11, 1);
    this->addEdge(11, 10);
    this->addEdge(12, 13);
    this->addEdge(12, 10);
    this->addEdge(13, 10);
    this->addEdge(10, 1);
    this->addEdge(10, 9);
    this->addEdge(10, 8);
    this->addEdge(9, 8);
    this->addEdge(1, 5);
    this->addEdge(1, 0);
    this->addEdge(5, 0);
    this->addEdge(0, 4);
    this->addEdge(0, 3);
    this->addEdge(0, 8);
    this->addEdge(8, 4);
    this->addEdge(8, 3);
    this->addEdge(3, 4);
}
void SkeldStructure::addEdge(int a, int b) {
    this->map[a].push_back(b);
    this->map[b].push_back(a);
}
std::vector<int> SkeldStructure::getNeighbors(int u) const {
    return this->map[u];
}

int SkeldStructure::getRandomRoom() {
    return rand() % 14;
}

bool SkeldStructure::areNeighbors(int a, int b) {
    return std::find(this->map[a].begin(), this->map[a].end(), b) != this->map[a].end() or a==b;
}