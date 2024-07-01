#include "menu.h"

void borrar(PNode &head)
{
    string id_main;
    cout << "Que id quieres borrar" << endl;
    forEach(head, [](Student const &st)
            { cout << st.id << endl; });
    cin >> id_main;
    auto f = [&id_main](Student const &st)
    { return st.id == id_main; };
    PNode new_node = delete_node(head, f);
    forEach(new_node, [](Student const &st)
            { cout << st.id << endl; });
}
void aniadir(PNode &head)
{
    string asignaturas;
    string nombre;
    Student s;
    cout << "nombre persona a añadir:" << endl;
    cin.ignore();
    getline(cin, nombre);
    s.name = parseName("name " + nombre);
    cout << "asignaturas separalas con comas:" << endl;
    cin.ignore();
    getline(cin, asignaturas);
    s.subjects = parseSubjects("subjects " + asignaturas);
    s.id = uuid(5);
    push(head, s);
}

void buscar(PNode &head)
{
    string nombre;
    cout << "Nombre de la persona que buscas:" << endl;
    getline(cin, nombre);
    nombre = parseName("name " + nombre);
    auto f = [&nombre](Student const &st)
    { return st.name == nombre; };
    auto found = find(head, f);
    cout << found->data << endl;
}

void saveToFile(string filename, PNode const &head)
{
    ofstream archivo(filename);
    if (!archivo)
    {
        throw std::runtime_error("No se pudo abrir el archivo");
    }
    forEach(head, [&archivo](Student p)
            { archivo << p << endl; });
    archivo.close();
}

void leer(PNode &head)
{
    string archivo;
    cout << "Nombre del archivo: " << endl;
    cin >> archivo;
    saveToFile(archivo, head);
}

void mostrar(PNode &head)
{
    auto it = head;
    while (it)
    {
        cout << it->data << endl;
        it = it->next;
    }
}
int menu()
{
    int numero_agenda;
    cout << "\n\n\n";
    std::cout << "===================================" << std::endl;
    std::cout << "   Menu de Gestion de Agenda   " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "Por favor, selecciona una opcion: " << std::endl;
    std::cout << "  1. Borrar" << std::endl;
    std::cout << "  2. Añadir" << std::endl;
    std::cout << "  3. Buscar" << std::endl;
    std::cout << "  4. Mostrar" << std::endl;
    std::cout << "  5. Leer" << std::endl;
    std::cout << "  6. Guardar" << std::endl;
    std::cout << " -1. Salir" << std::endl;
    std::cout << "===================================" << std::endl;
    cin >> numero_agenda;
    return numero_agenda;
}
