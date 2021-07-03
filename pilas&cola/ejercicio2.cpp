#include <iostream>
using namespace std;

/* 
Dada una pila y un valor I, desarrollar un procedimiento que inserte I como tercer valor de la pila.
(Definir parámetros y codificar).

*/


struct Nodo{
	int info; 
	Nodo* sgte;
};

//prototipos
void push(Nodo*&, int);
int pop(Nodo*&);


int main() {
	Nodo * pila = NULL;
	Nodo*pilaAux= NULL;
	
	int i, valor; 

	//cargo la pila 1
	for(i=0; i<4; i++){
		cout<< "Valor:"; 
    	cin>> valor;
		push(pila, valor);
	}
	
	//Desapilo los dos primeros nodos considerando es una pila de 4 nodos;
	
	for(int j=0; j<2; j++){
		//despilo pila1 y apilo pilaAux 
		push(pilaAux, pop(pila)); 
	}
	
	//apilo el valor para que quede en la tercera posicion 
	
	cout<< "Ingreso tercer valor:";
	cin>> valor;
   	push(pila, valor);
	
	//desapilo la pilaAux y vuelvo apilar en la pila
	
	for(int i=0; i<2; i++){
	 push(pila, pop(pilaAux));
	}
	
	//muestro la pila con su tercer valor insertado
	
	for(int i=0; i<5; i++){
		cout<< pop(pila)<< endl;
	}
	
	return 0;
}

void push(Nodo* &pila, int valor){
	
	Nodo * nuevo_nodo = new Nodo();
	nuevo_nodo ->info = valor; 
	nuevo_nodo -> sgte = pila;
	pila = nuevo_nodo; 
}
int pop(Nodo*&pila){
	int v;
	Nodo * aux = pila; 
	v = aux-> info;
	pila = aux-> sgte;
	delete aux;
	return v;
}
