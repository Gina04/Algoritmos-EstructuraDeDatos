#include <iostream>
using namespace std;


/* 
Dada una lista (nodo = registro + puntero), desarrollar y codificar una funcion que devuelva la cantidad de nodos que
tiene.
*/
struct t_registro{
	int tel; 
	int edad;
};

struct Nodo{
	t_registro info;
	Nodo*sgte;
};

//prototipos
Nodo * insertar_ordenado(Nodo*&, t_registro);
void cargar_registro(Nodo*&, t_registro & );
void sacar_nodo( Nodo* &, t_registro &);
int cantidadNodos(Nodo*&, t_registro &);
 


int main() {
	
	Nodo* lista = NULL; 
	t_registro registro;
	int i;
	
	for(i=0; i<5; i++){
		
	  cargar_registro(lista, registro);
	
	}
	
	cout << "Cantidad de nodos de la lista: " << cantidadNodos(lista, registro);
	
	return 0;
}

//Defino los prototipos

//identificamos 3 situaciones, (lista vacia- o nodo adelante de la lista -insertar al medio o al final que comparten logica).
Nodo* insertar_ordenado(Nodo*&lista, t_registro valor){
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->info = valor;
    nuevo_nodo->sgte = NULL;
    
    if(lista == NULL || valor.edad < lista->info.edad){ //si la lista esta vacia o si el valor que ingreso es menor que lo que hay en el nodo
    	nuevo_nodo->sgte = lista;
    	lista = nuevo_nodo;
	} else{
		Nodo*aux_1 = lista;
		while(aux_1->sgte!=NULL && aux_1->sgte->info.edad < valor.edad ){
			aux_1 = aux_1->sgte;
		}
		
		nuevo_nodo->sgte = aux_1->sgte; // enlazo al resto de la lista.
		aux_1->sgte = nuevo_nodo; //enlazo al nuevo nodo.
		
	}
	
	return nuevo_nodo;
	
};

void cargar_registro(Nodo*&lista, t_registro & registro){
	
		cout<< "Ingrese edad:";
		cin>> registro.edad;
		
		cout<< "Ingrese telefono: ";
		cin>> registro.tel;
		
		insertar_ordenado(lista,registro);
		
		return;
};

void sacar_nodo( Nodo* &lista, t_registro &registro){
    Nodo* ptr_aux = lista;
    registro = ptr_aux -> info;
    lista = ptr_aux -> sgte;
    delete ptr_aux;
}

int cantidadNodos(Nodo*&lista, t_registro & registro){
	int cont = 0;
	while(lista!=NULL){
		sacar_nodo(lista, registro);
		cont++;
	}
	
	return cont++;
	
	
}
