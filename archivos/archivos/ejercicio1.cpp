#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include<conio.h>
using namespace std;
/*
Se conoce de cada alumno de un curso los siguientes datos: legajo (8digitos) 
y las notas de 2 parciales (0..10), que finaliza con un legajo negativo.
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado 
y grabe un archivo binario CURSO.BIN con una línea por cada alumno, con el número de legajo 
y su promedio (real).
*/

struct Alumno{
	int legajo;
	float promedio;
};


int main() {
	
	FILE *archivo ;
	archivo = fopen("CURSO.BIN ", "wb+");
	
	Alumno alumno;
	int i=0;
	float suma=0, nota1, nota2;
	
	//ingreso los datos al registro 
	cout<<"Ingrese legajo (8 digitos): ";
	cin>>alumno.legajo;
	
	while(alumno.legajo > 0){
	
	cout<< "ingrese nota1:";
	cin>>nota1;
	
	cout <<"Ingrese nota2: ";
	cin>>nota2;
	
	suma= nota1+nota2;
	alumno.promedio = suma / 2; 
	
	
	fwrite(&alumno,sizeof(alumno),1,archivo); //grabo los datos 
	
	cout<<"Ingrese legajo (8 digitos):";
	cin>>alumno.legajo;
		
	}
	
	fclose(archivo);
	
	//leo registro y lo guardo en memoria, osea en el registro alumno.
	// y los leo por pantalla
	
	archivo = fopen("CURSO.BIN ","rb+"); //abro nuevamente ya que cerre el archivo ant.
	
	fread(&alumno, sizeof(alumno),1, archivo);
	
	while(!feof(archivo)){ //si no es fin de archivo leo
		cout<<alumno.legajo<<endl;
        cout<< alumno.promedio<<endl;
    	fread(&alumno, sizeof(alumno),1,archivo);
	}

	
	return 0;
}
