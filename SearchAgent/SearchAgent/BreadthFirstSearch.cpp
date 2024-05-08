#include "BreadthFirstSearch.h"
#include <queue>
#include <map>

Action* BreadthFirstSearch::selectAction(Node beginNode) {
	std::cout << "--- EMPIEZA BFS ---\n";
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
				Node::printTransition(node, neighbor);
				parent[neighbor] = node;
				q.push(neighbor);
			}
		}		
	}
	std::cout << "--- TERMINA BFS ---\n";
	return action;
}
