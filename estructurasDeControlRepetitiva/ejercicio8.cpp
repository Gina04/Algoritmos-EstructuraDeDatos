#include <iostream>
using namespace std;

int main() {
	int numero;
	int promedio=0; //acumulador
	int suma=0; //acumulador
	int i, cantidad;//contadores
	int sumaPromedio=0;//acumulador
	
	cout<<"Ingrese valor: "<<endl;
   	cin>>numero;
   	
    for(i=0; i<51;i++){
        
        if(numero < -10){
       	     suma+= numero;
       	     
    
	     }else if(numero>100){
	     	sumaPromedio+=numero;
	     	cantidad=i;  	
		 }
	cout<<"Ingrese valor: "<<endl;
   	cin>>numero;
	   	     
}
   promedio = sumaPromedio/cantidad;
   cout<<"El promedio de todos los valores mayores que 100 es:"<<promedio << "y la suma de all menores -10 es: "<<suma;
  
    
	
	
	return 0;
}
