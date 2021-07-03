#include <iostream>
using namespace std; 

struct Nodo{
	int info; 
	Nodo * sgte;
};

//Prototipos
void agregar_cola(Nodo*&, Nodo*&, int);
int suprimir_cola(Nodo*&, Nodo*&);

/* 
Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar un
procedimiento que genere una única cola COLAB a partir de ellas. (Primero los nodos de COLA y luego los de COLB).
 */

int main() {
	
	Nodo*fteA = NULL; 
	Nodo*finA = NULL;
	
	Nodo*fteB = NULL; 
	Nodo*finB = NULL;
	
	Nodo*fteAB = NULL; 
	Nodo*finAB = NULL;
	
	//No ingreso los valores por consola ya que me dice el enunciado "dadas dos colas.."
	//doy por hecho de que las colas ya las tengo por ende no hace falta el ingreso. 
	agregar_cola(fteA, finA, 78);
	agregar_cola(fteA, finA, 123);
	agregar_cola(fteA, finA, 1);
	
	
	agregar_cola(fteB, finB, 345);
	agregar_cola(fteB, finB, 300);
	agregar_cola(fteB, finB, 100);
    
    // los nodos que desencolo de A los agregro a la nueva COLAAB y como el enunciado pide (Primero los nodos de COLA y luego los de COLB).
    //por concepto de cola primero ingreso los nodos de ColaA y luego de ColaB.  FIFO - first in first out
	
	while(fteA!=NULL ){ 
		agregar_cola(fteAB, finAB, suprimir_cola(fteA, finA));
		
	} 
	
	while(fteB!=NULL ){ 
		agregar_cola(fteAB, finAB, suprimir_cola(fteB, finB));
	}
	
	//Imprimo o desencolo los nodos de la COLAB
	
	while(fteAB!=NULL){
		cout << suprimir_cola(fteAB, finAB)<< endl;
	}
	
	
	
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
