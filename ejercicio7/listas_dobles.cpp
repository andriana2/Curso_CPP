#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <cstdlib>

using namespace std;

struct Node
{
    string id;
    int data;
    shared_ptr<Node> next;
    shared_ptr<Node> prev;
};

using P_Node = shared_ptr<Node>;

string uuid()
{
    string id = "";
    for (int i = 0; i < 5; i++)
    {
        id += 'a' + rand() % 26;
    }
    return id;
}

P_Node insertBefore(P_Node const &it, int data)
{
    P_Node node = make_shared<Node>(Node{uuid(), data, it, it->prev});
    it->prev->next = node;
    it->prev = node;
    return it;
}

P_Node push_back(P_Node &head, int data)
{
    if (!head)
    {
        P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, nullptr});
        return node;
    }
    P_Node temp{head};
    while (temp->next)
    {
        temp = temp->next;
    }
    // estoy en el ultimo
    P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, temp});
    temp->next = node;
    return head;
}

P_Node push_front(P_Node &head, int data) {
    if (!head) {
        P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, nullptr});
        head = node;
        return head;
    }
    P_Node node = make_shared<Node>(Node{uuid(), data, head, nullptr});
    head->prev = node;
    head = node;
    return head;
}

P_Node push_at(P_Node &head, int data, int pos)
{
    if (pos < 0)
        throw out_of_range("Invalid Position");
    if (pos == 0)
        return push_front(head, data);
    if (!head && pos != 0)
        throw out_of_range("Invalid Position");
    auto it = head;
    int index{0};
    while (it->next)
    {
        index++;
        it = it->next;
        if (pos == index)
        {
            P_Node node = insertBefore(it, data);
            return head;
        }
    }
    throw out_of_range("Invalid position. Greater then list.");
}

P_Node push_in_order(P_Node &head, int data, int posm, bool asc = true)
{
    if (!head)
    {
        P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, nullptr});
        return node;
    }
    auto it = head;
    while (it->next)
    {
        auto condition = asc ? it->next->data < data : it->next->data > data;
        if (condition)
        {
            it = it->next;
        }
        else
        {
            P_Node node = insertBefore(it, data);
            return head;
        }
    }
    push_back(head, data);
    return (head);
}

P_Node pop_back(P_Node &head)
{
    if (!head) return nullptr;
    auto it{head};
    if (!head->next)
    {
        auto aux = head;
        head = nullptr;
        return aux;
    }
    while(it->next)
    {
        it = it->next;
    }
    it->prev->next = nullptr;
    it->prev = nullptr;
    return it;
}

P_Node pop_front(P_Node &head) {
    if (!head) return nullptr;
    if (!head->next)
    {
        auto aux = head;
        head = nullptr;
        return aux;
    }
    auto it = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    it->next = nullptr;
    return it;
}

void printList(P_Node head) {
    while (head) {
        cout << "[" << head->id << ": " << head->data << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    P_Node head = nullptr;

    // Adding elements to the list
    head = push_back(head, 10);
    head = push_back(head, 20);

    head = push_front(head, 5);
    head = push_at(head, 15, 2);
    head = push_in_order(head, 17, true);

    // Printing the list
    cout << "List after insertions: ";
    printList(head);

    // Removing elements from the list
    P_Node back = pop_back(head);
    cout << "Removed from back: " << back->id << ": " << back->data << endl;

    P_Node front = pop_front(head);
    cout << "Removed from front: " << front->id << ": " << front->data << endl;

    // Printing the final list
    cout << "Final list: ";
    printList(head);

    return 0;
}
