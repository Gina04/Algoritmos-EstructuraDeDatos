#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int i, n;
	
	cout<< "Ingrese tamanio de vector: ";
	cin>>n;
	int v[n]={0};
	cout<< "Valor:";
	
	for(i=0; i< n ; i++){
		
		fflush(stdin);
		cin>>v[i];
	}
	
	for(i=0; i<n; i++){
		cout<< v[i];
	}
	
	
	return 0;
}
