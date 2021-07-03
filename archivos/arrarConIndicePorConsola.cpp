#include <iostream>
using namespace std;
/*  */

int main() {
	
	int valor, i=0;
	int array[5]={0};
	int num[5]={1,2,3,4,5};
	
	cout<< "Valor: ";
	cin>> valor;
	
	while(valor>0){
		
		for(int i=0; i< 5; i++){ // recorro el array
			if(valor == num[i]){
			array[valor]++;
			
		  }
		}
		
		cout<< "Valor: ";
     	cin>> valor;
		
		
	}
	
	for(int j=0; j<5; j++){
		cout<<"Hay "<<array[j]<< "de" << j<< endl;
	}
	return 0;
}
