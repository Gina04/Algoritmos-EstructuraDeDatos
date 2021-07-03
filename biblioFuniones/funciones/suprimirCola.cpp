#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}

int suprimir_cola(Nodo*&fte, Nodo*&fin){
	int v; 
	Nodo*aux = fte;
	v = fte->info;
	if(fte==NULL){
		//fte = NULL;
		fin = NULL;
	}else{
		fte = fte->sgte;
	}
	
	delete aux;
	return v;
}
