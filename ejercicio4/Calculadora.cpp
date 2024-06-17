#include "Calculadora.h"

int suma(int a, int b){ return(a + b); }
shared_ptr<int> suma_punteros(shared_ptr<int> pA,shared_ptr<int> pB)
{
    shared_ptr<int> pResultado = make_shared<int>(*pA + *pB);
    return (pResultado);
}

vector<shared_ptr<Persona>> mayor_edad(vector<shared_ptr<Persona>> personas)
{
    vector<shared_ptr<Persona>> pResultado;

    for(auto &p : personas)
    {
        if (p->age >= 18)
        {
            p->underAge = true;
            pResultado.push_back(p);
        }   
    }
    return (pResultado);
}