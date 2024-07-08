#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <algorithm>

using namespace std;


struct Coordinates
{
    int x;
    int y;
};

struct Node;

struct Edge
{
    shared_ptr<Node> node;
    float distance;
};

struct Node
{
    Coordinates data;
    float distacia_min = INT8_MAX;
    set<Edge> neighbors;
    float cost = INT8_MAX;
    shared_ptr<Node> prev;
};

float operator-(Coordinates const &c1, Coordinates const &c2);
bool operator<(Edge const &e1, Edge const &e2);

void push(shared_ptr<Node> &n1, shared_ptr<Node> &n2, bool bidirecional = true);
void dijkstra(shared_ptr<Node> &start, vector<shared_ptr<Node>> nodes);
void estrella(shared_ptr<Node> &start, shared_ptr<Node> &end, vector<shared_ptr<Node>> nodes);

