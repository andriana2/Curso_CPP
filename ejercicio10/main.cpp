#include "arbol.h"






//--------------------parte2----------------
// void printTree(const P_NodeData &node)
// {
// 	if (!node)
// 		return;
// 	printTree(node->left);
// 	cout << "ID " << node->data.id << "    Value " << node->data.value << endl;
// 	printTree(node->right);
// }

// int main()
// {
// 	P_NodeData root = nullptr;

// 	int id1 = uuid(4);
// 	int id2 = uuid(4);
// 	int id3 = uuid(4);
// 	int id4 = uuid(4);

// 	Data data1 = {10, id1};
// 	Data data2 = {20, id2};
// 	Data data3 = {5, id3};
// 	Data data4 = {8, id4};

// 	push_s(root, data1);
// 	push_s(root, data2);
// 	push_s(root, data3);
// 	push_s(root, data4);


// 	cout << "ARBOL" << endl;
// 	printTree(root);

// 	P_NodeData result = find_s(root, id4);

// 	if (result)
// 	{
// 		cout << "Encontramos ID: " << result->data.id << ", Value: " << result->data.value << endl;
// 	}
// 	else
// 	{
// 		cout << "No encontramos ID " << id4 << endl;
// 	}


// 	P_NodeData result_1 = find_s(root, id2);
// 	if (result_1)
// 	{
// 		cout << "Encontramos ID: " << result_1->data.id << ", Value: " << result_1->data.value << endl;
// 	}
// 	else
// 	{
// 		cout << "No encontramos ID " << id2 << endl;
// 	}
// 	return 0;
// }