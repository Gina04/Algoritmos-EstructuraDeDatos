#include <iostream>
#include<cstring>
using namespace std;

struct notas{
	int nota1;
	int nota2;
	int nota3;
};

struct identidad{
	char apellido[20];
	char nombre[20];
};

struct datos{
	int legajo;
	identidad nombreCompleto;
	notas calificaciones;
};

struct cumple{
	int dia;
	int mes;
	int anio;
};
struct persona{
	char nombre[20];
	cumple fechaNacimiento;
	datos personales;
};
//prototipos
void buscarApellido(char[] ,persona[]);
//int buscar(persona [], int , string);
int main() {
	
	persona vector[20];
	char primerApellido[20];
	
	cout<<"la posicion 8 del vector, campo dia:"<<vector[8].fechaNacimiento.dia<<endl;//punto a
	cout<<"la posicion 0 del vector, campo nombre: "<<vector[0].nombre<<endl;//punto b
	
	int i;
	for(i=0;i<20;i++){//
	
		if(vector[i].personales.legajo==456789){//punto c
		cout<<"la posicion es:"<<i<<endl;
		cout<<"las calificaciones son: "<<vector[i].personales.calificaciones.nota1<<endl;
		cout<<vector[i].personales.calificaciones.nota2<<endl;
		cout<<vector[i].personales.calificaciones.nota3<<endl;
		}
	}
	
	
	cout<<"ingrese un apellido para buscarlo buscar la posicion en el vector: "<<endl;
	cin>>primerApellido;
	
	
	
	
	
	return 0;
}

/*int buscar(persona arr[], int len, string v) { 
int i=0; 
	while( i<len &&  strcmp(persona,v)){ //arr[i]!=v
 	i++; 
	} 
  	return i<len?i:-1; 
	} */

 void buscarApellido(char apellido[],persona vec[]){
  int i;
  for(i=0;i<20;i++){
  	if(strcmp(apellido,vec[i].personales.nombreCompleto.apellido)){
  		cout<<"la posicion del apellido es: "<<i<<endl;
  	/*cout<<"el legajo es: "<<vec.personales.legajo<<endl;
  		cout<<"el nombre es: "<<vec.nombre<<endl;
  		cout<<"las notas son: "<<vec.personales.calificaciones.nota1<<endl;
  		cout<<vec.personales.calificaciones.nota2<<endl;
  		cout<<vec.personales.calificaciones.nota3<<endl;
	  }*/
  }
	return;
}
}
