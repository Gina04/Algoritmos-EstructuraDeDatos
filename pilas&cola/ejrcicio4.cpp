#include <iostream>
using namespace std;


/* 
Dada una pila y dos valores X e I, desarrollar un procedimiento que inserte el valor X en la
posición I de la pila si es posible. (Definir parámetros y codificar).

 */
 

 
Struct Nodo{
	int info; 
	Nodo* sgte;
} 
 //prototipos
 
 void push(Nodo*&, int); 
 int pop(Nodo*&);

int main(int argc, char** argv) {
	return 0;
}

//defino los prototipos 
void push(Nodo*& pila, int valor){
 	Nodo* nodo = new Nodo();
 	nodo->info = valor; 
 	nodo->sgte = pila; 
 	pila = nodo;
 
 	return;
  	
 }
 
 int pop(Nodo* & pila){
 	int valor; 
 	Nodo* aux = pila;
 	valor = aux->info;
 	pila = aux->sgte;
 	delete aux;
 	return valor;
 }
