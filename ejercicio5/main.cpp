//nullptr es el null de una ptr
//funciones lambda 
//para que funcionan [] en las funciones lambda
//vp nuevoVector; // esta fuera de los {} de las diferentes funciones
// forEach(miVector, [](shared_ptr<Persona> p) {nuevoVector.push_back(p);});// no reconoce nada que no este entre los corchetes
// forEach(miVector, [&](shared_ptr<Persona> p) {nuevoVector.push_back(p);});// paso por referncia 
// forEach(miVector, [=](shared_ptr<Persona> p) {nuevoVector.push_back(p);});// paso por referencia constante
//un ejemplo [&nuevo,b] //nuevo por referencia y b por referencia constante


#include <functional>
#include <iostream>
#include <memory> // para los punteros inteligentes
using namespace std;
#include <vector>
#include <string>

struct Persona
{
    string name;
    int age;
};
typedef vector<int> vi;
typedef vector<shared_ptr<Persona>> vp;

typedef function<void(int)> flambda;
// typedef function<bool(int)> blambda;
typedef function<void(shared_ptr<Persona>)> personalambda;
typedef function<bool(shared_ptr<Persona>)> bpersonalambda;


void forEach(vi const &v, flambda const &f)
{
    for(auto const &elem : v)
    {
        f(elem);
    }
}

int main ()
{
    int f1 {1};
    int f2 {1};
    int f3 {2};
    vector <int> resultado;
    cout << "Indice fibonacci ";
    int indice;
    cin >>indice;
    resultado.push_back(f1);
    for (int i {0}; i < indice - 1; i++)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
        resultado.push_back(f1);
    }
    int suma{0};
    forEach(resultado, [](int a){ cout << a << " ";});
    cout << endl;
    forEach(resultado, [&suma](int a){suma = a + suma; cout << suma << " ";});
    cout << endl;


}

/*shared_ptr<Persona> find_(vp const &p, bpersonalambda const & f)
{
    for(auto const &elem : p)
    {
        if (f(elem))
        {
            return (elem);
        }
    }
    return nullptr;
}
void forEach(vp const &p, personalambda const &f)
{
    for(auto const &elem : p)
    {
        f(elem);
    }
}
bool some(vp const &p, bpersonalambda const &f)
{
    for(auto const &elem : p)
    {
        if (f(elem))
            return true;
    }
    return false;
}
bool every(vp const &p, bpersonalambda const &f)
{
    for(auto const &elem : p)
    {
        if (f(elem))
            return false;
    }
    return true;
}
vp filter(vp const &p, bpersonalambda const &f)
{
    vp resultado;
    for(auto const &elem: p)
    {
        if (f(elem))
        {
            resultado.push_back(elem);
        }
    }
    return resultado;
}

vp trasform(vp const &p,function<shared_ptr<Persona>(shared_ptr<Persona>)> const &f)
{
    vp resultado;
    for(auto const &elem: p)
    {
        shared_ptr<Persona> copia = make_shared<Persona>(*elem);
        resultado.push_back(f(copia));
    }
    return resultado;
}

int main()
{
    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"A", 20});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Ae", 16});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Ale", 34});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alie", 17});
    vp miVector{p1,p2,p3,p4};
    forEach(miVector, [](shared_ptr<Persona> p){cout << p->name << " ";});
    cout << endl;
    cout << some(miVector, [](shared_ptr<Persona> p){return (p->age <18);});
    cout << endl;
    cout << every(miVector, [](shared_ptr<Persona> p){return (p->age >=18);});
    cout << endl;

    vp vp1 = filter(miVector, [](shared_ptr<Persona> a)
    { return (a->age > 17); });
    cout << "Mayores de edad:"<<endl;

    for (auto const &f : vp1)
        cout << f->name << "     " <<f->age << endl;
    cout << "fin filter"<<endl;
    
    cout << "FELIZ CUMPLEAÑOS A TODOS-> Cumplis:"<<endl;
    vp vp2 = trasform(miVector, [](shared_ptr<Persona> a){ a->age++; return (a); });
    for (auto const &f : vp2)
        cout << f->name << " " <<f->age <<" " << endl;
    cout << endl;
    cout << endl;
    shared_ptr<Persona> puntero= find_(miVector, [](shared_ptr<Persona> a){ return(a->age < 18); });
    cout << puntero->name << " " <<puntero->age <<" " << endl;
    cout << endl;
    cout << endl;

    //vp nuevoVector;
    // forEach(miVector, [](shared_ptr<Persona> p) {nuevoVector.push_back(p);});// no reconoce nada que no este entre los corchetes
    // forEach(miVector, [&](shared_ptr<Persona> p) {nuevoVector.push_back(p);});// paso por referncia 
    // forEach(miVector, [=](shared_ptr<Persona> p) {nuevoVector.push_back(p);});// paso por referencia constante

    return 0;
}*/


/*
bool some(vi const &v, blambda const &f)
{
    for(auto const &elem : v)
    {
        if (f(elem) == true)
            return true;
    }
    return false;
}
bool every(vi const &v, blambda const &f)
{
    for(auto const &elem : v)
    {
        if (!f(elem))
            return false;
    }
    return true;
}
vi filter(vi const &v, blambda const &f)
{
    vi resultado;
    for(auto elem: v)
    {
        if (f(elem))
            resultado.push_back(elem);
    }
    return resultado;
}
vi trasform(vi const &v,function<int(int)> const &f)
{
    vi resultado;
    for(auto elem: v)
        resultado.push_back(f(elem));
    return resultado;
}

int main()
{
    flambda print = [](int a)
    {
        if (a % 2 == 0)
            cout << a << " ";
    };
    blambda booleano = [](int a)
    { return (a > 10); };
    vi miVector{1,2,3,4,5,6,7,8,9,10};
    forEach(miVector, print);
    cout << endl;
    cout << some(miVector, booleano);
    cout << endl;
    cout << every(miVector, [](int a)
    { return (a != 1); });
    cout << endl;

    vi v1 = filter(miVector, [](int a)
    { return (a > 5); });
    vi v2 = trasform(miVector, [](int a)
    { return (a * 2); });
    for (auto const &f : v1)
        cout << f << " ";
    cout << endl;
    
    for (auto const &f : v2)
        cout << f << " ";
    cout << endl;
    cout << endl;
    return 0;
}*/






//ejemplo inicial lambda
// int operacion(int a, int b, function<int(int, int)> f)
// {
//     cout << f(a,b) << endl;
//     return f(a,b);
// }

// int main()
// {
//     function<int (int, int)> suma = [](int a, int b){return (a + b);};
//     function<int (int, int)> resta = [](int a, int b){return (a - b);};
//     function<int (int, int)> multiplicacion = [](int a, int b){return (a * b);};

//     auto h1 = operacion(1,2,suma);
//     auto h2 = operacion(1,2,resta);
//     auto h3 = operacion(1,2,multiplicacion);

    
// }


