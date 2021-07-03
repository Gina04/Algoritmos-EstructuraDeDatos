#include <iostream>
using namespace std;

/* 
Dada una pila y un valor I, desarrollar un procedimiento que elimine los 2 primeros nodos de la pila y deje
el valor I como primero. (Definir parámetros y codificar).

 */
 
struct Nodo{
	int info;
	Nodo* sgte;
};


//prototipos
void push(Nodo*&,int);
int pop(Nodo*&);

int main() {
	
	int valor; 
	Nodo * nuevo_nodo = NULL;
	
	//push(nuevo_nodo, 62); // este valor I queda como primero 
	
	//cargo los nodos 
	for(int i=0; i<3; i++){
		cout<< "Ingrese un valor: "; 
	    cin>> valor;
	    
		push(nuevo_nodo, valor);
	}
	
	//elimino los dos primeros nodos de la pila
	for(int j=0; j<2; j++){
		cout<< "El valor eliminado del nodo "<< j << ":"<< pop(nuevo_nodo)<< endl;
		
	}
	
	cout<< "El primer valor es: " << nuevo_nodo-> info;
	
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
