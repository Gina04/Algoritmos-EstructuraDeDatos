#include <iostream>
using namespace std;

/*
Dada una cola (nodo = registro + puntero), desarrollar y codificar una función que devuelva la cantidad de nodos que 
tiene. 
*/
struct Nodo{
	int info; 
	Nodo * sgte;
};

//Prototipos
void agregar_cola(Nodo*&, Nodo*&, int);
int suprimir_cola(Nodo*&, Nodo*&);
int contadorNodosCola(Nodo*&, Nodo*&);

int main() {
	int cont=0;
	Nodo*fte = NULL;
	Nodo*fin = NULL;
	//dada una cola 
	agregar_cola(fte, fin, 8);
	agregar_cola(fte, fin, 34);
	agregar_cola(fte, fin, 11);
	agregar_cola(fte, fin, 345);
	agregar_cola(fte, fin, 468);
	agregar_cola(fte, fin, 8887);
	agregar_cola(fte, fin, 8887);
	
	//funcion que me retorna los nodos que tiene la cola

	cout<< "La cantidad de nodos que tiene la cola : " << contadorNodosCola(fte, fin);

	
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
		fte=NULL;
		fin=NULL;
	}else{
		fte = fte->sgte;
	}
	
	delete aux;
	return v;
}

int contadorNodosCola(Nodo*&fte, Nodo*&fin){
	    int cont = 0;
		while(fte!=NULL){
		suprimir_cola(fte, fin);
		cont++;
	}
	
	return cont++;
	
};
