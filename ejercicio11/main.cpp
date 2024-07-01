#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car
{
  string brand;
  string plate;
};

struct Person
{
  string name;
  int age;
  string dni;
  string email;
  //Car car;
};

void printPerson(Person const &p)
{
  cout << "Nombre: " << p.name << "\n";
  cout << "Edad: " << p.age << endl;
}

void menorEdad(vector<Person> const &p)
{
    for(const auto& persona: p){
        if (persona.age > 17)
            cout<< "Nombre mayor de edad " << persona.name <<endl;
    }
}

int main()
{
  Person alberto{"Alberto", 18, "123456789J", "alberto.valero@bq.com"};
  Person maria{"Maria", 20, "123436789J", "maria@bq.com"};
  Person luis{"Luis", 11, "123436789J", "maria@bq.com"};
  Person jesus{"Jesús", 21, "123436789J", "maria@bq.com"};
  Person ana{"Ana", 12, "123436789J", "maria@bq.com"};
  vector<Person> personas{alberto,maria, luis, jesus, ana};
  menorEdad(personas);
  
  return 0;
}