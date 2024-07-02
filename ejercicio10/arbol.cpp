#include "arbol.h"
// bst binary search tree arboles binarios de busqueda

P_Node_St push(P_Node_St &head, shared_ptr<st> data, function<int(shared_ptr<st>)> f)
{
	if(!head){
		head = make_shared<Node_st>(Node_st{data, nullptr, nullptr});
 		return head;
	}
	if (f(head->data) == f(data))
		return (head);
	if (f(head->data) > f(data))
		return push(head->left, data, f);
	else
		return push(head->right, data, f);

}

P_Node_St find_st(P_Node_St &head, shared_ptr<st> data, function<int(shared_ptr<st>)> f)
{
	if(!head)
		return (nullptr);
	if (f(head->data) == f(data))
		return (head);
	if (f(head->data) > f(data))
		return find_st(head->left, data, f);
	else
		return find_st(head->right, data, f);

}




//----------------parte2---------------


// P_NodeData &push_s(P_NodeData &head, Data data)
// {
// 	if (!head)
// 	{
// 		head = make_shared<Node_Data>(Node_Data{data, nullptr, nullptr});
// 		return head;
// 	}
// 	if (head->data.id > data.id)
// 	{
// 		head->left = push_s(head->left, data);
// 	}
// 	else
// 	{
// 		head->right = push_s(head->right, data);
// 	}
// 	return head;
// }

// P_NodeData find_s(P_NodeData const &head, int id)
// {
// 	if (!head)
// 		return nullptr;
// 	if (head->data.id == id)
// 		return head;
// 	if (head->data.id > id)
// 		return find_s(head->left, id);
// 	else
// 		return find_s(head->right, id);
// }

// int uuid(int size)
// {
// 	int uuid = 0;
// 	for (int i = 0; i < size; i++)
// 	{
// 		uuid *= 10;
// 		uuid += (rand() % 9);
// 	}
// 	return uuid;
// }


//------------------parte1-----------
// P_Node &push(P_Node &head, int data)
// {
// 	if (!head)
// 	{
// 		head = make_shared<Node>(Node{data, nullptr, nullptr});
// 		return head;
// 	}
// 	if (head->data > data)
// 	{
// 		head->left = push(head->left, data);
// 		return head;
// 	}
// 	else
// 	{
// 		head->right = push(head->right, data);
// 		return head;
// 	}
// }

// P_Node find(P_Node const &head, int data)
// {
// 	if (!head)
// 		return nullptr;
// 	if (head->data == data)
// 		return head;
// 	if (head->data > data)
// 		return find(head->left, data);
// 	else
// 		return find(head->right, data);
// }