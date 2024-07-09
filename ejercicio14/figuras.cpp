#include "figuras.h"

#include <iostream>
#include <cmath>

using namespace std;

// Implementación de la clase FiguraGeometricaReg

FiguraGeometricaReg::FiguraGeometricaReg(int nlados, float lado) : nlados(nlados), lado(lado) {}

void FiguraGeometricaReg::setnlados(int n) { nlados = n; }

void FiguraGeometricaReg::setLado(float l) { lado = l; }

int FiguraGeometricaReg::getnlados() const { return nlados; }

float FiguraGeometricaReg::getLado() const { return lado; }

float FiguraGeometricaReg::getPerimetro() const { return nlados * lado; }

void FiguraGeometricaReg::queSoy() const { cout << "Soy una figura geometrica regular" << endl; }

// Implementación de la clase Cuadrado

Cuadrado::Cuadrado(float lado) : FiguraGeometricaReg(4, lado) {}

float Cuadrado::detDiagonal() const { return lado * sqrt(2); }

void Cuadrado::queSoy() const { cout << "Soy un cuadrado" << endl; }
float Cuadrado::getArea() const { return lado * lado; }

// Implementación de la clase TrianguloEq

TrianguloEq::TrianguloEq(float lado) : FiguraGeometricaReg(3, lado) {}

float TrianguloEq::getArea() const { return (sqrt(3) / 4) * lado * lado; }

float TrianguloEq::getAltura() const { return (sqrt(3) / 2) * lado; }

void TrianguloEq::queSoy() const { cout << "Soy un triángulo equilátero" << endl; }

// Implementacion de la clase Pentagono

Pentagono::Pentagono(float lado, float apo) : FiguraGeometricaReg(5, lado), apotema(apo) {}

float Pentagono::getArea() const { return (getPerimetro()) * apotema * 0.5; }

void Pentagono::queSoy() const { cout << "Soy un pentagono equilátero" << endl; }