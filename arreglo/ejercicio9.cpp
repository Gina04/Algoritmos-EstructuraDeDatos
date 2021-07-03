#include <iostream>
#include<cstring>
using namespace std;

/*
Dado un numero N (<=50) y un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD),
informar el conjunto:
· ordenado por nombre
· ordenado por fecha y nombre
· ordenado por nombre y fecha
NOTA: Modifique y utilice el procedimiento Burbujeo
*/

struct Persona{
	char nombre[30];
	int fechaNacimiento;
};

//Prototipo
void ordenarNombre(Persona[], int);
void ordenarPorFecha(Persona[], int);

int main() {
	int n, i;
	
	cout<<"Ingrese n:";
	cin>>n;
	Persona datos[n];
	
	for(i=0;i<n; i++){
		cout<< "Ingrese nombre:";
		cin>>datos[i].nombre;
		cout<< "Ingrese fecha (AAAAMMDD)";
		cin>> datos[i].fechaNacimiento;
		
	}
	 ordenarNombre(datos,n);
	 ordenarPorFecha(datos, n);
	
	cout<< "Ordenado por nombre alfabeticamente \n";
	//ordenar por nombre
     for(i=0; i<n; i++){
     	cout<< datos[i].nombre<<endl;
	 }
	 
	 cout<<"Muestra Fecha de nacimiento de mayor a menor y nombre alfabeticamente"<<endl;
	 
	//ordenar por fecha-nacimiento y nombre
	 for(i=0; i<n; i++){
	 	cout<< datos[i].fechaNacimiento<<endl;
	 
	 }
	 
	 for(i=0;i<n;i++){
	 	cout<< datos[i].nombre<<endl;
	 }
	 
	 //ordenado por nombre y fecha
	 
	cout<<"Muestra  nombre alfabeticamente y fecha de nacimiento de mayor a menor"<<endl;
	
	for(i=0;i<n;i++){
	 	cout<< datos[i].nombre<<endl;
	 }
	 
	for(i=0; i<n; i++){
	 	cout<< datos[i].fechaNacimiento<<endl;
	 
	 }
	 

	return 0;
}

//Defino las funciones
//metodo burbujeo
void ordenarNombre(Persona datos[], int n){
	int i, j;
	char aux[30];
	for(i=1; i<n; i++){
		for(j=1; j<=n-i; j++){                             
			if(strcmp(datos[j-1].nombre, datos[j].nombre ) > 0){ // de menor a mayor
				 strcpy(aux,datos[j].nombre); 		 
				 strcpy(datos[j].nombre, datos[j-1].nombre);
				 strcpy(datos[j-1].nombre,aux);
		
			}	
		}
	}
	return;
}

void ordenarPorFecha(Persona datos[], int n){ //de mayor a menor
	int i, j, aux;
	for(i=1; i<n; i++){
		for(j=1; j<= n-i; j++){
			if(datos[j-1].fechaNacimiento > datos[j].fechaNacimiento){
				aux = datos[j].fechaNacimiento;
				datos[j].fechaNacimiento = datos[j-1].fechaNacimiento;
				datos[j-1].fechaNacimiento = aux;
				
				
			}
		}
	} 
	
	
}
