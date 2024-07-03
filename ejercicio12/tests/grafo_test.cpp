#include <gtest/gtest.h>
#include "grafos.h"
#include <string>
#include <vector>
#include <memory>
#include <set>
using namespace std;

TEST(GrafoTest, NodeInitialization)
{
	auto node = make_shared<Node>('A', vector<vector<string>>{{"B", "2"}, {"C", "1"}}, 0);
	EXPECT_EQ(node->nombre, 'A');
	EXPECT_EQ(node->letra_coste.size(), 2);
	EXPECT_EQ(node->letra_coste[0][0], "B");
	EXPECT_EQ(node->letra_coste[0][1], "2");
	EXPECT_EQ(node->coste_start, 0);
}

TEST(GrafoTest, PushSingleConnection)
{
	auto nodeA = make_shared<Node>('A', vector<vector<string>>{{"B", "2"}}, 0);
	auto nodeB = make_shared<Node>('B', vector<vector<string>>{{"A", "2"}}, INT8_MAX);

	push(nodeA, nodeB, false);

	ASSERT_EQ(nodeA->neighbors.size(), 1);
	EXPECT_EQ((*nodeA->neighbors.begin())->nombre, 'B');

	ASSERT_EQ(nodeB->neighbors.size(), 0); // Unidirectional connection
}

TEST(GrafoTest, PushBidirectionalConnection)
{
	auto nodeA = make_shared<Node>('A', vector<vector<string>>{{"B", "2"}}, 0);
	auto nodeB = make_shared<Node>('B', vector<vector<string>>{{"A", "2"}}, INT8_MAX);

	push(nodeA, nodeB, true);

	ASSERT_EQ(nodeA->neighbors.size(), 1);
	EXPECT_EQ((*nodeA->neighbors.begin())->nombre, 'B');

	ASSERT_EQ(nodeB->neighbors.size(), 1);
	EXPECT_EQ((*nodeB->neighbors.begin())->nombre, 'A');
}

TEST(GrafoTest, ComplexGraphConnections)
{
	Grafo grafo;
	auto nodeA = make_shared<Node>('A', vector<vector<string>>{{"B", "2"}, {"C", "1"}}, 0);
	auto nodeB = make_shared<Node>('B', vector<vector<string>>{{"E", "2"}}, INT8_MAX);
	auto nodeC = make_shared<Node>('C', vector<vector<string>>{{"F", "3"}, {"E", "5"}}, INT8_MAX);
	auto nodeD = make_shared<Node>('D', vector<vector<string>>{{"G", "5"}, {"B", "4"}}, INT8_MAX);
	auto nodeE = make_shared<Node>('E', vector<vector<string>>{{"C", "7"}, {"F", "1"}}, INT8_MAX);
	auto nodeF = make_shared<Node>('F', vector<vector<string>>{{"D", "2"}}, INT8_MAX);
	auto nodeG = make_shared<Node>('G', vector<vector<string>>(), INT8_MAX);

	grafo.grafo_st.insert(nodeA);
	grafo.grafo_st.insert(nodeB);
	grafo.grafo_st.insert(nodeC);
	grafo.grafo_st.insert(nodeD);
	grafo.grafo_st.insert(nodeE);
	grafo.grafo_st.insert(nodeF);
	grafo.grafo_st.insert(nodeG);

	push(nodeA, nodeB, false);
	push(nodeA, nodeC, false);
	push(nodeB, nodeE, false);
	push(nodeC, nodeF, false);
	push(nodeC, nodeE);
	push(nodeD, nodeG, false);
	push(nodeD, nodeB, false);
	push(nodeE, nodeF, false);
	push(nodeF, nodeD, false);

	EXPECT_EQ(nodeA->neighbors.size(), 2);
	EXPECT_EQ(nodeB->neighbors.size(), 1);
	EXPECT_EQ(nodeC->neighbors.size(), 2);
	EXPECT_EQ(nodeD->neighbors.size(), 2);
	EXPECT_EQ(nodeE->neighbors.size(), 2);
	EXPECT_EQ(nodeF->neighbors.size(), 1);
	EXPECT_EQ(nodeG->neighbors.size(), 0);
}