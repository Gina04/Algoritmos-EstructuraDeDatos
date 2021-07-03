#include <iostream>
using namespace std; 

int main() {
	float valor,suma;
	float maxNeg=0,minPos=0,rango=26.9,promedio;
	int aux,contador=0;
	int i=0;
	
		cout<<"ingrese un valor: "<<endl;
		cin>>valor;	
	
	while(valor!=0){
		
		
     //negativos- maximo negativo
	 if(valor<0){
	 	if(maxNeg==0 || valor > maxNeg){
	 		maxNeg=valor;
		 }
			}
	 
	//positivos - minimos positivos
	 if(valor>0){
	 	if(minPos==0 || valor < minPos){
	 		minPos=valor;
		 }
	 }
		
		if(valor<rango && valor>-17.3){ //entre -17.9  y 26.9
			rango=valor;
		}
		
		suma+=valor;
		contador++;
		
		
		cout<<"ingrese un valor: "<<endl;
		cin>>valor;
		
				
	}
	
	promedio=suma/contador;
	
	cout<<"el promedio de los valores es: "<<promedio<<endl;
	cout<<"el maximo negativo es: "<<maxNeg<<endl;
	cout<<"el minimo positivo es: "<<minPos<<endl;
	cout<<"el valor minimo del rango -17.3 y 26.9 es: "<<rango<<endl;
	return 0;
}
