#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>

using namespace std;

struct Node
{
    char nombre;//quien soy
    vector<vector<string>> letra_coste; //matriz donde el 0 es letra y 1 es coste cuest ir stoi
    int coste_start;// cuanto cuesta empezar
    //char donde_vengo;// donde vengo
    set<shared_ptr<Node>> neighbors;
};

struct Grafo
{
    set<shared_ptr<Node>> grafo_st;
};

shared_ptr<Node> push(shared_ptr<Node> &n1, shared_ptr<Node> &n2, bool bidirecional = true);