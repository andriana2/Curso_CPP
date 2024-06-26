// listas enlazadas

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <array>
#include <random>
#include <memory>
using namespace std;
struct Node
{
    int numero;
    string nombre;
    string id;
    shared_ptr<Node> next;
};
typedef shared_ptr<Node> P_Node;

string generateRandomID()
{
    const string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string id;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, letters.size() - 1);

    for (int i = 0; i < 5; ++i)
    {
        id += letters[distribution(generator)];
    }
    return id;
}

P_Node push(P_Node first, int telefono, string nombre)
{
    P_Node temp = first;
    while (temp->next)
    {
        temp = temp->next;
    }
    P_Node nNode = make_shared<Node>(Node{telefono, nombre, generateRandomID(), nullptr});
    temp->next = nNode;
    return nNode;
}
P_Node push_con_id(P_Node first, int telefono, string nombre, string id)
{
    P_Node temp = first;
    while (temp->next)
    {
        temp = temp->next;
    }
    P_Node nNode = make_shared<Node>(Node{telefono, nombre, id, nullptr});
    temp->next = nNode;
    return nNode;
}

void imprimir_elems(P_Node first, int filtro = 0)
{
    P_Node temp = first;
    int i{1};
    while (temp)
    {
        if (filtro == 0)
        {
            cout << i << ". " << temp->id << endl;
            temp = temp->next;
        }
        else
        {
            cout << i << ". " << temp->nombre << endl;
            temp = temp->next;
        }
        i++;
    }
}
void imprimir_elems_todos(P_Node first)
{
    P_Node temp = first;
    while (temp)
    {
        cout << "Nombre " << temp->nombre << endl
             << "Telefono " << temp->numero << endl
             << "ID " << temp->id << endl;
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
    while (temp)
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
    while (temp)
    {
        if (temp->nombre.find(nombre) != -1)
        {
            cout << "Nombre " << temp->nombre << endl
                 << "Telefono " << temp->numero << endl
                 << "ID " << temp->id << endl;
        }
        temp = temp->next;
    }
}

void modificar(P_Node &first, int numero)
{
    int i{1};
    P_Node temp{first};
    int num;
    while (i <= numero || temp == nullptr)
    {
        if (i == numero)
        {
            cout << "¿Que quieres modificar?" << endl
                 << "1. Nombre" << endl
                 << "2. Telefono" << endl;
            cin >> num;
            if (num == 1)
            {
                string nombre;
                cout << "nombre nuevo: ";
                cin >> nombre;
                temp->nombre = nombre;
                break;
            }
            else if (num == 2)
            {
                int nume;
                cout << "numero nuevo: ";
                cin >> nume;
                temp->numero = nume;
                break;
            }
        }
        temp = temp->next;
        i++;
    }
}
// borrar
// añadir
// buscar(nombre contiene esas letras en orden y imprimir)
//  y mostrar todos(nombre telefono uid)

ostream &operator<<(ostream &os, const P_Node &head)
{
    P_Node temp{head};
    if (typeid(os) == typeid(ofstream))
    {
        while (temp)
        {
            os << temp->nombre << " " << temp->numero << " " << temp->id << endl;
            temp = temp->next;
        }
    }
    else
    {
        int i{0};
        while (temp)
        {
            os << "Persona " << i + 1 << ":" << endl;
            os << "Nombre: " << temp->nombre << "\nEdad: " << temp->numero << endl;
            temp = temp->next;
            i++;
        }
    }
    return os;
}

istream& operator>>(istream& is, P_Node& head) {
    string nombre;
    int numero;
    string id;

    is >> nombre >> numero >> id;
    if (!is.fail()) {
        P_Node newNode = make_shared<Node>(Node{numero, nombre, id, nullptr});
        if (!head) {
            head = newNode;
        } else {
            P_Node temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return is;
}
P_Node leer() {
    P_Node head = nullptr;
    ifstream archivoLectura("contactos.txt");
    if (!archivoLectura) {
        cout << "Error al abrir para leer\n";
        exit(EXIT_FAILURE);
    }
    while (!archivoLectura.eof()) {
        archivoLectura >> head;
    }
    return head;
}
int guardar(const P_Node &head)
{
    ofstream archivo("contactos.txt");
    if (!archivo)
    {
        cout << "Error al abrir para escribir\n";
        return -1;
    }

    archivo << head << endl;

    archivo.close();
    return 0;
}

int main()
{
    int numero_agenda{0};
    string id_main;
    P_Node start = make_shared<Node>(Node{666777888, "Ana", generateRandomID(), nullptr});
    while (true)
    {
        cout << "\n\n\n";
        cout << "Que quieres hacer pon el numero a continuacion: " << endl;
        cout << "1 Borrar" << endl;
        cout << "2 Añadir" << endl;
        cout << "3 Buscar" << endl;
        cout << "4 Mostrar" << endl;
        cout << "5 Modificar" << endl;
        cout << "6 Leer" << endl;
        cout << "7 Guardar" << endl;
        cout << "-1 Para salir" << endl;
        cin >> numero_agenda;
        cout << endl;
        if (numero_agenda == -1)
            break;
        else if (numero_agenda == 1)
        {
            imprimir_elems(start);
            cout << "Que id quieres borrar" << endl;
            cin >> id_main;
            delete_node(start, id_main);
        }
        else if (numero_agenda == 2)
        {
            int tele;
            string nombre;
            cout << "nombre persona a añadir:" << endl;
            cin >> nombre;
            cout << "telefono persona a añadir:" << endl;
            cin >> tele;
            push(start, tele, nombre);
        }
        else if (numero_agenda == 4)
        {
            imprimir_elems_todos(start);
        }
        else if (numero_agenda == 3)
        {
            string nombre;
            cout << "nombre persona que buscas:" << endl;
            cin >> nombre;
            search(start, nombre);
        }
        else if (numero_agenda == 5)
        {
            int numero;
            imprimir_elems(start, 1);
            cout << "Que numero de la lista quieres modificar" << endl;
            cin >> numero;
            modificar(start, numero);
        }
        else if (numero_agenda == 6) // leer
        {
            start = leer();
        }
        else if (numero_agenda == 7) // guardar
        {
            if (guardar(start) == -1)
                return -1;
        }
        else
            cout << "Te has confundido con el numero";
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