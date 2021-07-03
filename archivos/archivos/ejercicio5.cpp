#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std; 

/* 
Se dispone un archivo binario de inscripción de alumnos a exámenes finales
MAESTROFINALES.DAT y otro con las inscripciones del día de hoy DIAFINALES.DAT,
ambos ordenados ascendente por código de materia y con el siguiente diseño:
a. Nro de legajo (8 dígitos)
b. Código de materia (6 dígitos)
c. ApellidoNombre(25caract)
Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales
FINALESACT.DAT resultante del apareo de los dos archivos anteriores, con el mismo orden
y diseño.

 */
 

struct Inscripciones{
	int legajos;
	int codigoMat;
	char apellidoNombre[25];
	
}; 

int main() {
	
	FILE* f1;
	FILE* f2;
	FILE* f3;
	
	f1 = fopen("MAESTROFINALES.DAT", "rb+");
	f2 = fopen("DIAFINALES.DAT", "rb+");
	f3 = fopen("FINALESACT.DAT", "wb+");
	
	Inscripciones r1;
	Inscripciones r2;
	Inscripciones r3;
	
	fread(&r1, sizeof(r1),1,f1);
	fread(&r2, sizeof(r2),1,f2);
	
	while(!feof(f1) && !feof(f2)){ //Condición que no termine los 2 archivos.
		if(r1.codigoMat< r2.codigoMat){
 			fwrite(&r1, sizeof(r3), 1, f3); //si r1.codigoMat es menor que el 2, grabo el r1.codigoMat 
			                                //en Archivo f3
		fread(&r1, sizeof(r1),1,f1);//Vuelvo a leer el  f1,
				
		}else{
			fwrite(&r2, sizeof(r3), 1, f3) //si r2.codigoMat es menor  que el 1, grabo el r2.codigoMat
			                                // en Archivo f3.
			fread(&r2, sizeof(r2),1,f2); //Vuelvo a leer el  f2,
		}
	}
	
	
	
	while(!feof(f1)){ //Mientras no se termine el archivo 1
       fwrite(&r1, sizeof(r3), 1, f3); //Grabo lo que queda del archivo f1 sin grabar al archivo f3.
       fread(&r1,sizeof(r1), 1, f1)};
	
	while(!feof(f2)){ //Mientras no se termine el archivo f2
	fwrite(&r2, sizeof(r3), 1, f3);//Grabo lo que queda del archivo f2 sin grabar al archivo f3.
	fread(&r2,sizeof(r2), 1, f2)};  
	
	fclose(f3); //Cierro los archivos (todos).
    fclose(f2);
    fclose(f1);
	
	return 0;
}
