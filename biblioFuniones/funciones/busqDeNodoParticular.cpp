#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}

/*Para efectuar una busqueda de un nodo en particular declaramos un puntero a lista 
  .Supongamos que buscamos un el valor = 42 de una Lista de numeros
  Chequeo:
  1) p es distinto de NULL(osea no llego a fin de lista) si es distinto 
  chequeo la siguiente condicion: 
  2) p-> info.id es distinto del valor que ingreso por parametro? 
    1.A) si es distinto: 
  		* Va a significar que no encontro el valor buscado entonces:	  	
  3) entra al while y avanzo con el puntero p al siguiente Nodo.
    1.B) Si es igual en alguno de las 2 condiciones:
		* va a significar que el valor no se encontro. 
		* o que llego a fin de la lista. 
	4) Y sale y me retorna el puntero P y devuelve:
		*El p!=NULL en el caso de haber encontrado el valor que buscamos . 
		*En otro caso el puntero p==NULL.
  
  
*/
NodoLp*buscarInsertar(NodoLp *& lista,int x){
	NodoLp * p = lista; 
	
	while(p!=NULL && p->info.id != x){ 
	   p= p->sgte;  
	}
	return p;
}
