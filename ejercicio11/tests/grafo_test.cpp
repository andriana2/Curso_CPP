#include <gtest/gtest.h>
#include "grafo.h"
#include <string>
#include <vector>
using namespace std;

TEST(GrafoTest, PushDireccional) {
  auto node1 = make_shared<Node<int>>(1);
  auto node2 = make_shared<Node<int>>(2);

  push(node1, node2);

  ASSERT_EQ(node1->neighbors.size(), 1);
  EXPECT_EQ(node1->neighbors[0]->data, 2);

  ASSERT_EQ(node2->neighbors.size(), 1);
  EXPECT_EQ(node2->neighbors[0]->data, 1);
}

TEST(GrafoTest, PushDireccionalfalse) {
  auto node1 = make_shared<Node<int>>(1);
  auto node2 = make_shared<Node<int>>(2);

  push(node1, node2,false);

  ASSERT_EQ(node1->neighbors.size(), 1);
  EXPECT_EQ(node1->neighbors[0]->data, 2);

  ASSERT_EQ(node2->neighbors.size(), 0);
}

TEST(GrafoTest, PushDuplicado) {
  auto node1 = make_shared<Node<int>>(1);
  auto node2 = make_shared<Node<int>>(2);

  push(node1, node2);
  push(node1, node2);

  ASSERT_EQ(node1->neighbors.size(), 1);
  EXPECT_EQ(node1->neighbors[0]->data, 2);

  ASSERT_EQ(node2->neighbors.size(), 1);
  EXPECT_EQ(node2->neighbors[0]->data, 1);
}

TEST(GrafoTest, grafo_completo) {
  auto node1 = make_shared<Node<int>>(1);
  auto node2 = make_shared<Node<int>>(2);
  auto node3 = make_shared<Node<int>>(3);

  push(node2, node1);
  push(node1, node3);

  ASSERT_EQ(node1->neighbors.size(), 2);
  EXPECT_EQ(node1->neighbors[0]->data, 2);
  EXPECT_EQ(node1->neighbors[1]->data, 3);

  ASSERT_EQ(node2->neighbors.size(), 1);
  EXPECT_EQ(node2->neighbors[0]->data, 1);

  ASSERT_EQ(node3->neighbors.size(), 1);
  EXPECT_EQ(node3->neighbors[0]->data, 1);
}

TEST(GrafoTest, grafo_completo_bidirecional) {
  auto node1 = make_shared<Node<int>>(1);
  auto node2 = make_shared<Node<int>>(2);
  auto node3 = make_shared<Node<int>>(3);

  push(node2, node1);
  push(node1, node3, false);
  push(node1, node3);

  ASSERT_EQ(node1->neighbors.size(), 2);
  EXPECT_EQ(node1->neighbors[0]->data, 2);
  EXPECT_EQ(node1->neighbors[1]->data, 3);

  ASSERT_EQ(node2->neighbors.size(), 1);
  EXPECT_EQ(node2->neighbors[0]->data, 1);

  ASSERT_EQ(node3->neighbors.size(), 1);
  EXPECT_EQ(node3->neighbors[0]->data, 1);
}