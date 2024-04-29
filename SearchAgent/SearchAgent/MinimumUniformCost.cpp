#include "MinimumUniformCost.h"
#include <queue>
#include <map>
#include <utility>
typedef std::pair<int, Node> MUCpair;

Action* MinimumUniformCost::selectAction(Node beginNode) {
	SkeldStructure map = SkeldStructure(); // cambiar
	std::map<Node, Node> parent;
	parent[beginNode] = beginNode;
	std::priority_queue<MUCpair, std::vector<MUCpair>, std::greater<MUCpair>> q;
	q.push({0, beginNode});
	Action* action = nullptr;
	while (not q.empty()) {
		Node node = q.top().second;
		int partial_cost = q.top().first;
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
				q.push({partial_cost + Node::getAction(node, neighbor)->usesEnergy(), neighbor});
			}
		}		
	}
	return action;
}
