#include <iostream>
#include <cstring>
using namespace std;
/*Me costo un monton este ejercicio, pero de todos los que hice me encantó porque aprendi un monton de cosas sobre el char, primero ingreso los datos
en una pila hasta que me ingresa un punto, luego declaro con un contador previo un for que me digite en otra pila el segundo conjunto (siempre
suponiendo que ambos conjuntos tiene la mismma longitud) luego de ambas pilas los guardo en dos arrays distintos, ordeno ambos y los comparo
con strcmp si son iguales es porque cuando se ingreso eran inversos, si no son iguales es porque no lo eran*/
struct Nodo{
	char info;
	Nodo *sgte;
};

void push(Nodo*&, char);
char pop(Nodo*&pila);
//void ordenarVectorAscendente(char [], int );
//bool inversa(char [],char []);

int main() {
	
	Nodo*pila1=NULL;
	Nodo*pila2=NULL;
	
	char caracter;
	int contador=0;
	
	cout<<"ingrese el conjunto de caracteres separado por un punto: "<<endl;
	cout<<"ingrese un caracter (termina con un punto): "<<endl;
	cin>>caracter;
	cout<<caracter;
	
	while(caracter!='.'){
		push(pila1,caracter);
		cout<<"ingrese un caracter (termina con un punto): "<<endl;
		cin>>caracter;
		contador++;
	}
	//cout<<"tamanio del primer conjunto: "<<contador<<endl;
	int i;
	for(i=0;i<contador;i++){
		cout<<"ingrese el siguiente conjunto, caracter por caracter, (termina con un punto: "<<endl;
		cin>>caracter;
		push(pila2,caracter);
		
	}
	
	char vecPila1[contador],vecPila2[contador];
	
	for(i=0;i<contador;i++){
		vecPila1[i]=pop(pila1);
		//cout<<"guardando elementos en vec pila 1:"<<vecPila1[i]<<endl;
	}
	int j;
	for(j=0;j<contador;j++){
		vecPila2[j]=pop(pila2);
		//cout<<"guardando elementos en vec pila 2:"<<vecPila2[j]<<endl;
	}
	
	//comparo las listas
	
	for (i=0;i<contador;i++){
		
		if(vecPila1[i] == vecPila2[contador-1]){
			cout<< "true";
		}else{
				cout<< "false";
		}
	}
	
  	//ordenarVectorAscendente(vecPila1,contador);
	//ordenarVectorAscendente(vecPila2,contador);
	/*cout<<"mostrando vec pila 1 ordenado:"<<endl;
	for(j=0;j<contador;j++){
		cout<<vecPila1[j]<<endl;
	}*/
	
	//cout<<"si retorna ""1"" es true, si retorna ""0"" es false: "<<endl;
	//cout<<inversa(vecPila1,vecPila2);
	
	return 0;
}

void push(Nodo*&pila, char x){ //meter elementos a la pila
	Nodo*p=new Nodo();
	//strcpy(p->info,x);
	p->info=x;
	p->sgte=pila;
	pila=p;
	return;
}
char pop(Nodo*&pila){ //saca elemento de la pila
	char x;
	Nodo*p=pila;
	//strcpy(x,p->info);
	x=p->info;
	pila=p->sgte;
	return x;
}
void ordenarVectorAscendente(char v[], int N) {// v el vector a ordenar N cantidad de componentes
	int i,j; 
	char aux;
	for(i = 1; i < N; i++){// pasos
		for( j = 1; j <= N - i;j++){//comparaciones en cada paso
			if(v[j-1] > v[j]){
				aux = v[j];
				v[j] = v[j -1];
				v[j - 1] = aux;
			}
		} // fin ciclo interno
	}// fin ciclo externo
return;
} // fin de la funcion
bool inversa(char vec1[],char vec2[]){
	if(strcmp(vec1,vec2)==0){
		return true;
	}else{
		return false;
	}
	
}

