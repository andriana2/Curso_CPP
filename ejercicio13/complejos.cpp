#include <iostream>
#include <string>

using namespace std;

class Complejo
{

    float real;
    float im;

    friend Complejo operator+(Complejo const &c1, Complejo const &c2);
    friend istream &operator>>(istream &is, Complejo &c1);
    friend ostream &operator<<(ostream &os, Complejo const &c1);
    friend Complejo operator-(Complejo const &c1, Complejo const &c2);

public:
    Complejo(float real, float im) : real{real}, im{im} {}
    float getImaginario() const { return im; }
    float getReal() const { return real; }
    void setImaginario(float i) { im = i; }
    void setReal(float r) { real = r; }
};

istream &operator>>(istream &is, Complejo &c1)
{
    is >> c1.real;
    is >> c1.im;
    return is;
}
ostream &operator<<(ostream &os, Complejo const &c1)
{
    os << c1.real << " " << c1.im << "j" << endl;
    return os;
}

Complejo operator+(Complejo const &c1, Complejo const &c2)
{
    return Complejo(c1.real + c2.real, c1.im + c2.im);
}
Complejo operator-(Complejo const &c1, Complejo const &c2)
{
    return Complejo(c1.real - c2.real, c1.im - c2.im);
}
// Complejo operator+(Complejo const &c1, Complejo const &c2){
//     return Complejo(c1.getReal()+ c2.getReal(), c1.getImaginario() + c2.getImaginario());
// } //sin ser amigos

int main()
{
    Complejo c1(0,0);
    Complejo c2(0,0);

    cout << "Introude la parte real y acontinucacion la parte imaginaria" << endl;
    cin >> c1;
    cout << "Introude la parte real y acontinucacion la parte imaginaria" << endl;
    cin >> c2;
    cout << "RESTA: " << c1 - c2 << endl
         << "SUMA:" << c2 + c1 << endl;
}