#include "student.h"
#include "node.h"
#include "menu.h"

int main(){
	int flag;
	PNode head = nullptr;
	while(true)
	{
		int numero = menu();
		switch (numero)
		{
		case 1: borrar(head); break;
		case 2: aniadir(head); break;
		case 3: buscar(head); break;
		case 4: mostrar(head); break;		
		default: numero = -1; break;
		}
		if(numero == -1)break;
	}

	return 0;
}

// int main()
// {
//   Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
//   Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
//   PNode head = nullptr;
//   push(head, st1);
//   push(head, st2);

//   forEach(head, [](Student const &st)
//           { cout << st << endl; });

//   return 1;
// }