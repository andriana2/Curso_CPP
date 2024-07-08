#include "grafos.h"

int main()
{
	// Create nodes with coordinates
	auto nodeA = make_shared<Node>();
	nodeA->data = {0, 0};

	auto nodeB = make_shared<Node>();
	nodeB->data = {1, 2};

	auto nodeC = make_shared<Node>();
	nodeC->data = {2, 3};

	auto nodeD = make_shared<Node>();
	nodeD->data = {3, 1};

	// Connect nodes with edges
	push(nodeA, nodeB);
	push(nodeA, nodeC, false);
	push(nodeB, nodeD, false);
	push(nodeC, nodeD, false);

	// List of all nodes
	vector<shared_ptr<Node>> nodes = {nodeA, nodeB, nodeC, nodeD};

	// Run Dijkstra's algorithm from nodeA
	dijkstra(nodeA, nodes);

	// Print the shortest path from nodeA to all other nodes
		int a{64};
	for (auto node : nodes)
	{
		cout << "Cost to reach node "<< (char)++a <<" (" << node->data.x << ", " << node->data.y << ") is " << node->cost << endl;
		cout << "Path: ";
		auto current = node;
		while (current != nullptr)
		{
			cout << "(" << current->data.x << ", " << current->data.y << ")";
			current = current->prev;
			if (current != nullptr)
				cout << " <- ";
		}
		cout << endl;
	}

	return 0;
}
