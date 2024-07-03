#include <iostream>
#include <string>
#include <vector>
#include "grafos.h"

using namespace std;

int main()
{
  Grafo grafo;
  auto nodeA = make_shared<Node>('A', vector<vector<string>>{{"B", "2"}, {"C", "1"}}, 0);
  auto nodeB = make_shared<Node>('B', vector<vector<string>>{{"E", "2"}}, INT8_MAX);
  auto nodeC = make_shared<Node>('C', vector<vector<string>>{{"F", "3"}, {"E", "5"}}, INT8_MAX);
  auto nodeD = make_shared<Node>('D', vector<vector<string>>{{"G", "5"}, {"B", "4"}}, INT8_MAX);
  auto nodeE = make_shared<Node>('E', vector<vector<string>>{{"C", "7"}, {"F", "1"}}, INT8_MAX);
  auto nodeF = make_shared<Node>('F', vector<vector<string>>{{"D", "2"}}, INT8_MAX);
  auto nodeG = make_shared<Node>('G', nullptr, INT8_MAX);

  grafo.grafo_st.insert(nodeA);
  grafo.grafo_st.insert(nodeB);
  grafo.grafo_st.insert(nodeC);

  push(nodeA, nodeB, false);
  push(nodeA, nodeC, false);
  push(nodeB, nodeE, false);
  push(nodeC, nodeF, false);
  push(nodeC, nodeE);
  push(nodeD, nodeG, false);
  push(nodeD, nodeB, false);
  push(nodeE, nodeF, false);
  push(nodeF, nodeD, false);
}