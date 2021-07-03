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
void sacar_nodo(t_nodo*&, t_inscripcion &); //notese que esta funcion es la misma que pilas
void cargar_inscripcion(t_inscripcion &);
void mostrar_nombre(char[]);


int main() {
	t_nodo*lista = NULL;
	
	t_inscripcion insc; 
	
	char respuesta = 's';
	
	cargar_inscripcion(insc);
	
	cout<< endl; 
	
	while(respuesta == 's'){
		
		insertar_ordenado_cR(lista, insc); //inserto un nodo ORDENADO dentro de la lista
		
		cout<< "desea cargar mas inscripciones (s/n): ";
		cin>> respuesta;
		cout << endl;
		
		if (respuesta=='s'){
			cargar_inscripcion(insc);
			cout << endl;
		}
		
	}
	cout << endl;
	cout << "La carga de la lista fue exitosa...."<< endl;
	cout << endl;
	
	
	cout << "Informe de la Estructura lista:"<< endl;
	cout << endl;
	
	while(lista!=NULL){
		sacar_nodo(lista, insc);
		
		mostrar_nombre(insc.nombre);
		cout<<" ... " << insc.cod_mat << " ... " << insc.cod_turno<< endl;
			
		
	}
	
		cout << endl;
        cout << "        FIN DEL LISTADO..." << endl;
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

//FUNCION PARA EXTRAER NODOS Y SUS CORRESPONDIENTES DATOS 
// CONSECUENTEMENTE VOY LIBERANDO MEMORIA DE LA LISTA EN TIEMPO DE EJECUCION 

void sacar_nodo(t_nodo*&lista, t_inscripcion & insc){
	t_nodo * aux = lista; 
	insc = aux->insc;
	lista = aux->sgte;
	delete aux;
	
	return;
	 
}

//FUNCION PARA CARGAR LOS DATOS DE UNA INSCRIPCION
void cargar_inscripcion(t_inscripcion & insc){
	char nom[20];
	
	cout<< "Ingrese el nombre de la persona: ";
	cin>> nom;
	
	strcpy(insc.nombre, nom);
	cout << endl;
	
	cout << "Ingrese el codigo de la materia: ";
	cin>> insc.cod_mat;
	cout<< endl; 
	
	cout<< "Ingrese el codigo del turno: ";
	cin>> insc.cod_turno;
	cout << endl;
	
	return;
}

//FUNCION PARA MOSTRAR ARRAY DE CHAR
void mostrar_nombre(char nombre[]){
	int i=0;
	
	while(nombre[i] != '\0'){ // mientras no sea fin de cadena
		cout<< nombre[i] ;
		i++;
	}
	
};
