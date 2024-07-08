#include <iostream>
#include <string>

using namespace std;

class Alumnos
{
protected:
    int matricula;
    string nombre;
    string apellido;
public:
    Alumnos(int m, string nom, string a){
        if(m < 0)
            cout << "No es matriculado" << endl;
        else
            matricula = m;
        nombre = nom;
        apellido = a;
    }

    virtual void print() {
        cout << "Matricula: " << matricula << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
    }
};

class Alumnos_Estrella : public Alumnos
{
public:
    Alumnos_Estrella(int m, string nom, string a, float nota)
        : Alumnos(m, nom, a), nota_media(nota) { }

    void print() override {
        Alumnos::print();
        cout << "Nota Media: " << nota_media << endl;
    }
private:
    float nota_media;
};

int main() {
    Alumnos_Estrella alumno(12345, "Juan", "Perez", 9.5);
    alumno.print();
    return 0;
}

