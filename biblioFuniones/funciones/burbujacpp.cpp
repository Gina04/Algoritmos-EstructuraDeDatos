#include <iostream>

//prototipos
void ordenCreciente(int[], int);
void ordenDescripcion(char[], int);

int main(int argc, char** argv) {
	return 0;
}

//menor-mayor
void ordenCreciente(int v[], int tam){
	int j,i,aux; 
	for(i=1; i< tam; i++){
		for(j=1; j <= tam-i; j++){
			if(v[j-1]> v[j]){
				aux = v[j];
				v[j]= v[j-1];
				v[j-1]= aux;
			}
		}
	}
	
	return;
}

//menor a mayor
void ordenDescripcion(string datos[], int n){ 
	int i, j;
	char aux[30];
	for(i=1; i<n; i++){
		for(j=1; j<=n-i; j++){                             
			if(strcmp(datos[j-1], datos[j] ) > 0){ 
				 strcpy(aux,datos[j]); 		 
				 strcpy(datos[j], datos[j-1]);
				 strcpy(datos[j-1],aux);
		
			}	
		}
	}
	return;
}

