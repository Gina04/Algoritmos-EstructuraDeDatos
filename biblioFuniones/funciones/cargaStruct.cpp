#include <iostream>
struct t_registro{
	int tel; 
	int edad;
};

struct Nodo{
	t_registro info;
	Nodo*sgte;
};

//prototipo
void cargar_registro(Nodo*&, t_registro & );


int main(int argc, char** argv) {
	
	//ejemplo de aplicacion
	
	Nodo*lista = NULL; 
	t_registro registro;
	
	for(int i; i< 4; i++){
		cargar_registro(lista, registro);
	}
	return 0;
}

void cargar_registro(Nodo*&lista, t_registro & registro){
	
		cout<< "Ingrese edad:";
		cin>> registro.edad;
		
		cout<< "Ingrese telefono: ";
		cin>> registro.tel;
		
		insertar_ordenado(lista,registro);
		
		return;
};
