#include <iostream>
using namespace std;

/*
Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada valor igual a X que 
se encuentre en la pila por el valor Y retornando la pila modificada. En caso de no haber ningún valor igual
a X retornar la pila sin cambio. (Definir parámetros y codificar)

*/

struct Nodo{
	int info; 
	Nodo* sgte;
	
};

//prototipos 
void push(Nodo*&, int);
int pop(Nodo*&);

int main() {
	Nodo*pila = NULL; 
	int v, i, n, x, y;
	int valorSacado;
	
	//cargo la pila con x cantidad de valores

	cout << "Tamanio de la pila: "; 
	cin>> n;
	
	//dado x e y
	cout<< "Ingrese x:";
	cin>> x;
	cout<< "Ingrese y: ";
	cin>> y;
	
	for(i=0; i< n; i++){
		cout<< "Valor: ";
		cin>> v;
		push(pila, v);
		
		if(pila->info == x){ // si valor de la pila es igual a x HACER:
			pop(pila); //saco de pila
			push(pila,y); // reemplazo por valor y
		}
	}
	
	/* imprimo pila modificada*/	
	for(int i=0; i< n; i++){
		cout<< "Valor retorno: " <<pop(pila)<<endl; 
	} 
	

	return 0;
}

//definir los prototipos

void push(Nodo*&pila, int valor){
	Nodo * nuevo_nodo = new Nodo();
	nuevo_nodo->info = valor; 
	nuevo_nodo->sgte= pila;
	pila = nuevo_nodo;
	return;
	
}; 

int pop(Nodo*&pila){
	int v;
	Nodo *aux = pila; 
	v = aux->info; 
	pila = aux->sgte;
	delete aux;
	return v;
}


