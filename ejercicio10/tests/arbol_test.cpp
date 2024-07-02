#include <gtest/gtest.h>
#include "arbol.h"
#include <string>
#include <vector>
using namespace std;

TEST(ArbolTest, Funcion_Arbol) {
    P_Node head = nullptr;
    push(head,10);
    push(head,5);
    push(head,6);
    push(head,12);
    push(head,30);
    push(head,2);
    EXPECT_EQ(head->data, 10);
    EXPECT_EQ(head->left->data, 5);
    EXPECT_EQ(head->left->right->data, 6);
    EXPECT_EQ(head->right->data, 12);
    EXPECT_EQ(head->right->right->data, 30);
    EXPECT_EQ(head->right->right->right, nullptr);
    EXPECT_EQ(head->right->right->left, nullptr);
    EXPECT_EQ(head->left->left->data, 2);
    EXPECT_EQ(head->left->left->left, nullptr);
    EXPECT_EQ(head->left->left->right, nullptr);
}

