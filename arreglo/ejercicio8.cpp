#include <iostream>
#include <string.h>
using namespace std;
 
//Prototipos
void ordenAscendente(int[], int);
void ordenDescendente(int[],int); 

int main() {

    int valor, tam, i;
	
	cout<< "Ingrese tamanio:";
	cin>> tam;
	
	int valores[tam]={0};
	
	for(i=0; i<tam; i++){	
	cout<< "Ingrese valor:";
	cin>> valores[i];
	
	}
	
   	ordenDescendente(valores, tam);
   	//ordenDescendente(valores,tam);

	for(i=0; i< tam; i++){
	//cout<< "Muestro el arreglo de mayor a menor: " << valores[i]<<endl;
	 cout<< "Muestro el arreglo de menor  a mayor: " << valores[i]<<endl;
	}
	system("PAUSE"); 
	return 0;
}

//  1,2,3,4,5 

void ordenAscendente(int v[], int N) {
    int i,j, aux;
    for(i = 1; i < N; i++){ //recorre
        for( j = 1; j <= N-i;j++){ //ordena
            if(v[j-1] > v[j]){    // el mayor valor lo va desplazando hacia abajo.
                aux = v[j];
                v[j] = v[j -1];
                v[j-1] = aux;
            }
        } 
    }
return;
}

//4,3,2,1
void ordenDescendente(int v[], int n){
	int i, j,aux;
	for(i=1; i < n; i++){ //recorre
		for(j=1; j<=n-i;j++){ // ordena
			if(v[j-1]<= v[j]){ // el menor valor lo va desplazando hacia abajo.
				aux= v[j];
				v[j] = v[j-1];
				v[j-1]=aux;
				
			}
			
		}
	}
	return;
}



