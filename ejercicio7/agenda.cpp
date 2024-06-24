//listas enlazadas

#include <memory>
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <random>
using namespace std;
struct Node
{
    int numero;
    string nombre;
    string id;
    shared_ptr<Node> next;
};
typedef shared_ptr<Node> P_Node;


string generateRandomID() {
    const  string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string id;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, letters.size() - 1);

    for (int i = 0; i < 5; ++i) {
        id += letters[distribution(generator)];
    }
    return id;
}

P_Node push(P_Node first, int telefono, string nombre)
{
    P_Node temp = first;
    while(temp->next)
    {
        temp = temp->next;
    }
    P_Node nNode = make_shared<Node>(Node{telefono, nombre, generateRandomID(), nullptr});
    temp->next = nNode;
    return nNode;
}

void imprimir_elems(P_Node first)
{
    P_Node temp = first;
    int i{1};
    while(temp)
    {
        cout << i << ". " << temp->id << endl;
        temp = temp->next;
        i++;
    }
}
void imprimir_elems_todos(P_Node first)
{
    P_Node temp = first;
    while(temp)
    {
        cout << "Nombre " << temp->nombre << endl <<"Telefono "<< temp->numero<<endl << "ID " <<temp->id << endl;
        temp = temp->next;
    }
}

void delete_node(P_Node &first, string eliminar)
{
    P_Node temp{first};
    P_Node node1;
    int flag{0};
    if (first->id == eliminar)
        first = first->next;
    while(temp)
    {
        if (flag == 1)
        {
            node1->next = temp->next;
            flag = 0;
        }
        else if (temp->next->id == eliminar)
        {
            node1 = temp;
            flag = 1;
        }
        temp = temp->next;
    }
}
void search(P_Node &first, string nombre)
{
    P_Node temp = first;
    while(temp)
    {
        if(temp->nombre.find(nombre) != -1)
        {
            cout << "Nombre " << temp->nombre << endl <<"Telefono "<< temp->numero<<endl << "ID " <<temp->id << endl;
        }
        temp = temp->next;
    }
}
//borrar 
//añadir 
//buscar(nombre contiene esas letras en orden y imprimir)
// y mostrar todos(nombre telefono uid)




int main(){
    int numero_agenda{0};
    string id_main;
    P_Node start = make_shared<Node>(Node{666777888, "Ana", generateRandomID(), nullptr});
    while (true)
    {
        cout <<"\n\n\n"<< "Que quieres hacer pon el numero a continuacion: " <<endl << "1. Borrar"<<endl << "2. Añadir"<<endl << "3. Buscar"<<endl << "4. Mostrar" <<endl << "-1. Para salir" <<endl;
        cin >> numero_agenda;
        cout << endl;
        if(numero_agenda == -1)
            break;
        else if(numero_agenda < 0 || numero_agenda > 4)
            cout << "Te has confundido con el numero";
        else if(numero_agenda == 1)
        {
            imprimir_elems(start);
            cout << "Que id quieres borrar"<<endl;
            cin >> id_main;
            delete_node(start, id_main);
        }
        else if (numero_agenda == 2)
        {
            int tele;
            string nombre;
            cout << "nombre persona a añadir:"<< endl;
            cin >> nombre;
            cout << "telefono persona a añadir:"<< endl;
            cin >> tele;
            push(start,tele, nombre);
        }
        else if (numero_agenda == 4)
        {
            imprimir_elems_todos(start);
        }
        else if (numero_agenda == 3)
        {
            string nombre;
            cout << "nombre persona que buscas:"<< endl;
            cin >> nombre;
            search(start, nombre);

        }

    }
    // P_Node start = make_shared<Node>(Node{1, nullptr});
    // push(start,2);
    // push(start,3);
    // P_Node node4 = push(start,4);
    // push(start,5);
    // push(start,6);
    // delete_node(start, node4);
    // imprimir_elems(start);
    // imprimir_recursivo(start);
    // //forEach(start, [](P_Node a){ cout << a->data << " ";});
    // cout << endl;



}