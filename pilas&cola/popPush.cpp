#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//prototipos

struct Nodo{
	char info;
	Nodo*sgte;
};

void push(Nodo*&, char); 
char pop(Nodo*&);


int main(int argc, char** argv) {
	return 0;
}


void push(Nodo*&pila, char caracter){
	Nodo*nodo_nuevo= new Nodo(); 
	nodo_nuevo->info = caracter;
	nodo_nuevo->sgte=pila; 
	pila= nodo_nuevo;
	return;
}; 

char pop(Nodo*&pila){
	char caracter; 
	Nodo*aux= pila; 
	caracter = aux->info; 
	pila= aux->sgte;
	delete aux; 
	return caracter;
	
};
