#include <iostream>
#include <cstring>
using namespace std;

/* 
Una empresa que distribuye mercadería hacia distintas localidades del interior dispone de dos archivos de registros:
Uno denominado DESTINOS con información de la distancia a cada uno de los destinos: a) Nro. De destino (3 dígitos) b) Distancia en kilómetros (NNN.NNN)
Otro denominado VIAJES con los viajes realizados por cada camión (< 200), donde cada registro contiene:
a) Patente del camión (6 caracteres)
b) Nro. de destino
c) Nro. de chofer (1 a 150)

Desarrollar estrategia, algoritmo y codificación del programa que determine e imprima:

1) Cantidad de viajes realizados a cada destino (solo si > 0).
2) Nro. de chofer con menor cantidad de Km (entre los que viajaron).
3) Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.

 */
 
struct Destino{
	int nroDestino;// 3 digitos
	float distanciaEnKilometros; //(NNN.NNN)
	
}; 

struct Viaje{
    char patenteCamion[6]; //(6 caracteres)
    int nroDestino;
    int nroChofer; //(1 a 150)
};
//pto 1
struct Tarray{
	float distanciaEnKilometros;
	int contadorDestinos;
	int len;
	char patenteCamion[200];
};

int main() {
	
	int i, mayor=0, pos=0, menor=0, j;
	FILE*f1;
	FILE*f2;
	
	int choferAcumKm[150]={0};
	Tarray destinos[1000]; // 1000- X condicion de enunciado
	
	//Inicializo el for
	
	for(int i=0; i< 1000; i++){
		destinos[i].distanciaEnKilometros=0;
	}
	
	// abro archivo para lectura
	f1 = fopen("VIAJES.DAT", "rb+"); //--> novedades
	f2 = fopen("DESTINOS.DAT", "rb+"); //--> consultas
	
	Destino destino;
	Viaje viaje;
	// paso este archivo a un array ya que se va a recorrer varias veces
	// y no se puede recorrer un archivo + 1 vez.
	
	fread(&destino, sizeof(destino), 1, f1);
	
	while(!feof(f1)){
		//cargo archivo al srtuct
	    destinos[destino.nroDestino].distanciaEnKilometros= destino.distanciaEnKilometros;
		destinos[destino.nroDestino].contadorDestinos = 0 ;
		destinos[destino.nroDestino].len=0;
		
		fread(&destino, sizeof(destino), 1, f1);
	}
	fflush(f1);
	
	//1) Cantidad de viajes realizados a cada destino.
	
	fread(&viaje, sizeof(viaje), 1,f2);
    
	while(!feof(f2)){
		
	    for(i=0; i< 1000; i++){ //recorro el array destinos[1000] y incremento;
	    	if(viaje.nroDestino == i){ // numero de destino coincide con el indice incremento
	    		destinos[i].contadorDestinos++;
	    		//3) Patente de los camiones que viajaron a un destino sin repeticion
	    		 if(destinos[i].patenteCamion =='\0' || strcmp(viaje.patenteCamion, destinos[i].patenteCamion)!= 0){ //si el array esta vacio o si son distintos hacer
	    			strcpy(destinos[i].patenteCamion, viaje.patenteCamion); //copio la petente en el arraisito
				}
	    		   	    	
			}
		}
		
		//sumatoria de kilometros recorrido por chofer
		for(int j=1; j< 150; j++){
			if(viaje.nroChofer == j) {
				choferAcumKm[j]+= destinos[viaje.nroDestino].distanciaEnKilometros;
			}
		    	
		}
		
	
	fread(&viaje, sizeof(viaje), 1,f2);
	
	}	
	
	//IMPRIMO
	//1. cantidad de viajes  cada destino
	// quien es el responsable de darme este dato? - El array destinos[999]
	
	
	for(int j=1; j<1000; j++){
		if(destinos[j].distanciaEnKilometros > 0){ // solo imprimo aquellos destinos cuya distancia >0
		cout<< "En el destino"<<j <<"se realizaron:" << destinos[j].contadorDestinos<< "viajes"<< endl;

		}
	}
	
	//2. Nro chofer con menor cantidad de viajes,(entre los que viajaron)
	
	for(j=1; j< 150; j++){
		if(choferAcumKm[j]>0){
			if(menor==0||choferAcumKm[j] < menor){
			menor = choferAcumKm[j];
			pos = j;
		    }
		}
	}
	
	cout << "El nro de chofer con menor nro. destinos es: " << pos;
	
     //3) Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
 	for(int j=0; j<1000; j++){
 		if(viaje.nroDestino == 116){
 			for(int i=1; i<50; i++){
 			cout<<"Patente de camion que viajaros al destino 116:"<<destinos[i].patenteCamion;
		 	}
		}
 	
	 }	
	 
	fclose(f2);
	fclose(f1);
	
	
	return 0;
}
