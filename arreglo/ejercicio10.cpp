#include <iostream>
using namespace std;

int main() {
	int tablas[10][10]={0};
    int i, j;
    
    for(i=1; i<10;i++){ //recorre filas //10
    	for(j=1; j<10;j++){ //recorre columnas //0,1,2,3
    		tablas[i][j]= j*i;
		}
	}
	
	//Muestro la matriz 
	for(i=1; i<10;i++){
		for(j=1; j<10; j++){
			cout<<tablas[i][j];
		}
		cout<< "\n";
	}
	
	
	return 0;
}
