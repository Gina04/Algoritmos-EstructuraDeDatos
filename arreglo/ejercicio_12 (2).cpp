#include <iostream>
#include<cstring>
#define tam 20
using namespace std;
/*declare un define para poder probarlo con 2 entradas de datos y no hacerlo con 20, anide los 4 struct como dice el enunciado
luego itero los datos (no lo pide pero lo hice para hacer la prueba en ejecucion) luego retorno las posiciones que se
me pide en el punto a y b,busco tambien la posicion del legajo que se pide, hago la busqueda del apellido que se ingresa
y por ultimo realizo la busqueda binaria para encontrar el legajo 456789, suponiendo que el vector de struct campo legajo
esta ordenado*/
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

int buscarApellido(char [],persona[]);
int busquedaBinaria(persona [], int , int,int &);
int main() {
	
	persona vector[tam];
	char primerApellido[20];
	int pos;
	
	
	int j;
	for(j=0;j<tam;j++){
		cout<<"nombre: "<<endl;
		cin>>vector[j].nombre;
		strcpy(vector[j].personales.nombreCompleto.nombre,vector[j].nombre);
		
		cout<<"apellido: "<<endl; 
		cin>>vector[j].personales.nombreCompleto.apellido;
		
		cout<<"legajo: "<<endl;
		cin>>vector[j].personales.legajo;
		
		cout<<"dia: "<<endl;
		cin>>vector[j].fechaNacimiento.dia;
		
		cout<<"nota 1:"<<endl;
		cin>>vector[j].personales.calificaciones.nota1;
		
		cout<<"nota 2:"<<endl;
		cin>>vector[j].personales.calificaciones.nota2;
		
		cout<<"nota 3:"<<endl;
		cin>>vector[j].personales.calificaciones.nota3;
	}
	
	cout<<"la posicion 1 del vector, campo dia:"<<vector[1].fechaNacimiento.dia<<endl;//punto a CAMBIAR A 8
	cout<<"la posicion 0 del vector, campo nombre: "<<vector[0].nombre<<endl;//punto b
	
	int i;
	for(i=0;i<tam;i++){//
	
		if(vector[i].personales.legajo==456789){//punto c
		cout<<"la posicion es:"<<i<<endl;
		cout<<"las calificaciones son: "<<vector[i].personales.calificaciones.nota1<<endl;
		cout<<vector[i].personales.calificaciones.nota2<<endl;
		cout<<vector[i].personales.calificaciones.nota3<<endl;
		}
	}
	
	cout<<"ingrese un apellido para buscarlo buscar la posicion en el vector: "<<endl;
	cin>>primerApellido;
	
	pos=buscarApellido(primerApellido,vector);
	
	cout<<"la posicion del apellido es: "<<pos<<endl;
	
	int primero=0;
	pos=busquedaBinaria(vector,456789,tam,primero);
	
	cout<<"el legajo esta en la posicion: (si retorna -1 es porque no se encontro) "<<pos<<endl;
	return 0;
}

int buscarApellido(char apellido[],persona vec[]){
  int i,posicion;
  for(i=0;i<tam;i++){
  	if(strcmp(apellido,vec[i].personales.nombreCompleto.apellido)==0){
  		posicion=i;
	  }
  }
	return posicion;
}

int busquedaBinaria(persona v[], int buscado, int N,int &primero){

	int ultimo = N-1;
	int medio;
	primero = 0;
	while (primero <= ultimo){
		medio = (primero + ultimo)/2;
		if(v[medio].personales.legajo == buscado) return medio; 
		if(buscado > v[medio].personales.legajo) primero = medio + 1;
		else ultimo = medio - 1;
	};
	return -1;
}


