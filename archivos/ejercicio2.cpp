#include <iostream>
#include <cstring>
using namespace std; 

/* 
Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el
mes de mayo.
Cada boleta tiene los siguientes datos: nombre y apellido, número de legajo, código
de materia, día, mes y año del examen. Los datos finalizan con un nombre y apellido nulo.
Desarrollar un programa que a partir del ingreso de las boletas mencionadas, por
teclado, genere un archivo binario de inscripción de alumnos a exámenes finales
DIAFINALES.DAT, según el siguiente diseño:
a. Nro. de legajo (8 dígitos)
b. Código de materia (6 dígitos)
c. Día del examen (1..31)
d. Mes del examen (1..12)
e. Año del examen (4 dígitos)
f. Nombre-Apellido (25caract)

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
	
	FILE*f;
	//creo y cargo datos
	f = fopen("DIAFINALES.DAT", "wb+");
	
	Boleta inscripcion;
	
	cout<<"Ingrese nombre y apellido: ";
	cin>> inscripcion.nombreYapellido;
	
	while(strcmp(inscripcion.nombreYapellido, "NULL")){
		cout<<"Legajo: ";
		cin>>inscripcion.legajo;
		
		cout<<"Codigo materia: ";
		cin>> inscripcion.codigoMateria;
		
		cout<<"Dia:";
		cin>>inscripcion.dia;
		
		cout<<"Mes:";
		cin>>inscripcion.mes;
		
		cout<<"Anio:";
		cin>>inscripcion.anioExamen;
		
		fwrite(&inscripcion,sizeof(inscripcion),1,f);
		
		cout<<"Ingrese nombre y apellido: ";
    	cin>> inscripcion.nombreYapellido;
		
	}
	
	fclose(f);
			
	return 0;
}
