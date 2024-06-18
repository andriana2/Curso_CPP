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
