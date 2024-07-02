#pragma once
// arboles binarios ordenados
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>

using namespace std;

struct Node_st;
using P_Node_St = shared_ptr<Node_st>;

struct st{
	int const value;//se muestra el valor
	int const id;//se busca por id 
	bool sayYes;
	int suma;
	float resta;
};

struct Node_st
{
	shared_ptr<st> data;
	shared_ptr<Node_st> left;
	shared_ptr<Node_st> right;
};

P_Node_St find_st(P_Node_St &head, st data, function<int(shared_ptr<st>)> f);



//---------------parte2----------------------
// struct Node_Data;
// using P_NodeData = shared_ptr<Node_Data>;


// struct Data{
// 	int value;//se muestra el valor
// 	int id;//se busca por id 
// };

// struct Node_Data
// {
// 	Data data;
// 	shared_ptr<Node_Data> left;
// 	shared_ptr<Node_Data> right;
// };


// P_NodeData &push_s(P_NodeData &head, Data data);
// P_NodeData find_s(P_NodeData const &head, int id);
// int uuid(int size);


//---------------parte1----------------
struct Node;
using P_Node = shared_ptr<Node>;
struct Node
{
	int data;
	shared_ptr<Node> left;
	shared_ptr<Node> right;
};
// P_Node &push(P_Node &head, int data);
// P_Node find(P_Node const &head, int data);

