#include "Calculadora.h"

bool estoy_dentro(vector<shared_ptr<Persona>> &v, shared_ptr<Persona> &person)
{
    for (const auto &vector_: v)
    {
        if (vector_ == person)
            return (true);
    }
    return (false);
}

int main()
{
    vector<shared_ptr<Persona>> personas;
    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    personas.push_back(p2);
    personas.push_back(make_shared<Persona>(Persona{"Alice", 17, false}));
    personas.push_back(make_shared<Persona>(Persona{"Alice", 19, false}));
    cout << estoy_dentro(personas, p1) << endl;
    cout << estoy_dentro(personas, p2) << endl;

}




// int main() {

//     vector<shared_ptr<Persona>> personas;
//     // Crear un vector de personas
//     personas.push_back(make_shared<Persona>(Persona{"Alice", 17, false}));
//     personas.push_back(make_shared<Persona>(Persona{"Alice0", 19, false}));
//     personas.push_back(make_shared<Persona>(Persona{"Alice1", 16, false}));
//     personas.push_back(make_shared<Persona>(Persona{"Alice2", 20, false}));
//     personas.push_back(make_shared<Persona>(Persona{"Alice3", 122, false}));
//     personas.push_back(make_shared<Persona>(Persona{"Alice4", 17, false}));

//     auto mayores = mayor_edad(personas);

//     // Imprimir los nombres de las personas mayores de edad
//     cout << "Personas mayores de edad:" << endl;
//     for (const auto& persona : mayores) {
//         cout << persona->name << " (" << persona->age << " años) " << persona->underAge << endl;
//     }
//     cout << "Todos:" << endl;

//     for (const auto& persona : personas) {
//         cout << persona->name << " (" << persona->age << " años) " << persona->underAge << endl;
//     }

//     return 0;
// }
