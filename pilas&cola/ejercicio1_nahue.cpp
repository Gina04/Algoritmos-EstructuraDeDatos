#include <iostream>

using namespace std;
/*Declaro la pila, y su respectivo struct, saco dos elementos random que invente, y luego en la primera posicion insert el valor 
que se me pide*/
struct Nodo{
	int info;
	Nodo *sgte;
};

void push(Nodo*&, int);
int pop(Nodo*&pila);

int main() {
	Nodo*pila=NULL;
	
	push(pila,34);
	push(pila,98);
	

	cout<<"sacando elementos de la pila"<<endl;
	cout<<pop(pila)<<endl;
	cout<<pop(pila)<<endl;
	int valor;
	
	cout<<"ingrese un elemento para la pila: "<<endl;
	cin>>valor;
		
	push(pila,valor);
		
	cout<<"el valor es : "<<pop(pila);
	
	return 0;
}

void push(Nodo*&pila, int x){ //meter elementos a la pila
	Nodo*p=new Nodo();
	p->info=x;
	p->sgte=pila;
	pila=p;
	return;
}
int pop(Nodo*&pila){ //saca elemento de la pila
	int x;
	Nodo*p=pila;
	x=p->info;
	pila=p->sgte;
	return x;
}

