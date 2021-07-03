#include <iostream>
#include <cstring>
using namespace std;

//Struct datos del Nodo
struct t_inscripcion{
	char nombre[20];
	int cod_mat; // CODIGO MATERIA A INSCRIBIRSE
	int cod_turno;
};

//NODO

struct t_nodo{
	t_inscripcion insc;
	t_nodo * sgte;
};

//Prototipos 
void insertar_ordenado_cR(t_nodo*&, t_inscripcion);

int main(int argc, char** argv) {
	return 0;
}

//FUNCION PARA INSERTAR NODOS ORDENADOS Y CON REPETICION

void insertar_ordenado_cR(t_nodo * & lista, t_inscripcion insc){
	t_nodo* nuevo_nodo = new t_nodo();
	nuevo_nodo->insc = insc; 
	t_nodo* aux_1 = lista; 
	t_nodo* aux_2;
	
	while((aux_1!=NULL) && (aux_1->insc.cod_mat < insc.cod_mat)){ // INSERTO ORDENADO EN
		aux_2 = aux_1; 
		aux_1 = aux_1->sgte;
	}
	
	if(lista == aux_1){ // que sucede si un nodo va al principio?
		lista = nuevo_nodo;
	} else{
		aux_2->sgte = nuevo_nodo;
	}
	  
	  nuevo_nodo->sgte = aux_1;
	  
	  return;
	
}
