#include <iostream>
#include<cstring>
using namespace std;

/* 
Dado el archivo ‘ALUMNOS.dat’ con los datos personales de alumnos ordenado por legajo, con el siguiente diseño:
a. Legajo (8 digitos)
b. Apellido y nombre ( 30 caracteres)
c. Domicilio (20 caracteres)
d. Código postal (4 digitos)
e. Teléfono (10 caracteres)
f. Año de ingreso (4 digitos)
Y otro archivo sin orden que el mencionado llamado ‘NOVEDADES.dat’, con cantidad
máxima de registros es 100. Posee las actualizaciones (altas, bajas, y modificaciones) a 
ser aplicadas, donde cada registro contiene además de todos los campos de Alumnos.dat un
código de operación (‘A’= Alta, ‘B’= Baja, ‘M’= Modificación).
Se pide desarrollar todos los pasos necesarios para realizar un programa que genere un
archivo actualizado ‘ALUMACTU.dat’ con el mismo diseño.

 */
 
struct Alumno{
	int legajo;
	char nombreYApe[30];
	char domicilio[20];
	int codigoPostal; 
	char telefono[10];
	int anioIngreso;

	 
	
};

struct Novedades{
	int legajo;
	char nombreYApe[30];
	char domicilio[20];
	int codigoPostal; 
	char telefono[10];
	int anioIngreso;
	char alta = 'A';
	char baja = 'B'; 
	char modificacion = 'M';
	 
	
};
 

int main() {
	
	// ALUMNOS.DAT
	//NOVEDADES.dat
	//ALUMACTU.dat 
	
	
	return 0;
}
