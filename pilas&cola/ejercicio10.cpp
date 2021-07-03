#include <iostream>
using namespace std;

/*
Dada una cola (nodo = registro + puntero), desarrollar y codificar un procedimiento que elimine 2 nodos de la misma
(indicar con un parámetro 'S'/'N' si ello fue, o no posible).
*/

struct Nodo{
	int info; // modificar resgistro
	Nodo * sgte;
};

//Prototipos
void agregar_cola(Nodo*&, Nodo*&, int);
int suprimir_cola(Nodo*&, Nodo*&);

int main() {
	Nodo* fte=NULL; 
	Nodo* fin=NULL;
	int i, valor, tam;
	char respuesta = 's';
	
	cout<< "Tamanio :"; 
	cin>> tam;
	//cargo la cola
	for(i=0; i< tam; i++){
		cout<< "valor: "; 
		cin>> valor;
		
		agregar_cola(fte, fin , valor);
	}
    
    cout<< "Decea eliminar los dos primeros nodos (s/n): ";
	cin>> respuesta;
	
	for(int j=0; j < 2;j++ ){        
		if(respuesta == 's'){
			cout << "Los dos nodos eliminados son: " << suprimir_cola(fte, fin)<<endl;
			}
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
		fte = NULL;
		fin = NULL;
	}else{
		fte = fte->sgte;
	}
	
	delete aux;
	return v;
}
