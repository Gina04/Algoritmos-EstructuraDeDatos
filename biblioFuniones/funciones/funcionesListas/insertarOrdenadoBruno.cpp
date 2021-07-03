#include <iostream>
using namespace std; 

struct t_struct{
	int legajo;
	int dni;
};

struct Nodo{
	t_struct info; 
	Nodo*sgte;
};

/*insertar ordenado*/

int main(int argc, char** argv) {
	return 0;
}


Nodo* insertarOrdenado(Nodo*&lista, t_struct x){
	Nodo*nuevo_nodo = new Nodo();
	nuevo_nodo->info = x; 
	nuevo_nodo->sgte = NULL; 
	
	if(lista==NULL && lista->info.legajo > x.legajo){ // si no hay nodos en la lista y es menor
		nuevo_nodo->sgte = lista; //la lista apunta al nuevo nodo
		lista = nuevo_nodo;       // lista recibe la direccion de memoria nuevo nodo osea
		                          // ahora esta lista apuntando a nuevo nodo.
		
	}else{ //si hay nodos en la lista
	     
	     Nodo * aux_1 = lista; // el puntero aux_1 apunta al principio
	     while((aux_1->sgte!=NULL) && (aux_1->sgte->info.legajo < x.legajo)){
				aux_1 = aux_1->sgte; // lo muevo al siguiente nodo     	
		 }
		 
		 nuevo_nodo->sgte = aux_1-> sgte;
		 aux_1->sgte = nuevo_nodo;
	    		
	}
	
	return nuevo_nodo;
}
