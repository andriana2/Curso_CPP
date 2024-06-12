#include <iostream>
#include <string>

using namespace std;

int main()
{
    //--------------------ejercicio 1-----------------
    string name{"Andri se ha ido de paseo"};
    int i = 1;
    int num = 0;

    while (i > 0)
    {
        int found = name.find(" ", num);
        if (found == -1)
            i = 0;
        else
        {
            name.at(found) = '_';
            num = found;
        }
    }
    cout << name << endl;
    //---------------------fin ejercicio 1----------------------

    //--------------------ejercicio 2-----------------
    string str1{"Andri se ha ido de paseo"};
    string str2{" Andri se ha ido a la playa"};
    string str3{" Andri esta durimiendo"};

    str1 = str1 + str2 + str3;
    cout << str1 << endl;
    //---------------------fin ejercicio 2----------------------

    //--------------------ejercicio 3-----------------
    string cadena_original{"El viaje estuvo chachi, te lo pasanste bien, no"};
    string subcadena_busco{"no"};
    string subcadena_reemplazo{"si"};
    int busca_cadena = cadena_original.find(subcadena_busco);
    if (busca_cadena == -1)
        cout << "No se encontro la palabra buscada" << endl;
    else{
        cadena_original.erase(busca_cadena, subcadena_busco.size());
        cadena_original.insert(busca_cadena,subcadena_reemplazo);
        cout << cadena_original << endl;
    }
    //---------------------fin ejercicio 3----------------------
    
    //--------------------ejercicio 4-----------------
    string cadena_invertir{"no me gustan las medusas"};
    string cadena_temporal = cadena_invertir;
    string cadena_nueva;
    for(auto &letra: cadena_invertir)
    {
        cadena_nueva = cadena_nueva + cadena_temporal.back();
        cadena_temporal.pop_back();
    }
    cout << cadena_nueva << endl;


    //---------------------fin ejercicio 4----------------------

    
    return 0;


}