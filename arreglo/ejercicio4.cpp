#include <iostream>
using namespace std;


int main() {

	int tam, valores; 
	int  i=0, a=0, b=0, c=0, d=0;
	
	cout<< "Ingrese valores entre [1...24]:";
	cin>>tam;
	
	float vectorB[tam]={0}, vectorA[tam]={0}, vectorC[tam]={0}, vectorD[tam]={0};
	
	cout<<"Ingrese valorA:"<<endl;
    cin>>vectorA[a];
	
	cout<< "Ingrese valorB:";
	cin>> vectorB[b];
	
	while(i<tam){
		
		//posicion impar vectorA
	    if(a % 2 !=0){
	    	vectorC[c]= vectorA[a];
	    	
		}
		//posicion par vectorB
		if(b % 2 == 0){
			vectorC[c] = vectorB[b];
			
		}
		
		//b. genere e informe un tercer vector D donde cada elemento contenga un valor cero si
        //los elementos de una misma posición de A y B son iguales, o un valor uno si no lo
        //son.
        
        if(vectorA[a]== vectorB[b])
        	vectorD[d]=0;
		else
		    vectorD[d]=1;
		
		
		i++;
		a++;
		b++;
		c++;
		d++;
			
		cout<<"Ingrese valorA:"<<endl;
        cin>>vectorA[a];
	
    	cout<< "Ingrese valorB:";
    	cin>> vectorB[b];
	
		
	}
	
	
	 for(c=0; c<tam; c++){
	 	cout<< "El valor intercalados del vectorC[]:"<<vectorC[c]<<endl;
	 	
	 }
	 
	 for(d=0; d<tam; d++){
	 	cout<< "El valor del vectorD[], 0 si es igual y 1 si es distinto: " << vectorD[d]<<endl;
	 }
	
	
	return 0;
}
