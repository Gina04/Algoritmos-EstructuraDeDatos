#include <iostream>
using namespace std;

/* 
3.	Dado un conjunto (<100) de valores enteros de los cuales el último es cero y no
debe procesarse:
a.	informe el valor mínimo, su posición dentro del conjunto, si el mínimo no es único, informar todas las posiciones donde 
    se encuentre.


 */
 
 //Prototipo 
 
int main() {
	int n, minimo, tam, producto=1;
	int v[100], pos[100]={0};
	int i=0, j=0; // cada vector tiene su indice

    // TODO: tengo que definir la posicion logica del vector !!
    cout<< "Ingrese tamaño del vector :";
    cin>> tam;
    
	cout<<"valor:";
	cin>>n;
	
	 while (tam<100 && n!= 0){
		v[i] = n;
		//minimo- le asigno la primer lectura 
		if(i==0 || v[i]<= minimo){
				minimo = v[i];
				pos[j]=i;
		
		}
		
		
		//b.informe el producto de los elementos impares que ocupen posición par.	
		if(i%2==0){
			if(v[i] % 2 != 0){
				producto*= v[i];
			}
			
		}
		
		j++; 
		i++; 
		
		cout<<"Valor:";
    	cin>>n;
		
	}
	
	cout<< "El minimo es: " << minimo << endl;
	
	for(j=0; j<tam; j++){
		cout << "La posicion es: " << pos[j]<<endl;
	}
	
	cout<< "El producto de los numeros impares en la posicion par es:" << producto<<endl;
	
	
	

	
	 
 


	return 0;
}
