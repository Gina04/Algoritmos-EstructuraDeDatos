#include <iostream>

//prototipo

void mostrar_nombre(char[]);

int main(int argc, char** argv) {
	return 0;
}
//FUNCION PARA MOSTRAR ARRAY DE CHAR
void mostrar_nombre(char nombre[]){
	int i=0;
	
	while(nombre[i] != '\0'){ // mientras no sea fin de cadena
		cout<< nombre[i] ;
		i++;
	}
	
};
