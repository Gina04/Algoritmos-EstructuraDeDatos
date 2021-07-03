#include  <iostream>
#include  <cstring>
#include  <string>
#include  <stdio.h>
using namespace std;
/* 
Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que solicitando por teclado un código de materia permita seleccionar todos los registros
que se anotaron para rendirla y los grabe en otro archivo (MATFINALES.DAT), con el mismo
diseño.

*/

struct Boleta{
	char nombreYapellido[25];
	int legajo; 
	int codigoMateria;
	int dia; 
	int mes;
	int anioExamen;
	
};

int main() {
	int codigo;
	FILE* f1;
	FILE* f2;
	

	//abro para lectura DIAFINALES.DAT
	
	f1 = fopen("DIAFINALES.DAT", "rb+");
	f2=  fopen("MATFINALES.DAT", "wb+");
	
	
	
	cout<<"Ingrese codigo de la materia a buscar: ";
	cin>>codigo;
	
	Boleta inscripciones; // guardo en este registro lo que leeo de DIAFINALES.DAT
	
    fread(&inscripciones, sizeof(inscripciones), 1, f1);
	
	while(!feof(f1)){
	
		if(inscripciones.codigoMateria == codigo){
			//grabo codigo materia en f2
			fwrite(&inscripciones,sizeof(inscripciones),1,f2);
		}
		
		fread(&inscripciones, sizeof(inscripciones), 1, f1);
      }
      
      fclose(f1);
      fclose(f2);
      
     /* 
     hice esto para ver que se cargaba el archivo correctamente-no lo pide ejercicio.
     f2 = fopen("MATFINALES.DAT ","rb+"); 
      
     //leer f2
     fread(&inscripciones, sizeof(inscripciones),1,f2);  
    
     while(!feof(f2)){
    	cout<<inscripciones.nombreYapellido <<"-"<<inscripciones.legajo<<endl;
    
    	
    	fread(&inscripciones, sizeof(inscripciones),1,f2);  
	 }
	 
	 */
	 
     
      
	
	
	return 0;
}
