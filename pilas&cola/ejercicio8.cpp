#include <iostream>
#include <cstring>
using namespace std;

/* 
Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos y Nombre de alumnos y los imprima en orden inverso al
de ingreso. (Definir parámetros y codificar).
 */

struct Nodo{
	char nombre[30];
	Nodo*sgte;
};

//prototipos
void push(Nodo*&, char[]); 
char pop(Nodo*&, char[]);


int main() {
	Nodo*pila= NULL;
	char nombre[10];
	int tam,i;
	
	cout<< "Ingrese tamaño:"; 
	cin>> tam;
	
	for(i=0; i< tam; i++){
		cout<< "Nombre_apellido:";
		cin>> nombre;
		push(pila, nombre);
	
	}
	
	//Imprimo
	
	for(int j=0; j< tam; j++){
		pop(pila, nombre);
		cout<< "Nombre: " << nombre<<endl;
		
	}
	
	
	
	return 0;
}

//defino los prototipos
void push(Nodo*&pila, char nombre[]){
  Nodo* nuevo_nodo= new Nodo();
  strcpy(nuevo_nodo->nombre, nombre);
  nuevo_nodo->sgte = pila; 
  pila = nuevo_nodo;
  return;
	
	
}; 
char pop(Nodo*&pila, char nombre[30]){
	Nodo*aux = pila;
    strcpy(nombre, aux->nombre); 
    pila = aux->sgte;
    delete aux; 
    return nombre[30];
	
	
};


