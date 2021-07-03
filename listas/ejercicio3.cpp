#include <iostream>
using namespace std;

/* 
Dada una LISTA (nodo = registro + puntero), imprimirla en orden natural si tiene mas de 100 nodos,
caso contrario imprimirla en orden inverso.
*/
struct t_registro{
	int tel; 
	int edad;
};

struct Nodo{
	t_registro info;
	Nodo*sgte;
};

//Prototipos
Nodo* insertar_ordenado(Nodo*&, t_registro);
void cargar_registro(t_registro& );
int cantidadNodos(Nodo*&);
void push(Nodo*&, t_registro);
t_registro pop(Nodo*&);

int main() {
	Nodo*lista = NULL; 
	Nodo*pila = NULL;
	t_registro registro;
	int i;
	
	//cargo lista
	cout << "Cargo valores para la listaA: " << endl;
	for(i=0; i<2; i++){
		cargar_registro(registro);	
		insertar_ordenado(lista, registro);
		 
	}
	
	if(i > 100){
		cout << "Muestro en el orden natural: "; 
		while(lista!=NULL){
			t_registro r = pop(lista);
			cout<< r.edad<< endl; 
			cout<< r.tel << endl;
		}
		
	}else{
		//cargo una pila con los valores sacados de lista he imprimo
		cout << "Mostrar en orden inverso: "; 
		for(int j=0; j< i; j++){
		 	push(pila,pop(lista)); //cargo pila
		 	}
		
		for(int j=0; j<i; j++){
			t_registro r = pop(pila);
			cout<< r.edad<< endl; //muestro pila
			cout<< r.tel<< endl; // muestro pila
		} 
		
		
	}
	
	return 0;
}

//Defino los prototipos 

Nodo* insertar_ordenado(Nodo*& lista, t_registro registro){
	Nodo*nuevo_nodo = new Nodo();
	nuevo_nodo->info = registro; 
	nuevo_nodo->sgte = NULL;
	if(lista == NULL || registro.edad < lista->info.edad){
		nuevo_nodo->sgte = lista;
		lista = nuevo_nodo;
	}else{
		Nodo* aux = lista;
		while(aux->sgte!=NULL && aux->sgte->info.edad < registro.edad){
			aux = aux->sgte;
		}
		nuevo_nodo->sgte = aux->sgte;
		aux->sgte = nuevo_nodo;
	}
	
	return nuevo_nodo;
};
void cargar_registro(t_registro& registro){
	cout<< "Cargar edad: " << endl; 
	cin>>registro.edad;
	
	cout<< "Cargar Tel:" << endl;
	cin>> registro.tel;
	
	return; 
};


int cantidadNodos(Nodo*&lista){
	int cont = 0;
	while(lista!=NULL){
		pop(lista);
		cont++;
	}
	
	return cont++;
};

void push(Nodo*&pila, t_registro valor){
	Nodo* nuevo_nodo= new Nodo();
	nuevo_nodo->info = valor; 
	nuevo_nodo->sgte = pila; 
	pila = nuevo_nodo;
	return;
}

t_registro pop(Nodo*&pila){
	t_registro valor;
	Nodo * aux = pila; 
	valor = aux->info;
	pila = aux->sgte;
	delete aux;
	return valor;
}
