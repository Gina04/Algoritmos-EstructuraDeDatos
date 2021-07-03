#include <iostream>
using namespace std;

/* 2.	Ingresar un valor entero N (< 30) y a continuación un conjunto de N elementos. Si el último
 elemento del conjunto tiene un valor menor que 10 imprimir los negativos y en caso contrario los demás */

int main() {
	int n, valor[n], i;

	cout<<"Ingrese tamanio del vector menor a 30"<<endl;
	cin>>n;
	
	int vec[n];
	cout<<"Ingrese un valor: "<<endl;
	
	for(i=0; i< n; i++){
	    cin>> valor[i];	   
	    
	}
	
	//cout<< "La posicion: " << i<< endl;
   //	cout<< "Ultima posicion: "<< valor[i-1];
	
	  
	if(valor[i-1]< 10 ){
	 	for(i=0; i<n;i++){
	 	 	if(valor[i]<0 ){
	 	 		cout<< "Negativos: " << valor[i];
			}
		}   			 
	}else{
		for(i=0; i<n; i++){
			cout<< "Positivos: " << valor[i]<<endl;
		}
		
	}
	  	
	
	return 0;
}
