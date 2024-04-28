#include "AStar.h"
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>
#include "SkeldStructure.h"
#include <iostream>
#include <queue>
#include <functional>
typedef std::pair<int, Node> ASTARpair;

Action* AStar::selectAction(Node beginNode) {
	SkeldStructure map = SkeldStructure(); // cambiar
	std::map<Node, Node> parent;
	parent[beginNode] = beginNode;
	std::priority_queue<ASTARpair, std::vector<ASTARpair>, std::greater<ASTARpair>> q;
	q.push({0 + beginNode.heuristic(), beginNode});
	Action* action = nullptr;
	while (not q.empty()) {
		Node node = q.top().second;
		int partial_f = q.top().first;
		//std::cout << "Q.front = " << partial_cost << '\n';
		q.pop();
		if (node.isGoal()) {
			// goal
			while (parent[node] != beginNode)
				node = parent[node];
			action = Node::getAction(beginNode, node);
			break;
		}
		std::vector<Node> neighbors = node.expandNode(map);
		for (const Node& neighbor : neighbors) {
			if (parent.count(neighbor) == 0) {
				parent[neighbor] = node;
				q.push({partial_f + Node::getAction(node, neighbor)->usesEnergy() + neighbor.heuristic(), neighbor});
			}
		}		
	}
	std::cout << "HIZO ACCION\n";
	return action;
}
