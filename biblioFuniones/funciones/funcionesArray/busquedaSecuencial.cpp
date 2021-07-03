#include <iostream>
#include <stdlib.h>
using namespace std; 
struct ObraRechazada{
	int idObra; 
	int cantRechazada;
};
int busquedasecuencial(ObraRechazada v[],int buscado,int N);

int main() {
	int cant=0;
	int valor;
	ObraRechazada array[5]; 
	
	cout<< "Valor:";
	cin>> valor;
	
	
	if(busquedasecuencial(array, valor, 5)>=0){
			array[busquedasecuencial(array, valor, 5)].cantRechazada = cant;
			
		}else{
			cout<< "el valor no se encontro";
		}

	 


	system("pause");
	return 0;
}

int busquedasecuencial(int v[],int buscado,int N)
{
	int i=0;	
	while(i<N && buscado!=v[i]){
		
		i++;
	}
	if(i<N)
		return i;
	else 
		return -1;
	// i<N?i:-1;
}


