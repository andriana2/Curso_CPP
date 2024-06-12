#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> soccer(string str)
{
    vector <string> resultado;
    int num_abierto{0};
    bool flag_abierto{0};
    int num_cerrado{0};
    int abierto_inicio;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
        {
            flag_abierto = 1;
            num_abierto++;
            if (num_abierto == 1)
            {
                abierto_inicio = i;
            }
        }
        if (str.at(i) == ')')
        {
            if(flag_abierto == 1 && num_abierto == 1)
            {
                num_abierto = 0;
                flag_abierto = 0;
                cout << str.substr(abierto_inicio + 1, i - abierto_inicio - 1)<< endl;
                resultado.push_back(str.substr(abierto_inicio + 1, i - abierto_inicio - 1));
            }
            num_cerrado++;
            if ((num_abierto - num_cerrado) == 0)
            {
                num_abierto = 0;
                num_cerrado = 0;
                cout << str.substr(abierto_inicio + 1, i - abierto_inicio - 1)<< endl;
                resultado.push_back(str.substr(abierto_inicio + 1, i - abierto_inicio - 1));

            }
        }
    }
    return (resultado);
    
}

int main()
{
    //_________ej2__________
    vector <string> cadena(soccer("((hola)(que))(tal)(estas)"));
        

    return (0);
}













// int main()
// {
//     //--------------------ejercicio 1-----------------
//     string name{"Andri se ha ido de paseo"};
//     int i = 1;
//     int num = 0;

//     while (i > 0)
//     {
//         int found = name.find(" ", num);
//         if (found == -1)
//             i = 0;
//         else
//         {
//             name.at(found) = '_';
//             num = found;
//         }
//     }
//     cout << name << endl;
//     //---------------------fin ejercicio 1----------------------

//     //--------------------ejercicio 2-----------------
//     string str1{"Andri se ha ido de paseo"};
//     string str2{" Andri se ha ido a la playa"};
//     string str3{" Andri esta durimiendo"};

//     str1 = str1 + str2 + str3;
//     cout << str1 << endl;
//     //---------------------fin ejercicio 2----------------------

//     //--------------------ejercicio 3-----------------
//     string cadena_original{"El viaje estuvo chachi, te lo pasanste bien, no"};
//     string subcadena_busco{"no"};
//     string subcadena_reemplazo{"si"};
//     int busca_cadena = cadena_original.find(subcadena_busco);
//     if (busca_cadena == -1)
//         cout << "No se encontro la palabra buscada" << endl;
//     else{
//         cadena_original.erase(busca_cadena, subcadena_busco.size());
//         cadena_original.insert(busca_cadena,subcadena_reemplazo);
//         cout << cadena_original << endl;
//     }
//     //---------------------fin ejercicio 3----------------------
    
//     //--------------------ejercicio 4-----------------
//     string cadena_invertir{"no me gustan las medusas"};
//     string cadena_temporal = cadena_invertir;
//     string cadena_nueva;
//     for(auto &letra: cadena_invertir)
//     {
//         cadena_nueva = cadena_nueva + cadena_temporal.back();
//         cadena_temporal.pop_back();
//     }
//     cout << cadena_nueva << endl;


//     //---------------------fin ejercicio 4----------------------

//     //--------------------ejercicio 5-----------------
//     string string_vocales{"Todos tenemos un amigo"};
//     int contar_vocales{0};
//     for(const auto &letras: string_vocales)
//     {
//         if(letras == 'a' || letras == 'e' || letras == 'i' || letras == 'o' || letras == 'u')
//             contar_vocales ++;
//     }

//     cout << contar_vocales << endl << endl;
//     //---------------------fin ejercicio 5----------------------
//     //--------------------ejercicio 6-----------------

//     string cmp1{"es igual"};
//     string cmp2{"es igual"};
//     if (cmp2 == cmp1)
//         cout << "es igual"<< endl << endl;
//     else
//         cout << "no es igual"<< endl << endl;
//     //---------------------fin ejercicio 6----------------------


//     //--------------------ejercicio 7-----------------
//     string str4{"Todos tenemos un amigo"};
//     string str5;
//     char subcadena_caracter{'a'};
//     int letra_a_encontrar = str4.find(subcadena_caracter);
//     if (letra_a_encontrar != -1)
//     {
//         str5 = str4.substr(0, letra_a_encontrar);
//         cout << str5 << endl << endl;
//     }
//     //---------------------fin ejercicio 7----------------------
    
//     //--------------------ejercicio 8-----------------
//     //string_vocales{"Todos tenemos un amigo"};
//     // string string_nuevo = string_vocales;
//     // vector<int> numeros_vocales; 
//     // int contador{0};
//     // for(const auto &letras: string_vocales)
//     // {
//     //     if(letras == 'a' || letras == 'e' || letras == 'i' || letras == 'o' || letras == 'u')
//     //         numeros_vocales.push_back(i);
//     //     i++;
//     // }
//     // for(const auto &l: numeros_vocales)
//     // {

//     // }
//     // cout <<  << endl << endl;
//     //---------------------fin ejercicio 8----------------------

//     //--------------------ejercicio 9-----------------
//     string str7{"Todos lo HACEMOs BIen"};
//     for (auto &s: str7)
//     {
//         if (s >= 97 && s <= 122)
//             s = s - 32;
//     }
//     cout << str7 << endl << endl;
//     //---------------------fin ejercicio 9----------------------
//     //--------------------ejercicio 10-----------------
//     // string str8{"buenos dias que tal estas"};
//     // int cont{0};
//     // int flag{0};
//     // int flag_letra{0};
//     // for (int i{0}; i < str8.size(); i++)
//     // {
//     //     if (str8.at(i) == ' ')
        
        
//     // }
//     // cout << str7 << endl << endl;
//     //---------------------fin ejercicio 10----------------------

//     return 0;


// }