#include <gtest/gtest.h>
#include "grafos.h"
#include <string>
#include <vector>
#include <memory>
#include <set>
using namespace std;

TEST(GrafoTest, NodeInitialization)
{
	auto nodeA = make_shared<Node>();
	nodeA->data = {0, 0};
	auto nodeB = make_shared<Node>();
	nodeB->data = {1, 2};
	auto nodeC = make_shared<Node>();
	nodeC->data = {2, 3};
	auto nodeD = make_shared<Node>();
	nodeD->data = {3, 1};

	push(nodeA, nodeB);
	push(nodeA, nodeC, false);
	push(nodeB, nodeD, false);
	push(nodeC, nodeD, false);

	vector<shared_ptr<Node>> nodes = {nodeA, nodeB, nodeC, nodeD};

	dijkstra(nodeA, nodes);
	EXPECT_EQ(nodeA->cost, 0);
	EXPECT_EQ(nodeB->cost, 5);
	EXPECT_EQ(nodeC->cost, 13);
	EXPECT_EQ(nodeD->cost, 18);
}
