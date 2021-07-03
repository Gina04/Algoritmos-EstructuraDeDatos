#include <iostream>
#include <stdlib.h>
using namespace std; 

/*
Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar un
procedimiento que genere otra cola COLAB por apareo del campo ARRIBO del registro
(define orden creciente en ambas).
Nota: COLA y COLB dejan de ser útiles después del apareo.

*/

struct Arribo{
	int arribo;
	int arri2;
};
struct Nodo{
	Arribo info; 
	Nodo*sgte;
};

//prototipo 
void agregar_cola(Nodo*&,Nodo*&, int);
Arribo suprimir_cola(Nodo*&, Nodo*&);

int main() {
    Arribo valorB, valorA, valorAB;
    Arribo r;
	
	Nodo*fteA = NULL;
	Nodo*finA = NULL;
	
	Nodo*fteB = NULL;
	Nodo*finB = NULL;
	
	Nodo*fteAB = NULL;
	Nodo*finAB = NULL;
	
	//cargoa pilaA
	agregar_cola(fteA,finA,1);
	agregar_cola(fteA,finA,2);
	agregar_cola(fteA,finA,6);
	agregar_cola(fteA,finA,8);
	agregar_cola(fteA,finA,10);
	
	//cargo pilaB
	
	agregar_cola(fteB,finB,2);
	agregar_cola(fteB,finB,4);
	agregar_cola(fteB,finB,5);
	agregar_cola(fteB,finB,6);
	
		
	
			
	while(fteA!=NULL && fteB!=NULL ){ //Condición que existan nodos en las colas.
		 valorA = suprimir_cola(fteA, finA);
		 valorB = suprimir_cola(fteB, finB);
		
		if(valorA.arribo< valorB.arribo){ //si valor de la colaA es menor que colaB, grabo colaA en colaAB
			agregar_cola(fteAB,finAB,valorA.arribo); 
				
			}else{ // de lo contrario grabo el valor de la colaB.
				
				agregar_cola(fteAB,finAB,valorB.arribo);
			                               				 
			}
						
		}
			
		while(fteA!=NULL){
			valorA = suprimir_cola(fteA, finA);
			agregar_cola(fteAB,finAB,valorA.arribo);
		}	
		
		while(fteB!=NULL){ //Mientras no se termine la colaA
			valorB = suprimir_cola(fteA, finA); 
			agregar_cola(fteAB,finAB,valorA.arribo);//Grabo lo que queda de la colaA sin grabar en la colaAB.
		}	
		
			
			
		while(fteAB!=NULL){ //Mientras no se termine la colaA.
		  valorAB = suprimir_cola(fteAB, finAB);
		  cout<< valorAB.arribo; //Grabo lo que queda en la colaB sin grabar en la colaAB.
		}	
		
     	
	return 0;
}

//defino prototipos

void agregar_cola(Nodo*&fte, Nodo*&fin, int valor){
	Nodo*nuevo_nodo = new Nodo();
	nuevo_nodo->info.arribo = valor;
	nuevo_nodo->sgte = NULL; 
	
	if(fte==NULL){
		fte= nuevo_nodo;
	}else{
		fin->sgte= nuevo_nodo; 
	}
	
	fin = nuevo_nodo;
	return;
}

Arribo suprimir_cola(Nodo*&fte, Nodo*&fin){
	Arribo v; 
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
