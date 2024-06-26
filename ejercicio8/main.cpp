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

struct Persona
{
    string name;
    int age;
    string id;
};
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

ostream &operator<<(ostream &os, const Persona &persona)
{
    if (typeid(os) == typeid(ofstream))
    {
        os << persona.name << " " << persona.age << " " << persona.id << endl;
    }
    else
    {
        os << "Nombre: " << persona.name << "\nEdad: " << persona.age << "\nID: " << persona.id << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const vector<Persona> &personas)
{
    if (typeid(os) == typeid(ofstream))
    {
        for (size_t i = 0; i < personas.size(); ++i)
        {
            os << personas[i];
        }
    }
    else
    {
        for (size_t i = 0; i < personas.size(); ++i)
        {
            os << "Persona " << i + 1 << ":" << endl;
            os << personas[i] << endl;
        }
    }
    return os;
}

istream &operator>>(istream &is, Persona &persona)
{
    cout << "Ingrese nombre: ";
    is >> persona.name;
    cout << "Ingrese edad: ";
    is >> persona.age;
    cout << "Ingrese ID: ";
    is >> persona.id;
    return is;
}

istream &operator>>(istream &is, vector<Persona> &personas)
{
    for (size_t i = 0; i < personas.size(); ++i)
    {
        cout << "Persona " << i + 1 << ":" << endl;
        is >> personas[i];
    }
    return is;
}

int main()
{
    vector<Persona> personas(3);
    cin >> personas;
    // escribir la matriz en un archivo
    ofstream archivo("data.txt");
    if (!archivo)
    {
        cout << "Error al abrir para escribir\n";
        return -1;
    }
    archivo << personas << endl;

    archivo.close();

    ifstream archivoLectura("data.txt");
    if (!archivoLectura)
    {
        cout << "Error al abrir para leer\n";
        return -1;
    }
    // archivoLectura >> archivo;// hay que hacerlo bien
    cout << personas;

    archivoLectura.close();

    return 1;
}

//______________operadores y ejercicio para imprimir y guarar matriz_________
// struct Point{
//     float x;
//     float y;
// };

// //Point operatos+(Point const &izquierda, Point const &derecha)
// Point operator+(Point const &a, Point const &b)
// {
//     return(Point{a.x + b.x, a.y + b.y});
// }

// ostream &operator << (ostream &os, Point const &p)
// {
//     os << "[" << p.x << ", "<< p.y << "]";
//     return(os);
// }//un ostream es una concatenacion cout<< "[" cout << p.x  cout << ", " etc asi funciona y lo necesitas al inicio y al final

// istream &operator>>(istream &is, Point &p)
// {
//     int x, y;
//     is >> p.x >> p.y;
//     return is;
// }

// // Función para dividir una cadena en elementos separados por un delimitador
// vector <string> split(string const &str, char separador)
// {
//     vector <string> resultado;
//     string temp{""};
//     bool flag_palabra{0};
//     for (int i{0}; i < str.size(); i++)
//     {
//         if (str.at(i) == separador)
//         {
//             if (flag_palabra == 1)
//             {
//                 resultado.push_back(temp);
//                 temp = "";
//             }
//             flag_palabra = 1;
//         }
//         else if (flag_palabra = 1)
//         {
//             temp = temp + str.at(i);
//         }
//     }
//     if (temp != "")
//         resultado.push_back(temp);
//     return (resultado);
// }

// int main() {
//     int matriz[3][3];
//     string elementos;
//     vector<string> vector_elementos;

//     cout << "Escribe los 9 elementos separados por un espacio: " << endl;
//     getline(cin, elementos); // cin con espacion lo considera otra cosa por eso
//                             // o pones "" o utilizas getline

//     vector_elementos = split(elementos, ' ');

//     if (vector_elementos.size() != 9) {
//         cout << "No hay nueve elementos hay "<< vector_elementos.size()  << endl;
//         return -1;
//     }

//     int k = 0;
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             matriz[i][j] = stoi(vector_elementos.at(k++));
//         }
//     }

//     ofstream miArchivo("matriz.txt");
//     if (!miArchivo) {
//         cout << "No se ha creado el archivo" << endl;
//         return -1;
//     }

//     miArchivo << "Matriz 3x3:" << endl;
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             miArchivo << matriz[i][j] << " ";
//         }
//         miArchivo << endl;
//     }
//     miArchivo.close();

//     ifstream archivoParaLeer("matriz.txt"); // ifstream abrir por lectura
//     if (!archivoParaLeer) {
//         cout << "No se ha podido abrir el archivo" << endl;
//         return -1;
//     }

//     string line;
//     while (getline(archivoParaLeer, line)) {
//         cout << line << endl;
//     }
//     archivoParaLeer.close();

//     return 0;
// }
//____________fin________________________________

//---------------version del profe:--------------------------------------------

// struct Matrix
// {
//   array<array<float, 3>, 3> data;
// };

// istream &operator>>(istream &is, Matrix &m)
// {
//   for (int r{0}; r < m.data.size(); r++)
//   {
//     for (int c{0}; c < m.data.at(r).size(); c++)
//     {
//       is >> m.data.at(r).at(c);
//     }
//   }
//   return is;
// }

// ostream &operator<<(ostream &os, Matrix const &m)
// {
//   if (typeid(os) == typeid(ofstream))
//   {
//     for (int r{0}; r < m.data.size(); r++)
//     {
//       for (int c{0}; c < m.data.at(r).size(); c++)
//       {
//         os << m.data.at(r).at(c) << " ";
//       }
//     }
//   }
//   else
//   {
//     for (int r{0}; r < m.data.size(); r++)
//     {
//       for (int c{0}; c < m.data.at(r).size(); c++)
//       {
//         os << m.data.at(r).at(c) << "\t";
//       }
//       os << endl;
//     }
//   }
//   return os;
// }

// int main()
// {
//   cout << "Introduce los 9 valores de la matriz ordenados por filas y columnas:\n";
//   Matrix miMatriz;
//   cin >> miMatriz;
//   // escribir la matriz en un archivo
//   ofstream archivo("data.txt");
//   if (!archivo)
//   {
//     cout << "Error al abrir para escribir\n";
//     return -1;
//   }

//   archivo << miMatriz << endl;

//   archivo.close();

//   ifstream archivoLectura("data.txt");
//   if (!archivoLectura)
//   {
//     cout << "Error al abrir para leer\n";
//     return -1;
//   }

//   archivoLectura >> miMatriz;

//   // leer la matriz de un archivo
//   cout << miMatriz;
//   return 1;
// }
//------------------------------------fin--------------------------------------

// int main()
// {
//     Point a{3,2};
//     ifstream archivoParaLeer("archivo.txt");//ifstream abrir por lectura
//     if(!archivoParaLeer)
//     {
//         cout << "no se ha podido abrer el archivo" << endl;
//         return -1;
//     }
//     string line;
//     while(getline(archivoParaLeer, line))
//     {
//         cout<< line <<endl;
//     }
//     archivoParaLeer.close();
// }

// fstream arvhivo("archivo.txt", ios::in | ios::out);//para leer y escribir

//------------para leer--------------------------------
// int main()
// {
//     Point a{3, 2};//ofstream abrir por lectura
//     ofstream miArchivo("ejemplo.txt");//que no se sobre escriba ofstream miArchivo("ejemplo.txt", ios::app);
//     if(!miArchivo)
//     {
//         cout<< "No se ha creado el archivo"<<endl;
//         return -1;
//     }
//     miArchivo << "Estoy guardando en el archivo" << endl;
//     miArchivo << "El punto es " << a << endl;
// }

// int main()
// {
//     Point a{3, 2};
//     cout << "El punto a es: " << a << endl;
//     cout << "Escribe el punto: ";
//     cin >> a;
//     cout << a << endl;
// }