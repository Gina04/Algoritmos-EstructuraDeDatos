#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

struct Hotel{
	int codigo;
	int cantHabitaciones;
	int cantDiasDisponibles;
};


int main(int argc, char** argv) {
	Hotel reservas[100]={0};
	int codigo, i=0; 
	char respuesta = 's';
	Hotel pup; 
	
	cout <<"CARGE EL STRUCT DE HOTELES" << endl;
	
		while(respuesta == 's'){
		cout<< "Ingrese codigo de hotel entre 1000 y 1100: ";
		cin>>reservas[i].codigo;
		
		cout<< "ingrese cantidad habitacion del hotel " <<"--> "<< i << ": ";
	    cin>>reservas[i].cantHabitaciones; 
	    
	    cout<< "Ingrese cantidad de dias disponibles en la temporada: "; 
	    cin>> reservas[i].cantDiasDisponibles; 
	    
	    cout<< "Desear realizar una nueva carga (s/n):"; 
	    cin>> respuesta;
	    i++;
    }
    
    cout<< "Carge un codigo  a buscar:"; 
    cin>> codigo; 
    
    for(int i=0; i < 100; i++){
    	reservas[codigo - 0]= reservas[]; 
    
	}
	
	for(int i=0; i < 100; i++){
		cout<< pup.codigo; 
	}
    

    system("PAUSE");
	return 0;
}
