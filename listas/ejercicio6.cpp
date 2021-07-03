#include <iostream>
using namespace std;

/* 
Dado un archivo de registros de alumnos ARCHA sin ningún orden donde cada registro
contiene:
a) Apellido y Nombre del alumno (34 caracteres)
b) Numero de legajo (6 dígitos) 
c) División asignada (3 dígitos)
Se debe desarrollar el algoritmo y codificación del programa que imprima el listado de alumnos por división
ordenado por división y numero de legajo crecientes, a razón de 55 alumnos por hoja.
*/

struct Alumno{
	char apellidoYNombre[34];
	int legajo;
	int division;
};

struct Nodo{
	Alumno info;
	Nodo*sgte;
};

//prototipos 
void cargarDatos(Alumno& );
void mostrarDatos(Alumno);
Nodo * ordenarPorDivision(Nodo*&, Alumno);
Alumno sacar_nodo(Nodo*&);

int main() {
	Nodo*lista = NULL;
	FILE * f1;
	Alumno alumno;
	//abro archivo para lectura
	f1= fopen("ARCHA.BIN", "rb+");
	
	fread(&alumno, sizeof(alumno),1,f1);
	
	while(!feof(f1)){
		ordenarPorDivision(lista, alumno);
		fread(&alumno, sizeof(alumno),1,f1);
	}

	
	//finalmente leo la lista a ver si queda ordenada
	cout<< "Muestro legajos y divisiones ordenados de forma creciente";
    cout<< endl;
    
    while(lista!=NULL){
     	int j;
     	for(j=0; j<3; j++){
     		Alumno a = sacar_nodo(lista); 
     		cout<< "Legajo" << " "<< "Nombre_Apellido" <<" "<< "Division"<< endl;
     		cout<< "========================================================================"<< endl;
     		cout<< a.legajo << " --> " << a.apellidoYNombre << " --> "<< a.division<< endl;
		
		 }
		 // claro el enunciado me pide 55 alumnos por hoja
		 cout << "Imprimo: " << j << " cantida de alumnos por hoja"<< endl;
		 
		 cout<< endl;
	 }
	
	
	return 0;
}

// FUNCION QUE ME ORDENA MAS DE UN CAMPO DEL NODO DADO UN CRITERIO--> ACA ORDENE DE MANERA CRECIENTE AMBOS CAMPOS

Nodo * ordenarPorDivision(Nodo*& lista, Alumno alumno){
	Nodo*nuevo_nodo = new Nodo();
	nuevo_nodo->info = alumno; 
	nuevo_nodo->sgte = NULL; 
	if(lista == NULL || lista->info.division >alumno.division || lista->info.legajo > alumno.legajo ){
		nuevo_nodo->sgte = lista; 
		lista = nuevo_nodo; 
		
		
	}else{
		Nodo*aux = lista; 
		while(aux->sgte!=NULL && aux->sgte->info.division < alumno.division){
			aux= aux->sgte;
		}
		
		nuevo_nodo->sgte= aux->sgte;
		aux->sgte = nuevo_nodo;
		
		
	}
	
	return nuevo_nodo;
	
}



Alumno sacar_nodo(Nodo*&lista){
	Alumno alumno;
	Nodo*aux = lista; 
	alumno = aux->info;
	lista = aux->sgte;
	delete aux; 
	return alumno;
	
	
};
