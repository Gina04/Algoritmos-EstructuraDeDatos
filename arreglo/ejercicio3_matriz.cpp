#include <iostream>
using namespace std;

/* 
  Hacer una matriz de tipo entera de 2 * 2, llenarla de números y luego copiar todo su 
  contenido hacia otra matriz.
 */

int main() {
	int numeros[2][2]= {{1,2},{3,4}};
	int matriz2[2][2];
	int i, j;
	
	//Pasando el contenido de numeros hacia matriz2
	for(i=0; i<2; i++){
		for(j=0; j<2;j++){
			matriz2[i][j]=numeros[i][j];
		}
	}
	//Mostrando matriz2
	for(i=0; i<2; i++){
		for(j=0;j<2; j++){
			cout<< matriz2[i][j];
		}
		
		cout<<"\n";
	}
	
	return 0;
}
