#include "AStar.h"
#include <queue>
#include <map>
#include <utility>
typedef std::pair<int, Node> ASTARpair;

Action* AStar::selectAction(Node beginNode) {
	
	std::map<Node, Node> parent;
	parent[beginNode] = beginNode;
	std::priority_queue<ASTARpair, std::vector<ASTARpair>, std::greater<ASTARpair>> q;
	q.push({0 + beginNode.getCrewmatesLeft() + beginNode.getSabotagesLeft(), beginNode});
	Action* action = nullptr;
	while (not q.empty()) {
		Node node = q.top().second;
		int partial_f = q.top().first;
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
				q.push({partial_f + Node::getAction(node, neighbor)->usesEnergy() + neighbor.getCrewmatesLeft() + neighbor.getSabotagesLeft(), neighbor});
			}
		}		
	}
	return action;
}
