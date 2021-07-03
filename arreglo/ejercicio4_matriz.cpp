#include <iostream>
using namespace std;
/* 
Hacer una matriz preguntando al usuario el numero de filas y columnas,
llenarla de números aleatorios, copiar el contenido a otra matriz y por 
último mostrarla en pantalla.

 */

int main() {
	int i,j, filas, columnas;
	
	cout<<"Ingrese numero de filas: ";
	cin>>filas;
	cout<< "Ingrese numero de columnas: ";
	cin>> columnas;
	
	int matriz1[filas][columnas];
	int matriz2[filas][columnas];
	
	//cargo una matriz por consola y copio contenido a otra matriz
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			cout<< "Ingrese numeros aleatorios ["<<i<<"]["<<j<<"]";
			cin>>matriz1[i][j];
			
			matriz2[i][j]= matriz1[i][j];
		}
	}
	//Muestro matriz
	for(i=0; i< filas; i++){
		for(j=0; j<columnas; j++){
			cout<< matriz2[i][j];
		}
		
		cout<<"\n";
	}
	
	return 0;
}
