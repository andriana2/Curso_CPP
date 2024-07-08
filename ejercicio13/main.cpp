#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
	string name;
	int age;

public:
//get
	string getName(){return name;}
	int getAge(){return age;}
//set
	void setName(string n){name = n;}
	void setAge(int a){age = a;}
//funciones
	void cumple();
	void print();
//constructor
	Person(string n, int e)
	{
		if(e < 0)
			e = 0;
		name = n;
		age = e;
	}
//constructor sin parametros
	Person()
	{
		age = 0;
		name = "";
	}
};

void Person::cumple()
{
	age++;
}

void Person::print()
{
	cout << "Nombre: " << name << endl;
	cout << "Edad: " << age << endl;

}

int main()
{
	Person persona("Juan", 12);
}
