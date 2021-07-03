#include <iostream>
using namespace std;
struct Reserva{
	int codigoHotel; 
	int cantidadDeDiasHospeda;
};

struct Nodo{
	Reserva info; 
	Nodo*sgte;
};

//prototipo
Nodo* insertarSinOrden(Nodo*&, int );

int main(int argc, char** argv) {
	return 0;
}

Nodo* insertarSinOrden(Nodo*&lista, Reserva valor){
	Nodo* nuevo_nodo = new Nodo(); 
	nuevo_nodo->info= valor; 
	nuevo_nodo->sgte = NULL; 
	Nodo*aux = lista;
	while(aux->sgte!=NULL){ // aca no tengo en cuenta si la lista esta vacia por condicion de enunciado
	    aux= aux->sgte;     // ya tengo una pila y una lista cargada entonces descarto esa posibilidad
	                            // y ademas descarto la posibilidad de que un nodo vaya o no entre medio de otros	
	}
	nuevo_nodo->sgte = aux->sgte;
	aux->sgte = nuevo_nodo;
	
	return nuevo_nodo;	
	}
