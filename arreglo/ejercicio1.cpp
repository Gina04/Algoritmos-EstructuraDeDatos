#include <iostream>
using namespace std;
/*
1.	Dado un número N (<30), genere e informe un vector VEC de N elementos que contenga los 
primeros N números naturales pares.

*/
int main() {
	int  n, i;	
    cout << "Ingrese tamaño de vector menor que 30:";
	cin>> n;
	int vec[n];	
	
	for(i=0; i< n; i++){
	  vec[i]= i*2;
		
	}

	for(i=0; i<n; i++){
	cout<< vec[i]<<endl;
	}
	
	return 0;
}
