#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <limits>

// funciona para el push no set
using namespace std;

template <typename T>
struct Node
{
    T data;
    set<shared_ptr<Node<T>>> neighbors;
};

template <typename T>
shared_ptr<Node<T>> push(shared_ptr<Node<T>> &n1, shared_ptr<Node<T>> &n2, bool bidirecional = true)
{
    n1->neighbors.insert(n2);
    if(bidirecional)
        n2->neighbors.insert(n1);
    return n1;
}













//----------------sin set----------------


// template <typename T>
// shared_ptr<Node<T>> push(shared_ptr<Node<T>> head, shared_ptr<Node<T>> next, bool bidirecional = true)
// {
//     bool flag1{0};
//     bool flag2{0};
//     if (bidirecional)
//     {
//         for (auto &elem : head->neighbors)
//         {
//             if (elem == next)
//                 flag1 = true;
//         }
//         for (auto &elem : next->neighbors)
//         {
//             if (elem == head)
//                 flag2 = true;
//         }
//         if (flag1 && flag2)
//             return head;
//         else if (flag1 && !flag2)
//             next->neighbors.push_back(head);
//         else if (!flag1 && flag2)
//             head->neighbors.push_back(next);
//         else
//         {
//             next->neighbors.push_back(head);
//             head->neighbors.push_back(next);
//         }
//     }
//     else
//     {
//         for (auto &elem : head->neighbors)
//         {
//             if (elem == next)
//                 flag1 = true;
//         }
//         if(!flag1)
//             head->neighbors.push_back(next);
//     }
//     return head;
// }
