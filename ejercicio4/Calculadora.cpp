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

bool estoy_dentro(vector<shared_ptr<Persona>> &v, shared_ptr<Persona> &person)
{
    for (const auto &vector_: v)
    {
        if (vector_ == person)
            return (true);
    }
    return (false);
}

bool estoy_includo_vector(vector<shared_ptr<Persona>> &vec, vector<shared_ptr<Persona>> &subvector)
{
    int contador{0};
    for (auto const &sv: subvector)
    {
        for (auto const &v: vec)
        {
            if (v == sv)
                contador++;
        }
    }
    if (contador == subvector.size())
        return (true);
    else
        return (false);
}

vector<shared_ptr<Persona>> interseccion(vector<shared_ptr<Persona>> &v1, vector<shared_ptr<Persona>> &v2)
{
    vector<shared_ptr<Persona>> resultado;

    for (auto &sv: v2)
    {
        if (estoy_dentro(v1, sv) == true)
        {
            resultado.push_back(sv);
        }
    }
    return (resultado);
}

vector<shared_ptr<Persona>> diferencia(vector<shared_ptr<Persona>> &v1, vector<shared_ptr<Persona>> &v2)
{
    vector<shared_ptr<Persona>> resultado;

    for (auto &sv: v2)
    {
        if (estoy_dentro(v1, sv) == false)
            resultado.push_back(sv);
    }
    for (auto &sv1: v1)
    {
        if (estoy_dentro(v2, sv1) == false)
            resultado.push_back(sv1);
    }
    return (resultado);
}

vector<shared_ptr<Persona>> Union(vector<shared_ptr<Persona>> &v1, vector<shared_ptr<Persona>> &v2)
{
    vector<shared_ptr<Persona>> resultado;
    resultado = v1;
    for (auto &sv: v2)
    {
        if (estoy_dentro(v1, sv) == false)
        {
            resultado.push_back(sv);
        }
    }
    return (resultado);
}