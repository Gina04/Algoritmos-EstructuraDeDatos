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

struct Legajo{
	char nombreYapellido[25];
	int legajo;  
	int codigoMateria;
	int dia; 
	int mes;
	int anioExamen;	
	
};

//prototipos
int cantidadRegistros(FILE*);
void ordenarLegajos(Legajo[], int);

int main() {	
	int tam,i=0, pup;
    FILE * arch1;
    FILE * arch2;
    
   //abro archivo MATFINALES.DAT para lectura
    arch1 = fopen("MATFINALES.DAT", "rb+");
    arch2= fopen("ARCHIVOORDENADOPUP.DAT", "wb+");
    Legajo alumnos;
    
     //leer el registro del archivo sin orden
         
    while(fread(&alumnos, sizeof(alumnos), 1, arch1)){
    	pup = alumnos.legajo - 80001; //Calcular la PUP, recordar que se debe restar el valor de la primera  de las claves posibles
         
		//fseek(arch1, pup*sizeof(Legajo),SEEK_SET);                             
        fseek(arch2, pup*sizeof(arch2),SEEK_SET); //hago un fseek para acceder a la posicion 
    	
    	fwrite(&alumnos, sizeof(Legajo),1,arch2); //graba el registro a un nuevo archivo
    	
    //	fread(&alumnos, sizeof(Legajo), 1, arch1);
	}
		
	
	//muestro el archivo nuevo 
	
	fseek(arch2,0, SEEK_SET);
	
	fread(&alumnos, sizeof(Legajo),1, arch2);
	while(!feof(arch2)){
		cout<< alumnos.legajo<< endl; 
		cout<< alumnos.nombreYapellido;
		
		fread(&alumnos, sizeof(Legajo),1, arch2);
	}
	
    
    fclose(arch2);
    fclose(arch1);
    
    


	return 0;
}






