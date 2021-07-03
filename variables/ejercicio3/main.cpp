//Realizar la suma de todos los numeros pares entre 2 al 10000
//Como es el ingreso de valorde del 2 hasta 10000.?

#include <iostream>

using namespace std;
//Prototipo
bool numeroPar(int numero);

int main(){

int suma=0;
int i;
//int numero;


for(i=0;i<10000; i+=2){
   suma+=i;
}

cout<< "La suma de numeros pares del 2 hasta el 10000 es:" << suma;



return 0;
}


//Desarrollar prototipo

bool numeroPar(int numero){
    return numero%2 == 0;


}
