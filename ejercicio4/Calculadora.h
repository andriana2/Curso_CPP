#ifndef CALCULADORA_H
#define CALCULADORA_H

// punteros inteligentes
#include <iostream>
#include <memory> // para los punteros inteligentes
using namespace std;
#include <vector>
#include <string>

int suma(int a, int b);
shared_ptr<int> suma_punteros(shared_ptr<int> pA, shared_ptr<int> pB);
struct Persona
{
    string name;
    int age;
    bool underAge;
};

vector<shared_ptr<Persona>> mayor_edad(vector<shared_ptr<Persona>> personas);
bool estoy_dentro(vector<shared_ptr<Persona>> &v, shared_ptr<Persona> &person);

#endif