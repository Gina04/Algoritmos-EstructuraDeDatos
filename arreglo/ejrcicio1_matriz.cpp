#include <iostream>

using namespace std;

/*
Ejercicio 1: Hacer un programa para rellenar una matriz pidiendo al usuario el número de
filas y columnas, Posteriormente mostrar la matriz en pantalla.
 */

int main() {
	int numeros[100][100], filas, columnas, j, i;
	
	cout<< "Digite el numero de filas:";
	cin>>filas;
	
	cout<< "Digite el numero de columnas:";
	cin>>columnas;
	
	//almacenando elementos en la matriz
	for(i=0; i<filas; i++){ 
		for(j=0; j<columnas; j++){
			cout<<"Digite un numero ["<< i<< "]["<<j<<"]";//[0][0]
			cin>> numeros[i][j];
		}
	}
	//Mostrando la matriz
	for(i=0; i< filas; i++){
		for(j=0; j< columnas; j++){
			cout<<numeros[i][j];
		}
		cout<< "\n";
	}
	
	return 0;
}
