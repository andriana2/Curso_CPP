#pragma once
#include "node.h"
#include "student.h"
#include "utils.h"
#include <fstream>

void borrar(PNode &head);
void aniadir(PNode &head);
void buscar(PNode &head);
void mostrar(PNode &head);

void saveToFile(string filename,PNode const &head);

int menu();


