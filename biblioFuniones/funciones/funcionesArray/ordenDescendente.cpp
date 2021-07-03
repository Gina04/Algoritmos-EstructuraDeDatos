#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}

//4,3,2,1
void ordenDescendente(int v[], int n){
	int i, j,aux;
	for(i=1; i < n; i++){ //recorre
		for(j=0; j<=n-i;j++){ // ordena
			if(v[j+1]>= v[j]){ // el menor valor lo va desplazando hacia abajo.
				aux= v[j];
				v[j] = v[j+1];
				v[j+1]=aux;
				
			}
			
		}
	}
	return;
}
