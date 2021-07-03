#include <iostream>
#include <stdlib.h>
using namespace std;

/* 
Dada una cola (nodo = registro + puntero), imprimirla en orden natural si tiene mas de 100 nodos,
caso contrario imprimirla en orden inverso.
*/

struct Nodo{
	int info; // modificar resgistro
	Nodo * sgte;
};

//Prototipos
void push(Nodo*&, int);
int pop(Nodo*&);
void agregar_cola(Nodo*&, Nodo*&, int);
int suprimir_cola(Nodo*&, Nodo*&);
 
int main() {
	Nodo * fte = NULL;
	Nodo * fin = NULL; 
	Nodo * pila = NULL;
	int i;
	
	/* cargo la cola con valores random...*/
	
	for(i=0; i < 100; i++){
		int numeroRandom = rand();
		//int numeroRandom;
		//cout<< "Valor:";
		//cin>> numeroRandom;
		agregar_cola(fte, fin,numeroRandom);
	
	}
	
	if(i > 100){
		cout<< "Mostrar elemento en orden natural: "<< endl; 
		for(int j=0; j< i; i++){
				cout<< suprimir_cola(fte, fin)<< endl;
			}
		}else{
			
		cout<< "Mostrar elementos en forma inversa: "<< endl; 
		for(int j=0; j< i; j++){
		 	push(pila,suprimir_cola(fte, fin));
		 	}
		 	
		for(int j=0; j<i; j++){
			cout<< pop(pila)<< endl;
		} 	
		 	
	}

	cout<< "Nro de Nodos: " << i;
	return 0;
}

void agregar_cola(Nodo*&fte, Nodo*&fin, int valor){
	Nodo*nuevo_nodo = new Nodo();
	nuevo_nodo->info = valor;
	nuevo_nodo->sgte = NULL; 
	
	if(fte==NULL){
		fte= nuevo_nodo;
	}else{
		fin->sgte= nuevo_nodo; 
	}
	
	fin = nuevo_nodo;
	return;
}

int suprimir_cola(Nodo*&fte, Nodo*&fin){
	int v; 
	Nodo*aux = fte;
	v = fte->info;
	if(fte==NULL){
		//fte = NULL;
		fin = NULL;
	}else{
		fte = fte->sgte;
	}
	
	delete aux;
	return v;
}

void push(Nodo*&pila, int valor){
	Nodo*nuevo_nodo = new Nodo(); 
	nuevo_nodo->info = valor; 
	nuevo_nodo->sgte = pila; 
	pila = nuevo_nodo;
	return;
}; 

int pop(Nodo*&pila){
	int v;
	Nodo*aux = pila; 
	v = aux->info; 
	pila = aux-> sgte; 
	delete aux; 
	return v;
};




