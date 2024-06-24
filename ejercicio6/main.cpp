// templete
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

template <typename T>
T suma(T a, T b)
{
    return a + b;
}

template <typename T>
void forEach(vector<T> const &v, function<void(T)> const &f)
{
    for (auto const &elem : v)
    {
        f(elem);
    }
}
template <typename T>
bool every(vector<T> const &v, function<bool(T)> const &f)
{
    for (auto const &elem : v)
    {
        if (!f(elem))
            return false;
    }
    return true;
}
template <typename T>
vector<T> filter(vector<T> const &v, function<bool(T)> const &f)
{
    vector<T> resultado;
    for (auto elem : v)
    {
        if (f(elem))
            resultado.push_back(elem);
    }
    return resultado;
}
template <typename T>
vector<T> trasform(vector<T> const &v, function<T(T)> const &f)
{
    vector<T> resultado;
    for (auto elem : v)
        resultado.push_back(f(elem));
    return resultado;
}

typedef vector<int> vi;
typedef vector<string> vs;

typedef function<void(int)> flambda;

int main()
{
    // template <typename T>
    auto z = suma<int>(3, 4);                // Corrección: los parámetros de plantilla están bien aquí
    auto b = suma<string>("hola", " mundo"); // Corrección: agregar el espacio después de "hola"
    cout << "Suma de enteros: " << z << endl;
    cout << "Concatenación de cadenas: " << b << endl;

    // template <typename T>
    // void forEach(vector<T> const &v, function<void(T)> const &f)
    // typedef vector<int> vi;

    vi vect{1, 2, 3, 4, 5, 6};
    forEach<int>(vect, [](int a)
                 { cout << a << " "; });
    cout << endl;

    vector<string> vecStr{"hola", "que", "tal", "hola"};
    forEach<string>(vecStr, [](string a)
                    { cout << a << " "; });
    cout << endl;

    cout << every<int>(vect, [](int a)
                       { return (a != 1); });
    cout << endl;

    cout << every<string>(vecStr, [](string a)
                          { return (a != "hola"); });
    cout << endl;

    vi v1 = filter<int>(vect, [](int a)
                        { return (a > 5); });
    auto s1 = filter<string>(vecStr, [](string a)
                             { return (a != "hola"); });

    vi v2 = trasform<int>(vect, [](int a)
                          { return (a * 2); });

    auto s2 = trasform<string>(vecStr, [](string a)
                               { return (a + " mundo"); });

    return 0;
}
