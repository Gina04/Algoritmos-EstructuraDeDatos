#include <iostream>
using namespace std;

/* 
Dado un conjunto de N cursos ( <=20) de la cátedra de algoritmos, de cada uno
de ellos código de curso ( 4 caracteres) y cantidad de alumnos, y de cada curso 
el número de legajo y nota (0..10) de los alumnos.
Se pide:
· informar de cada curso la cantidad de alumnos que tuvieron como nota 0, 1, ...,9, 10
· informar al final del proceso el código de curso, el % de aprobados y el de insuficientes 
  de cada curso.

 */
 struct Alumno{
 	int nota;
 	int legajo;
 };
 
 struct Algoritmos{
 	int cantAlumnos;
 	char codigo[4];
 	Alumno alumno;
 };

int main() {
	
	Algoritmos alumnos[20];
	int i, nota;
	
	for(i=0;i<=20;i++){
		cout<< "Cantidad de alumnos en el curso:"<<endl;
		cin>> alumnos[i].cantAlumnos;
		cout<<"Codigo del curso (4 caracteres):"<<endl;
		cin>>alumnos[i].codigo;
		cout<< "Legajo alumno: "<<endl;
		cin>>alumnos[i].alumno.legajo;
		cout<<"Nota alumno: "<<endl;
		cin>>alumnos[i].alumno.nota;
		//ver por corte de control
		for(j=0, i<=10;j++){
			if(alumnos[j].alumno.nota == j){
				
			}
		}
	}
	
	
	
	return 0;
}
