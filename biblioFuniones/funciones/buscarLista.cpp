#include <iostream>
//Prototipo
struct Alumno{
	int nota; 
	char nombre[10]; 
	int edad;
};
nodo* buscar(nodo* lista,Alumno x);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}

nodo* buscar(nodo* lista,Alumno x)
{
	nodo* p=lista;
	while(p!=NULL && p->info.dni!=x.dni){
		p=p->sgte;
	}
		
	return p;
}

