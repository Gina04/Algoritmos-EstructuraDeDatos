#include <iostream>
using namespace std; 


/* 
Dada una pila y un valor X, desarrollar un procedimiento que inserte el valor X en la última
posición de la pila y la retorne. (Definir parámetros y codificar).
*/
struct Nodo{
	int info; 
	Nodo* sgte;
};

//prototipos

void push(Nodo*&, int);
int pop(Nodo*&);

int main() {
	Nodo* pila = NULL;
	Nodo* aux = NULL; 
	int valor,i,n; 
	
	cout<< "Tamanio pila: "; 
	cin>> n;
	
	for(i=0; i<n; i++){ // cargo pila
		cout<< "Valor: "; 
		cin>> valor;
		
		push(pila, valor);
	}
	
	for(i=0; i< n; i++){ //desapilo pila y apilo en aux
	   push(aux, pop(pila));
	   
	}
	
	//ingreso el valor en la pila vacia 
    cout << "ingrese x:"; 
    cin>> valor;
    
    push(pila, valor);
    
	// vuelvo a cargar la pila con los valores sacados
	
	for(i=0; i<n; i++){
		push(pila, pop(aux));
	}
	
	//muestro la pila con el ultimo valor retornado 
     
     for(i=0; i< n+1; i++){
                	
     		cout<< i << " : " << pop(pila)<<endl;
	 }
	
	
	return 0;
}

//definos los prototipos 

void push(Nodo*&pila, int valor){
	 Nodo* nuevo_nodo = new Nodo();
	 nuevo_nodo->info = valor; 
	 nuevo_nodo->sgte=pila;
	 pila = nuevo_nodo;
	 return;
	
};
int pop(Nodo*&pila){
	int v;
	Nodo* aux = pila; 
	v = aux->info;
	pila= aux->sgte; 
	delete aux; 
	return v;
};
