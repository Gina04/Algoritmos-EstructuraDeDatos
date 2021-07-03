#include <iostream>
#include <stdlib.h>
using namespace std;

/* 
Dadas dos listas LISTA y LISTB (nodo = registro + puntero), desarrollar y codificar un
procedimiento que genere una única lista LISTC a partir de ellas. (Primero los nodos de LISTA 
y luego los de LISTB).
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
Nodo* insertar_ordenado(Nodo*&, t_registro);
void cargar_registro(t_registro& );
t_registro  sacar_nodo(Nodo*&);


int main() {	
	Nodo*listaA = NULL;
	Nodo*listaB = NULL;
	Nodo*listaC = NULL;
	int i;
	t_registro registro;
	
	//cargo listaA
	cout << "Cargo valores para la listaA: " << endl;
	for(i=0; i<2; i++){
		cargar_registro(registro);	
		insertar_ordenado(listaA, registro);
		 
	}
	cout<< endl;
	//cargo listaB
	cout << "Cargo valores para la listaB: " << endl;
	
	for(i=0; i<2; i++){
		cargar_registro(registro);
		insertar_ordenado(listaB, registro);
		
	}
	
    while(listaA!=NULL){
		t_registro r = sacar_nodo(listaA);
		
   		insertar_ordenado(listaC, r);
   	
  	 }
   
    while(listaB!=NULL){
	   t_registro r = sacar_nodo(listaB);
       insertar_ordenado(listaC, r );  	
   	
  	 }


	
	cout<<"ListaC con valores de listaA y listaB" << endl;
	//genero con lo valores que voy a sacar de la lista una listaC
	while(listaC!=NULL){
	   t_registro r = sacar_nodo(listaC);
	   cout<< r.edad << endl;
	   cout<< r.tel << endl;
	   
   	
   }
   
    system("pause");
	return 0;
}


   
   

//definir las funciones 

Nodo* insertar_ordenado(Nodo*&lista, t_registro registro){
	Nodo*nuevo_nodo = new Nodo();
	nuevo_nodo->info = registro;
	nuevo_nodo->sgte = NULL;
	
	//identifico dos casos (lista vacia- nodo delante de todo)
	if(lista==NULL || lista->info.edad > registro.edad ){
		nuevo_nodo->sgte = lista; 
		lista = nuevo_nodo;
	}else{
		Nodo*aux = lista;
		while(aux->sgte != NULL && aux->sgte->info.edad < registro.edad){
			aux = aux->sgte;
			
		}
		
		nuevo_nodo->sgte = aux->sgte;
		aux->sgte = nuevo_nodo;
			
		}
		return nuevo_nodo;
	
	};
	
	

void cargar_registro(t_registro& registro ){
	cout<< "cargar edad: ";
	cin>> registro.edad;
	
	cout<< "cargar tel: ";
	cin>> registro.tel;
	
	return;
	
	
};

t_registro sacar_nodo( Nodo* & lista){
	t_registro registro;
	Nodo*aux = lista;
	registro = aux->info;
	lista = aux->sgte;
	delete aux;
	return registro;
};




