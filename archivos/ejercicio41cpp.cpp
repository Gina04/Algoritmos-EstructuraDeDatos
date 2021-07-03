#include  <iostream>
#include  <cstring>
#include  <string>
#include  <stdio.h>
using namespace std;

/*
Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que genere un archivo ordenado por número de legajo (cada registro debe tener los campos
legajo y apellido y nombre) para todos los alumnos que se inscribieron una o más veces. 
Cada legajo debe ocupar una posición única y predecible en el archivo. El intervalo de los
legajos es 80001 a 110000, pueden no presentarse todos los legajos.

*/

//prototipos
int cantidadRegistros(FILE*);
void ordenarLegajos(int[], int);

struct Legajo{
	char nombreYapellido[25];
	int legajo; 	
	
};

int main() {
	
	int tam,i=0;
	// vinculo la memoria al disco donde estan los arhivos;
    FILE * arch1;
    FILE * arch2;
    
   //abro archivo MATFINALES.DAT para lectura
   arch1 = fopen("MATFINALES.DAT", "rb+");
   
    Legajo alumnos;
    
    fread(&alumnos, sizeof(alumnos), 1, arch1);
     // recorro el registro para averiguar la cantidad de bytes
    while(!feof(arch1)){
    	
   	 fread(&alumnos, sizeof(alumnos), 1, arch1);
     }
   
     //obtengo la cantidad de registros para utilizarlo en el tam de array 
	  
     tam = cantidadRegistros(arch1);
	
     int alum[tam]={0};
      
    //me vuelvo a posicionar al principio del archivo 
    fseek(arch1,0,SEEK_SET);
    
    //leo el archivo arch1 y guardo estos datos en el vector
    fread(&alumnos, sizeof(alumnos), 1, arch1);
    
	while(!feof(arch1)){
		
		if(alumnos.legajo>80001 && alumnos.legajo < 11000000){
		 alum[i] = alumnos.legajo; // guardo vector
		}
		i++;
		
		fread(&alumnos, sizeof(alumnos), 1, arch1);
	
	}
	
	
    //ordeno el vector de legajos con burbuja de menor a mayor
      
   	ordenarLegajos(alum, tam);
   	
   	
	// for(i=0; i<5;i++){
	//	cout<< num[i]<< endl;
	//}
   
   
   	//lo grabo en el arch2 el array con los legajos ordenados
   	
   	arch2 = fopen("LEGAJOSORDENADOS.DAT", "wb+");
   	
   	for(i=1;i<tam;i++){ //sera porque arch comienza en 1?
   		alumnos.legajo= alum[i];
   		fwrite(&alumnos,sizeof(alumnos),1,arch2); //grabo los datos 
	   }
	   //importante cuando grabe el puntero se ubico al final
	   //por eso vuelvo a indicar que se empieze a leer desde la posicion inicial :)
	   
	   fseek(arch2,0,SEEK_SET); 
   	
   	/*leo los datos de arch2 */ 
   	
   	fread(&alumnos, sizeof(alumnos), 1, arch2);
   	
   	while(!feof(arch2)){
   		
   		cout<<alumnos.legajo<<endl;
   	
   		fread(&alumnos, sizeof(alumnos), 1, arch2);
	   }
	   
	fclose(arch1);   
	fclose(arch2);
	   
     

	return 0;
}

//Defino las funciones

int cantidadRegistros(FILE*arch1){
	//retorna la cantidad de registro de un archivo
	Legajo r;
	fseek(arch1,0,SEEK_END); //pone el puntero al final del archivo
	return ftell(arch1)/sizeof(r);//cantidad de bytes desde el principio/tamaño del registro
	
}

void ordenarLegajos(int v[], int tam){
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




