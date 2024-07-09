#pragma once
// Cuando tenemos una funcion pura no se puede declarar
#include <string>

class FiguraGeometricaReg
{
public:
    FiguraGeometricaReg(int nlados, float lado);

    void setnlados(int n);
    void setLado(float l);

    int getnlados() const;
    float getLado() const;

    float getPerimetro() const;

    virtual float getArea() const = 0;
    virtual void queSoy() const;

protected:
    int nlados;
    float lado;
};

class Cuadrado : public FiguraGeometricaReg
{
public:
    Cuadrado(float lado);
    float detDiagonal() const;
    float getArea() const override;
    void queSoy() const override;
};

class TrianguloEq : public FiguraGeometricaReg
{
public:
    TrianguloEq(float lado);
    float getArea() const override;
    float getAltura() const;
    void queSoy() const override;
};

class Pentagono : public FiguraGeometricaReg
{
public:
    Pentagono(float lado, float apotema);
    float getArea() const override;
    void queSoy() const override;
    // implementar setlado dependiente del apotema
private:
    float apotema;
};