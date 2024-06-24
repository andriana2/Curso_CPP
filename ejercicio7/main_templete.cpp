//listas enlazadas

#include <memory>

using namespace std;


template <typename T>
struct Node {
    T data;
    shared_ptr<Node<T>> next;
};

template <typename T>
using P_Node = shared_ptr<Node<T>>;

template <typename T>
P_Node<T> push(P_Node<T> first, T data) {
    P_Node<T> temp = first;
    while (temp->next) {
        temp = temp->next;
    }
    P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr});
    temp->next = nNode;
    return nNode;
}

template <typename T>
P_Node<T> push_r(P_Node<T> first, T data) {
    if (first->next)
        return push_r(first->next, data);
    P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr});
    first->next = nNode;
    return nNode;
}

// void imprimir_elem(P_Node first)
// {

// }


int main(){
    //P_Node start<int> = make_shared<Node<int>>(Node<int>{1, nullptr});//MAL
    P_Node<int> start = make_shared<Node<int>>(Node<int>{1, nullptr});
    push(start, 2);
    push(start, 3);
    push(start, 4);
    push(start, 5);


}