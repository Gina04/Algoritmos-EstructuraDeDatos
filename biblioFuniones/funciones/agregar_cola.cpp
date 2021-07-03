#include <iostream>
struct Nodo{
	int info; 
	Nodo*sgte;
}

//Prototipos
void agregar_cola(Nodo*&, Nodo*&, int);


int main(int argc, char** argv) {
	Nodo*fte = NULL;
	Nodo*fin = NULL;
	agregra_cola(fte,fin,5);
	
	return 0;
}

void agregar_cola(Nodo*&fte, Nodo*&fin, int v){
	Nodo* nuevo_nodo = new Nodo(); 
	nuevo_nodo->info =v; 
	nuevo_nodo->sgte = NULL;
	if(fte==NULL){
		fte=nuevo_nodo;
	} else{
		fin->sgte = nuevo_nodo;
	}
	fin = nuevo_nodo;
	
}
