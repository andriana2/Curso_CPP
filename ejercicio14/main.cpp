#include <iostream>
#include <memory>
#include <vector>
#include "figuras.h"

// el dinamic cast es para un valor 
using namespace std;

int menu()
{
	int num;
	cout << "Que quieres hacer" << endl;
	cout << "1 Añadir" << endl;
	cout << "2 Mostrar" << endl;
	cin >> num;
	return (num);
}

int menu_figuras_push()
{
	int num;
	cout << "Que figura quieres añadir:" << endl;
	cout << "\t 3 Triangulo" << endl;
	cout << "\t 4 Cuatrado" << endl;
	cout << "\t 5 Pentagono" << endl;
	
	cin >> num;
	return (num);
}
int menu_figuras_ver()
{
	int num;
	cout << "Que figura quieres ver:" << endl;
	cout << "\t 3 Triangulo" << endl;
	cout << "\t 4 Cuatrado" << endl;
	cout << "\t 5 Pentagono" << endl;
	cout << "\t 6 Todas" <<endl;
	
	cin >> num;
	return (num);
}

shared_ptr<FiguraGeometricaReg> push(vector<shared_ptr<FiguraGeometricaReg>> fig, float lado, int num)
{
	shared_ptr<FiguraGeometricaReg> resultado;

	if(num == 3){}
		//fig.push_back(make_shared)
}


int main()
{
	int numero_menu;
	int numero_figura;
	vector<shared_ptr<FiguraGeometricaReg>> fig;

	while(true)
	{
		numero_menu = menu();
		if(numero_menu == 1){}
			// push()
		else if(numero_menu == 2){}
			//show
		else {
			cout << "te confundiste de numero";
			break;
		}
	}
}

// int main()
// {
// 	// Crear shared_ptr de Cuadrado con lado 5
// 	shared_ptr<Cuadrado> c = make_shared<Cuadrado>(Cuadrado{5});
// 	// Crear shared_ptr de TrianguloEq con lado 5
// 	shared_ptr<TrianguloEq> t = make_shared<TrianguloEq>(5);

// 	// Vector de shared_ptr de FiguraGeometricaReg
// 	vector<shared_ptr<FiguraGeometricaReg>> fig;
// 	fig.push_back(c);
// 	fig.push_back(t);
// 	fig.at(0)->queSoy();
// 	fig.at(1)->queSoy();

// 	cout << dynamic_cast<Cuadrado *>(fig.at(0).get())->getLado() << endl;



// 	// if (auto triangulo = dynamic_pointer_cast<TrianguloEq>(fig.at(1)))
// 	// {
// 	// 	cout << "Altura del Triángulo: " << triangulo->getAltura() << endl;
// 	// }
// 	// else
// 	// {
// 	// 	cout << "No se pudo hacer el cast a TrianguloEq" << endl;
// 	// }

// 	// // Intentar hacer el cast de TrianguloEq a Cuadrado (debería fallar)
// 	// if (dynamic_pointer_cast<TrianguloEq>(fig.at(1)) != nullptr)
// 	// {
// 	// 	cout << "El elemento en fig.at(1) es un TrianguloEq" << endl;
// 	// }
// 	// else
// 	// {
// 	// 	cout << "El elemento en fig.at(1) no es un TrianguloEq" << endl;
// 	// }
// }

// int main() {
//     // Crear un cuadrado con lado 5
//     Cuadrado c{5};
//     // Crear un triángulo equilátero con lado 3
//     TrianguloEq t{3};
//     // Crear un pentágono con lado 4 y apotema 2.5
//     Pentagono p{4, 2.5};

//     // Mostrar detalles del cuadrado
//     c.queSoy();
//     std::cout << "Lado: " << c.getLado() << std::endl;
//     std::cout << "Perímetro: " << c.getPerimetro() << std::endl;
//     std::cout << "Área: " << c.getArea() << std::endl;
//     std::cout << "Diagonal: " << c.detDiagonal() << std::endl;

//     // Mostrar detalles del triángulo equilátero
//     t.queSoy();
//     std::cout << "Lado: " << t.getLado() << std::endl;
//     std::cout << "Perímetro: " << t.getPerimetro() << std::endl;
//     std::cout << "Área: " << t.getArea() << std::endl;
//     std::cout << "Altura: " << t.getAltura() << std::endl;

//     // Mostrar detalles del pentágono
//     p.queSoy();
//     std::cout << "Lado: " << p.getLado() << std::endl;
//     std::cout << "Perímetro: " << p.getPerimetro() << std::endl;
//     std::cout << "Área: " << p.getArea() << std::endl;

//     return 0;
// }
