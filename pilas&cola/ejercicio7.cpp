#include <iostream>
#include <cstring>
using namespace std;

/*
 Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por un punto y retorne True 
 si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si no lo son. Los conjuntos deben ingresarse por teclado. 
 (Definir parámetros y codificar).

*/

struct Nodo{
	char info;
	Nodo*sgte;
};

//prototipos

void push(Nodo*&, char); 
char pop(Nodo*&);

int main() {
	int  i, cant=0;
	bool v = true;
	char vP1, vPAx;
	char caracter;
	Nodo*pila1;
	Nodo*pila2;
	Nodo*pilaAux;
	
	//cargo pila1 
	cout<< "Ingrese caracter p/ pila1: ";
	cin>> caracter; 
	
    while(caracter != '.'){
        push(pila1, caracter);
		cant++; //esto para saber las cantidad de veces que ingrese datos a la pila 
		cout<< "Ingrese caracter p/ pila1: ";
	    cin>> caracter; 	
	}
	
	//cargo pila2

    for(i=0; i< cant; i++){
    	cout<< "Ingrese caracter p/ pila2: ";
	    cin>> caracter;
		 
        push(pila2, caracter);
		
	}
	
	//saco los valores de pila2 o pila1 cualquiera --> elijo pila2 y los apilo en pilaAux
	
	for(i=0; i< cant; i++){
		push(pilaAux, pop(pila2));
		
	}
	
	//ahora comparo los valores de pilaAux y pila1
    // true->1, false->0
     for(i=0; i< cant; i++){
     //saco valores
    	vP1 = pop(pila1);
        vPAx= pop(pilaAux);   
    	if(vP1!= vPAx){
	        v = false;
	        cout<< "Son inversas ? : "<< v;
	        return v; //seria como el corte del ciclo 
           } 
           
		}    
		cout<< "Son inversas ? :" << v << endl; 	
			  
	cout<< "\n";
	cout<< "================================"<< endl;	
	cout<<"FALSE--> 0 "<<  endl;
	cout<<"True--> 1 " << endl;
	cout<< "================================"<< endl;
	
	return 0;
}

//defino los prototipos 

void push(Nodo*&pila, char caracter){
	Nodo*nodo_nuevo= new Nodo(); 
	nodo_nuevo->info = caracter;
	nodo_nuevo->sgte=pila; 
	pila= nodo_nuevo;
	return;
}; 

char pop(Nodo*&pila){
	char caracter; 
	Nodo*aux= pila; 
	caracter = aux->info; 
	pila= aux->sgte;
	delete aux; 
	return caracter;
	
};
