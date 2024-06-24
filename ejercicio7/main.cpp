//listas enlazadas

#include <memory>
#include <iostream>
#include <functional>
using namespace std;
struct Node
{
    int data;
    shared_ptr<Node> next;
};
typedef shared_ptr<Node> P_Node;

P_Node push(P_Node first, int data)
{
    P_Node temp = first;
    while(temp->next)
    {
        temp = temp->next;
    }
    P_Node nNode = make_shared<Node>(Node{data, nullptr});
    temp->next = nNode;
    return nNode;
}
P_Node push_r(P_Node first, int data)
{
    if(first->next)
        return (push_r(first->next, data));
    P_Node nNode = make_shared<Node>(Node{data, nullptr});
    first->next = nNode;
    return nNode;
}

void imprimir_elems(P_Node first)
{
    P_Node temp = first;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;
}
void imprimir_recursivo(P_Node first)
{
    if (first)
    {
        cout << first->data << " ";
        return(imprimir_recursivo(first->next));
    }
    cout <<endl;
}
void forEach(P_Node first, function<void(P_Node)> const &f)
{
    P_Node temp = first;
    while(temp)
    {
        f(temp);
        temp = temp->next;
    }
}
void delete_node(P_Node first, P_Node eliminar)
{
    P_Node temp{first};
    P_Node node1;
    int flag{0};
    while(temp)
    {
        if (flag == 1)
        {
            node1->next = temp->next;
            flag = 0;
        }
        else if (temp->next == eliminar)
        {
            node1 = temp;
            flag = 1;
        }
        temp = temp->next;
    }
}
//borrar añadir buscar(nombre contiene esas letras en orden y imprimir) y mostrar todos(nombre telefono uid)


int main(){
    P_Node start = make_shared<Node>(Node{1, nullptr});
    push(start,2);
    push(start,3);
    P_Node node4 = push(start,4);
    push(start,5);
    push(start,6);
    delete_node(start, node4);
    imprimir_elems(start);
    imprimir_recursivo(start);
    forEach(start, [](P_Node a){ cout << a->data << " ";});
    cout << endl;



}