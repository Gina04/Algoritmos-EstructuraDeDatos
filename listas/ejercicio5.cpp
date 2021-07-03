#include <iostream>
#include <stdio.h>
using namespace std;

/* 
Dado un archivo de registros de alumnos ARCHA sin ningún orden, donde cada registro
contiene: 
a) Apellido y Nombre del alumno (34 caracteres)
b) Numero de legajo (6 dígitos)
a) División asignada (1 a 100)
Se debe desarrollar el algoritmo y codificación del programa que genere un archivo ARCHL 
igual al anterior pero ordenado por número de legajo.
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
Nodo * insertarOrdenado(Nodo*&, Alumno alumno);
Alumno sacar_nodo(Nodo*&);

int main() {
	Nodo* lista = NULL;
	FILE * archivo;
	FILE* archivo2;
	// abro archivo para escritura de tipo bin 
	
	archivo = fopen("ARCHA.BIN", "wb+");
	char respuesta = 's';
    Alumno alumno;
    
    //cargo datos del archivo 
	while(respuesta == 's'){
		cargarDatos(alumno);
		
		//grabo los datos al archivo
		fwrite(&alumno,sizeof(alumno),1, archivo);
		
		cout<< "Quiere seguir cargando datos (s/n):";
		cin>> respuesta;
		cout << endl;
	
		
	}
	
	//leo los datos del archivo 
	
	 //---> me posiciono al principio del archivo, NO OLVIDAR
	 
	 fseek(archivo,0,SEEK_SET);
	 
	 fread(&alumno, sizeof(alumno),1,archivo);
	 
	 while(!feof(archivo)){
	 	//cargo la lista con los datos que leo del archivo
	 	insertarOrdenado(lista, alumno);
	    //mostrarDatos(alumno);
	 	fread(&alumno, sizeof(alumno),1,archivo);
	 }
	 
	 // una vez que ordene la info vuelvo a grabar en un archivo nuevo 
	 
     archivo2 = fopen("ARCHL.BIN", "wb+");
     
	 /* muestro los datos de la lista--> deben estar los legajos oredenados de forma creciente*/
	 
	 while(lista!=NULL){
	 	Alumno alum2= sacar_nodo(lista); 
	 	//cout<< alum.legajo<< "--->"<< alum.apellidoYNombre << endl ;
	 	fwrite(&alum2,sizeof(alum2),1, archivo2);
	 } 
	 
	 //muestro los datos del archivo2 a ver si cargo correctamente
	 fseek(archivo2,0,SEEK_SET); 
	 
	 fread(&alumno, sizeof(alumno),1,archivo2);
	 
	 while(!feof(archivo2)){
	 	 mostrarDatos(alumno);
	 	 fread(&alumno, sizeof(alumno),1,archivo2);
	 	 
	 }
	
	fclose(archivo2); 
	fclose(archivo);
	
	return 0;
}

void cargarDatos(Alumno & alumno){
	
	cout<< "Ingrese apellido_nombre:"<< endl;
	cin>>alumno.apellidoYNombre;
	
	cout<< "Ingresese legajo: "<< endl;
	cin>>alumno.legajo;
	
	cout<< "Ingrese division (1 hasta 100):"<< endl;
	cin>> alumno.division;
	
	return;
	
		
}

void mostrarDatos(Alumno alumno){
		cout<< alumno.apellidoYNombre<< "-->" << alumno.legajo << "-->" << alumno.division << endl ;
	 	return;
}

Nodo * insertarOrdenado(Nodo*&lista, Alumno alumno){
	Nodo*nuevo_nodo = new Nodo(); //genero el nodo
	nuevo_nodo->info = alumno;    // lo cargo con los datos
	nuevo_nodo->sgte = NULL;     
	
	// donde inserto el nuevo nodo? 2POSIBILIDADES
	if(lista==NULL || alumno.legajo < lista->info.legajo){
		nuevo_nodo->sgte = lista;
		lista = nuevo_nodo;
	}else{
		Nodo*aux = lista; 
		while(aux->sgte!=NULL && aux->sgte->info.legajo < alumno.legajo){
			aux = aux->sgte;
		}
		
		nuevo_nodo->sgte= aux->sgte;
		aux->sgte = nuevo_nodo;
	}
	
	return nuevo_nodo;
	
};

Alumno sacar_nodo(Nodo*&lista){
	Alumno alumno;
	Nodo*aux = lista; 
	alumno = aux->info;
	lista = aux->sgte;
	delete aux; 
	return alumno;
	
	
};
