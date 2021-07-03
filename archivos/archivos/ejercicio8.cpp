#include <iostream>
#include <cstring>
using namespace std; 

/* PRACTICA4/ ARCHIVO/EJERCICIO 8*/

struct Vuelo{
	char codigoVuelo[6];
	int cantPasajesDisponibles;
};

struct Comprador{
	char codigoVuelo[6];
	int cantidadPasajesSolicitados;
	int dni;
	char apeYNom[30];
};

struct TArr{
	char codigoVuelo[6];
	int cantPasajesDisponibles ;
	int pasajesRechazados;
	
};
/* DUDAS 
   - Dudas con el struct del array y el struct del archivo VUELO.DAT --> Son distintos diseños esto a la hora de pasar datos de un 
   archivo al array hay algun problema?? No se puede.
   
   - Puedo dentro de un struct inicializar las variables?. Creo que no
   
*/

//Prototipos
bool procesarVentas(TArr[], int, int , char[]);
//void cargarArray(TArr[], FILE*); 

int main() {
	int i;
	int len=0; // tamanio logico
	TArr x;
	TArr arreglo[500]={0}; //me traigo los datos de vuelo a memoria ya que un codigo de vuelo puede ser accedido varias veces por concepto de archivos.
	
	FILE * f1;
	FILE * f2;
	
	
	//abro archivo VUELO.DAT lo recorro y agrego datos a struct de tipo TArr
	f1=  fopen("VUELO.DAT", "rb+");
	Vuelo v1;
	fread(&v1, sizeof(Vuelo),1, f1);
	
	while(!feof(f1)){
		strcpy (x.codigoVuelo, v1.codigoVuelo);
		x.cantPasajesDisponibles = v1.cantPasajesDisponibles;
		x.pasajesRechazados = 0;
		
		// agrego el elemento x de tipo TArr a mi array y soluciono lo de tipos de struc diferentes
		arreglo[len] = x; // grabo al array
		len++;
		
		fread(&v1, sizeof(Vuelo),1, f1);
	}
	

	// abro archico COMPRADORES.DAT para lectura
	f2 = fopen("COMPRADORES.DAT", "rb+");
	
	Comprador comprador;
	//leo el archivo y guardo en el struct comprador
	
	fread(&comprador,sizeof(comprador),1,f2);
	
	while(!feof(f2)){
		//verifico si se puede realizar la venta o no
		if(procesarVentas(arreglo, len, comprador.cantidadPasajesSolicitados, comprador.codigoVuelo )){
			// si puede comprar imprimo todo el registro que acabo de leer
			cout<< comprador.dni<<endl;
			cout<< comprador.apeYNom<< endl; 
			cout<< comprador.cantidadPasajesSolicitados<< endl; 
			cout<< comprador.codigoVuelo;
				
		}
		
		fread(&comprador,sizeof(comprador),1,f2);
	}
  
    // Imprimo el listado 2 --> Que esta en el array CodigoVuelo ---> PasajesDisponibles ---> PasajesRechazados
	
	 for(int j=0; j< 500; j++){
	 	cout<< "Codigo de Vuelo:" << arreglo[i].codigoVuelo<<endl;
	 	cout<< "Cantidad de pasajes disponibles: " << arreglo[i].cantPasajesDisponibles<< endl; 
	 	cout<< "Pasajes rechazados: " << arreglo[i].pasajesRechazados<< endl;
	 	
	 }	
	 
	 fclose(f2);
	 fclose(f1);
	
	return 0;
}

bool procesarVentas(TArr v[],int tam, int cantPasajesSoli, char codigoVuelo[]){
	int i;
	bool valorDeVerdad = true;
	for(i=0; i< tam; i++){
	   if(strcmp(v[i].codigoVuelo, codigoVuelo )){ //si codigo de vuelo existe hacer
	   	 if(v[i].cantPasajesDisponibles >= cantPasajesSoli){ // verifico si hay pasajes disponibles
	   	 	
	   	 	// y actualizo la cantidad disponible de pasajes con este codigo de vuelo	
			 v[i].cantPasajesDisponibles -= cantPasajesSoli; 
			 
			 return valorDeVerdad; 
	   	 	
			}else{
			 // acumulo la cantidad de pasajes rechazados

			 v[i].pasajesRechazados+= cantPasajesSoli; 
			  
		     valorDeVerdad = false;
		     
			 return valorDeVerdad;
			}
	   }
	}
		
};

/*void cargarArray(TArr v[],  FILE*f1){
	int len = 0; //tamanio del array
	Vuelo v1;
	//abro archivo VUELO.DAT lo recorro y agrego cada uno de los elementos al array
	f1=  fopen("VUELO.DAT", "rb+");
	
	fread(&v1, sizeof(Vuelo),1, f1);
	
	while(!feof(f1)){
		TArr x;
		strcpy (x.codigoVuelo, v1.codigoVuelo);
		x.cantPasajesDisponibles = v1.cantPasajesDisponibles;
		x.pasajesRechazados = 0;
		
		// agrego el elemento x de tipo TArr a mi array y no produciria error de tipos
		v[len] = x;
		len++;
		
		fread(&v1, sizeof(Vuelo),1, f1);
	}
	
}*/

