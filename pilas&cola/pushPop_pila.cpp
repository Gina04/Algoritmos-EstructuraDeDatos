#include <iostream>
using namespace std; 

struct Nodo{
	int info; 
	Nodo*sgte;
}
//prototipos
void push(Nodo*&, int);
int pop(Nodo*&); // esto cambia depende del tipo de dato de la info de mi struct 

int main(int argc, char** argv) {
	return 0;
}

void push(Nodo*& pila, int valor){
	Nodo * aux = new Nodo(); //creo un nodo llamado aux
	aux->info = valor; // accedo al struct y cargo valor
	aux->sgte = pila; //enlazo con la estructura enlazada
	pila = aux;//vuelvo a apuntar al primer nodo
	
	return;
}

int pop(Nodo*&pila){
	int v;// auxiliar que utilizamos para devolver el valor de struct que vamos a eliminar
	Nodo*aux = pila; // apunta a donde apunta pila
	v = aux->info; // pasamos el valor del struct a v
	pila = aux->sgte; //pila apunta al sgte de aux porque a ese elem lo vamos a borrar
	delete aux;
    return v;	
}
