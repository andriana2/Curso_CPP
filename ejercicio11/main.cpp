#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct Node
{
    T data;
    vector<shared_ptr<Node<T>>> neighbors;
};

template <typename T>
shared_ptr<Node<T>> push(shared_ptr<Node<T>> head, shared_ptr<Node<T>> next, bool bidirecional = true)
{
    bool flag1{0};
    bool flag2{0};
    if (bidirecional)
    {
        for (auto &elem : head->neighbors)
        {
            if (elem == next)
                flag1 = true;
        }
        for (auto &elem : next->neighbors)
        {
            if (elem == head)
                flag2 = true;
        }
        if (flag1 && flag2)
            return head;
        else if (flag1 && !flag2)
            next->neighbors.push_back(head);
        else if (!flag1 && flag2)
            head->neighbors.push_back(next);
        else
        {
            next->neighbors.push_back(head);
            head->neighbors.push_back(next);
        }
    }
    else
    {
        for (auto &elem : head->neighbors)
        {
            if (elem == next)
                flag1 = true;
        }
        if(!flag1)
            head->neighbors.push_back(next);
    }
    return head;
}

int main()
{
    auto node1 = make_shared<Node<int>>(1);
    auto node2 = make_shared<Node<int>>(2);
    auto node3 = make_shared<Node<int>>(3);

    //push(node1, node2);
    push(node1, node3, false);
    push(node2, node3);
    push(node1, node3);
    push(node2, node3);


    cout << "Nodo " << node1->data << " está conectado a: ";
    for (const auto &neighbor : node1->neighbors)
    {
        cout << neighbor->data << " ";
    }
    cout << endl;

    cout << "Nodo " << node2->data << " está conectado a: ";
    for (const auto &neighbor : node2->neighbors)
    {
        cout << neighbor->data << " ";
    }
    cout << endl;

    cout << "Nodo " << node3->data << " está conectado a: ";
    for (const auto &neighbor : node3->neighbors)
    {
        cout << neighbor->data << " ";
    }
    cout << endl;

    return 0;
}