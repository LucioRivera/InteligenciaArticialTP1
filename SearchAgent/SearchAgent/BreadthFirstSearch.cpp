#include "BreadthFirstSearch.h"
#include <queue>
#include <map>

Action* BreadthFirstSearch::selectAction(Node beginNode) {
	std::map<Node, Node> parent;
	parent[beginNode] = beginNode;
	std::queue<Node> q;
	q.push(beginNode);
	Action* action = nullptr;
	while (not q.empty()) {
		Node node = q.front();
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
				q.push(neighbor);
			}
		}		
	}
	return action;
}
