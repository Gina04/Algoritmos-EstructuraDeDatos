#include <iostream>
#include <cstring>
#include <stdio.h>


using namespace std;

/* 

Dado un archivo PRECIOS (desordenado) con los precios de cada articulo, donde cada registro contiene:
a. Nro. de articulo (5 digitos)
b. Descripcion del articulo (19 c)
c. Precio por unidad (real)
d. Cantidad en stock (5 e)
e. Nro. de proveedor (4 digitos)

Desarrollar el programa que imprima el contenido del archivo ordenado por:
1) Nro. de articulo creciente
2) Descripcion del articulo (alfabetico creciente)
3) Nro. de proveedor creciente y dentro del mismo por Nro. de articulo creciente
4) Nro. de proveedor creciente y dentro del mismo por Nro. de articulo decreciente.


*/

//Prototipos
void ordenCreciente(int[], int);
void ordenDescripcion(char[], int);
string convertToString(char* , int);

struct Precio{
	int articulos;
	char descripcion;
	float precio;
	int stock;
	int nroProveedor;
};
int main() {
	int tam, i=0;
	
	Precio precios;
	
	FILE* archivo;
	FILE*archivo2;
	
	archivo = fopen("PRECIOS.DAT", "rb+"); //abro
	
	fread(&precios,sizeof(precios), 1, archivo); // leo
	
	while(!feof(archivo)){ //mientras no sea fin de archivo
		fread(&precios,sizeof(precios), 1, archivo);
	}
	
	tam = ftell(archivo)/sizeof(precios); //cantidad de registros
	
	//VECTORES
	int articulos[tam];
	 // guarda nro articulos
    string descripcion;  //Un string es una cadena de caracteres,
	                     // o lo que es lo mismo un string es un array de chars.
	 //guarda la descripcion
	int proveedor[tam];//guarda nro.proveedor
	
	
	fseek(archivo,0,SEEK_SET);//me vuelvo a posicionar al inicio
	
	fread(&precios, sizeof(precios), 1,archivo); //leo
	
	while(!feof(archivo)){
		articulos[i] = precios.articulos; //cargo los datos al array p/ ordenar.
		descripcion= precios.descripcion;
		
		
		
		i++;
		
		fread(&precios, sizeof(precios), 1,archivo);
	}
	
	//ORDENAR:
	//ordeno de menor a mayor los nro articulos, descripcion (creciente)
	
	ordenCreciente(articulos, tam);
	
	ordenDescripcion(descripcion, tam);
	
	ordenCreciente(proveedor, tam);
	
	//lo grabo en el archivo2 el array con los legajos ordenados
	
	archivo2 = fopen("PRECIOSORDENADOS.DAT", "wb+");
	
	for(i=0; i< tam; i++){
		precios.articulos = articulos[i];
		precios.descripcion= descripcion[i];
		precios.nroProveedor = proveedor[i];
		
		fwrite(&precios, sizeof(Precio), 1, archivo2); 
	}
	
	fseek(archivo2,0,SEEK_SET); //esto en el caso que quiera leer
	
	//c y d forma de mostrarlos :-?
	int j;
	
	while(!feof(archivo2)){
		for(j=0; j < sizeof(precios); j++){
			
		}
	}
	
	
     	
	return 0;
}

//menor-mayor
void ordenCreciente(int v[], int tam){
	int j,i,aux; 
	for(i=1; i< tam; i++){
		for(j=1; j <= tam-i; j++){
			if(v[j-1]> v[j]){
				aux = v[j];
				v[j]= v[j-1];
				v[j-1]= aux;
			}
		}
	}
	
	return;
}

//menor a mayor
void ordenDescripcion(string datos[], int n){ 
	int i, j;
	char aux[30];
	for(i=1; i<n; i++){
		for(j=1; j<=n-i; j++){                             
			if(strcmp(datos[j-1], datos[j] ) > 0){ 
				 strcpy(aux,datos[j]); 		 
				 strcpy(datos[j], datos[j-1]);
				 strcpy(datos[j-1],aux);
		
			}	
		}
	}
	return;
}






