#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
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
