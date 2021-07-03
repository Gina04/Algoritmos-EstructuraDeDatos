#include <iostream>
#include <string.h>
using namespace std;
// STRUCT DATOS DEL NODO

struct t_censo {
    char nombre[20];
    int edad;
    long dni;
};

// NODO

struct t_nodo {
    t_censo cen;
    t_nodo* sgte;
};

// PROTOTIPOS

void insertar_ordenado_sR( t_nodo* &, t_censo, t_nodo* &, bool & );
void sacar_nodo( t_nodo*& , t_censo & );  // nótese que esta función es la misma que sacar_pila, me sirve para ir extrayendo los nodos
void cargar_censo( t_censo & );
void mostrar_nombre( char [] );

int main(int argc, char** argv) {
	 t_nodo* lista = NULL;
	 t_nodo* rf = NULL;
     bool test;
     
    t_censo censo;
    
    char respuesta = 's';

    cargar_censo( censo );
    cout << endl;
    
    while ( respuesta == 's' ){

        insertar_ordenado_sR( lista, censo, rf, test );  // inserto si corresponde un nodo, VACIO!!, en la posición correcta dentro de la lista
        
         if ( !test ){                                    // acá pregunto por la booleana para saber si fue insertado, en tal caso inserto
            rf -> cen = censo;
        }
        
        cout << "    desea cargar mas personas ( s/n ): ";
        cin >> respuesta;
        cout << endl;
        cin.ignore();

        if ( respuesta == 's' ){
           cargar_censo( censo );
           cout << endl;
        }
      
    } 
	
	cout << endl;
    cout << "LA CARGA DE LA LISTA FUE EXITOSA.." << endl;
    cout << endl;

    cout << "  INFORME DE LA ESTRUCTURA LISTA:" << endl;
    cout << "  ==============================" << endl;
    cout << endl;
    
    while ( lista != NULL ){
        sacar_nodo( lista, censo );

        mostrar_nombre( censo.nombre );
        cout << "  ...  " << censo.edad << "  ...  " << censo.dni << endl;
    }

    cout << endl;
    cout << "        FIN DEL LISTADO..." << endl;

    
      
	return 0;
}

// FUNCIÓN PARA INSERTAR NODOS ORDENADOS y SIN REPETICIÓN

void insertar_ordenado_sR( t_nodo* &lista, t_censo cen, t_nodo* &rf, bool &test ){
    rf = lista;
    t_nodo* aux_2;

    test = true;

    while ( ( rf != NULL ) && ( rf -> cen.dni < cen.dni ) ){
        aux_2 = rf;
        rf = rf -> sgte;
    }

    if ( ( rf == NULL ) || ( ( rf != NULL ) && ( rf -> cen.dni > cen.dni ) ) ){
        t_nodo* nuevo_nodo = new t_nodo();

        if ( lista == rf ){
            lista = nuevo_nodo;
        }else{
            aux_2 -> sgte =  nuevo_nodo;
        }

        nuevo_nodo -> sgte = rf;
        rf = nuevo_nodo;
        test = false;
    }

    return;
}

