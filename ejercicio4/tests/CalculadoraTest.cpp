#include <gtest/gtest.h>
#include "Calculadora.h"
#include <string>
#include <vector>
using namespace std;

TEST(CalculadoraTest, SumaValida) {
    const int input1 = 2;
    const int input2 = 3;
    const int expected = 5;
    EXPECT_EQ(suma(input1, input2), expected);
}

TEST(CalculadoraTest, SumaValida2) {
    shared_ptr<int> pInput1 = make_shared<int>(2);
    shared_ptr<int> pInput2 = make_shared<int>(3);
    shared_ptr<int> pExpected = make_shared<int>(5);

    shared_ptr<int> pResultado = suma_punteros(pInput1, pInput2);

    EXPECT_EQ(*pResultado, *pExpected);
}

TEST(CalculadoraTest, TRUE_TEST)
{
    vector<shared_ptr<Persona>> personas;
    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    personas.push_back(p2);

    EXPECT_EQ(estoy_dentro(personas, p2), true);
}

TEST(CalculadoraTest, FALSE_TEST)
{
    vector<shared_ptr<Persona>> personas;
    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    personas.push_back(p2);

    EXPECT_EQ(estoy_dentro(personas, p1), false);
}

TEST(CalculadoraTest, True_TEST_subvector)
{
    vector<shared_ptr<Persona>> vec;
    vector<shared_ptr<Persona>> subvector;

    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alice", 17, false});
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    vec.push_back(p4);
    subvector.push_back(p2);
    subvector.push_back(p1);
    EXPECT_EQ(estoy_includo_vector(vec, subvector), true);
}

TEST(CalculadoraTest, FALSE_TEST_subvector)
{
    vector<shared_ptr<Persona>> vec;
    vector<shared_ptr<Persona>> subvector;

    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alice", 17, false});
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    subvector.push_back(p2);
    subvector.push_back(p4);
    EXPECT_EQ(estoy_includo_vector(vec, subvector), false);
}

TEST(CalculadoraTest, TEST_interseccion_bien)
{
    vector<shared_ptr<Persona>> vec;
    vector<shared_ptr<Persona>> subvector;
    vector<shared_ptr<Persona>> resultado;


    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alice", 17, false});
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    subvector.push_back(p2);
    subvector.push_back(p4);
    resultado.push_back(p2);
    EXPECT_EQ(interseccion(vec, subvector), resultado);
}

TEST(CalculadoraTest, TEST_interseccion_bien_2)
{
    vector<shared_ptr<Persona>> vec;
    vector<shared_ptr<Persona>> subvector;
    vector<shared_ptr<Persona>> resultado;
    vector<shared_ptr<Persona>> comparacion;
    


    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alice", 17, false});
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    vec.push_back(p4);
    subvector.push_back(p4);
    subvector.push_back(p2);

    resultado.push_back(p4);
    resultado.push_back(p2);
    comparacion= interseccion(vec, subvector);

    EXPECT_EQ(comparacion.size(), 2);
    EXPECT_TRUE(estoy_includo_vector(resultado, comparacion));
}

TEST(CalculadoraTest, TEST_union_bien)
{
    vector<shared_ptr<Persona>> vec;
    vector<shared_ptr<Persona>> subvector;
    vector<shared_ptr<Persona>> resultado;
    vector<shared_ptr<Persona>> comparacion;


    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alice", 17, false});
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    subvector.push_back(p2);
    subvector.push_back(p4);
    resultado.push_back(p1);
    resultado.push_back(p2);
    resultado.push_back(p3);
    resultado.push_back(p4);
    
    comparacion = Union(vec,subvector);

    EXPECT_EQ(comparacion.size(), 4);
    EXPECT_TRUE(estoy_includo_vector(resultado, comparacion));
}

TEST(CalculadoraTest, TEST_diferencia_bien)
{
    vector<shared_ptr<Persona>> vec;
    vector<shared_ptr<Persona>> subvector;
    vector<shared_ptr<Persona>> comparacion;
    vector<shared_ptr<Persona>> resultado;


    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Alice", 17, false});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alice", 17, false});
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    subvector.push_back(p4);
    resultado.push_back(p1);
    resultado.push_back(p2);
    resultado.push_back(p3);
    resultado.push_back(p4);
    comparacion = diferencia(vec,subvector);

    EXPECT_EQ(comparacion.size(), 4);
    EXPECT_TRUE(estoy_includo_vector(resultado, comparacion));
}

TEST(CalculadoraTest, TEST_diferencia_bien_2)
{
    vector<shared_ptr<Persona>> vec;
    vector<shared_ptr<Persona>> subvector;
    vector<shared_ptr<Persona>> comparacion;
    vector<shared_ptr<Persona>> resultado;


    shared_ptr<Persona> p1 = make_shared<Persona>(Persona{"A", 17, false});
    shared_ptr<Persona> p2 = make_shared<Persona>(Persona{"Ae", 17, false});
    shared_ptr<Persona> p3 = make_shared<Persona>(Persona{"Ale", 17, false});
    shared_ptr<Persona> p4 = make_shared<Persona>(Persona{"Alie", 17, false});
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    subvector.push_back(p3);
    resultado.push_back(p1);
    resultado.push_back(p2);

    comparacion = diferencia(vec,subvector);
    EXPECT_EQ(comparacion.size(), 2);
    EXPECT_TRUE(estoy_includo_vector(resultado, comparacion));
}
// TEST(CalculadoraTest, NoIniciaConParentesis) {
//     const std::string input = "hola(que)(tal)";
//     EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
// }

// TEST(CalculadoraTest, ParentesisNoBalanceados) {
//     const std::string input = "(hola)(que(tal)";
//     EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
// }

// TEST(CalculadoraTest, NoTerminaConParentesisCerrado) {
//     const std::string input = "(hola)(que))(tal";
//     EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
// }

// TEST(CalculadoraTest, ParentesisVacios) {
//     const std::string input = "(hola)()";
//     EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
// }

// TEST(CalculadoraTest, TextoFueraDeParentesis) {
//     const std::string input = "(hola)que(tal)";
//     EXPECT_THROW(GestionParentesis(input), std::invalid_argument);
// }
