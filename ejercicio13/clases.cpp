

// getArea
// getPerimitro
// print
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Poligonos
{
public:
    virtual float getArea() = 0;
    virtual float getPerimetro() = 0;
    virtual void print() = 0;
};

class Triangulo : public Poligonos
{
private:
    int altura;
    int base;

public:
    float getArea() { return (base * altura * 0.5); }
    float getPerimetro() { return (base + altura + sqrt(base * base + altura * altura)); }
    void print()
    {
        cout << "Triangulo Altura " << altura << " Base: " << base << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimetro: " << getPerimetro() << endl;
    }
    Triangulo(int a, int b)
    {
        if (a < 0 || b < 0)
            cout << "Has puesto un valor menor que cero";
        else
        {
            altura = a;
            base = b;
        }
    }
};

class Circulo : public Poligonos
{
private:
    int radio;

public:
    Circulo(int r)
    {
        if (r < 0)
            cout << "Has puesto un valor menor que cero";
        else
            radio = r;
    }
    float getArea() { return (3.14 * radio * radio); }
    float getPerimetro() { return (2 * 3.14 * radio); }
    void print()
    {
        cout << "Circulo Radio " << radio << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimetro: " << getPerimetro() << endl;
    }
};

class Rectagulo : public Poligonos
{
private:
    int lado_largo;
    int lado_corto;

public:
    Rectagulo(int ll, int lc)
    {
        if (ll < 0 || lc < 0)
            cout << "Has puesto un valor menor que cero";
        else
        {
            lado_largo = ll;
            lado_corto = lc;
        }
    }
    float getArea() { return (lado_corto * lado_largo); }
    float getPerimetro() { return (lado_corto * 2 + lado_largo * 2); }
    void print()
    {
        cout << "Rectangulo Lado corto " << lado_corto << " Lado largo: " << lado_largo << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimetro: " << getPerimetro() << endl;
    }
};

int main()
{
    Triangulo t(12, 2);
    t.print();
    Circulo c(2);
    c.print();
    Rectagulo r(9, 6);
    r.print();
}