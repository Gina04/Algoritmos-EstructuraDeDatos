#include <iostream>
using namespace std;

int main() {
	int n, sumatoria=0, total=0, elemento;
	cout<< "Ingrese numero de fila y columna: ";
	cin>>n;
	
	int promedio, maximo=0,posFila , posColumna, minimoPorFila[n]={0}, maximoPorColumna[n]={0};
	int elemPositivos=0,elemNegativos=0,elemP,elemN;

	
	int mat[n][n]; //matriz
	
	
	int i, j;
	for(i=0; i<n;i++){ //fila
		for(j=0;j<n;j++){ //columna
			cout<< "Valor: ";
			cin>>mat[i][j];	
			sumatoria+=mat[i][j];	
		//d.obtenes el maximo elemento y la posicion(fila-columna)	
		if(mat[i][j]> maximo){
			maximo = mat[i][j];
			posFila = i;
			posColumna=j;
			
			}
		//e.Informar el mínimo de cada fila 	
		 if(minimoPorFila[i]==0|| mat[i][j]< minimoPorFila[i]){
		 	minimoPorFila[i] = mat[i][j];
		    }
		//e. y el máximo de cada columna    
		if(maximoPorColumna[i]==0 || mat[i][j]> maximoPorColumna[i]){
		 	maximoPorColumna[i]=mat[i][j];
		    } 
		    
		//f.diagonal principal elementos positivos
		
		if(i==j){
			elemP=mat[i][j];
			if(elemP>0){
				elemPositivos++;
			}
					
		}
		
		//f.diagonal secundaria elementos negativos i+j = n-1
		
		if(i+j==n-1){
		   elemN = mat[i][j];
		   if(elemN<0){
		   	elemNegativos++;
		     }
		    
	      }
		
		} //fin del for interno
		
	
	}// fin del for externo
	 
	 
	cout<<"Elementos de la diagonal secundaria:"<< elemNegativos<<endl;
	
    cout<<"La diagonal principal hay: " << elemPositivos<<" elementos positivos"<< endl;
	cout<<"El valor maximo es: "<< maximo<<endl;
	cout<<"Se encuentra en la posicion["<< posFila<<"]["<<posColumna<<"]"<<endl;
	
	//c.
	total = n*n;
	promedio= sumatoria / total;
	cout<< "La sumatoria de todos los elementos de la matriz: "<< sumatoria<<endl;
	cout<<"El promedio de la  matriz:"<< promedio<<endl;  
	
	cout<< "\n";
	

	//a.
	cout<<"Imprimo la matriz por fila \n";
	
	for(i=0;i<n; i++){
		for(j=0; j<n; j++){
			cout<<mat[i][j];
		}
		cout<< "\n";
	}
	//b.
	cout<<"Imprimo la matriz por columna \n";
	
	for(j=0; j<n; j++){ //columnas
		for(i=0; i<n; i++){ //filas
			cout<< mat[i][j];
		
		}
			
		cout<<"\n";
	}
	
	//e. imprimo maximos por columna y minimos por fila
	
	cout<< "Imprimo minimos por filas \n"; 
	
		for(i=0; i<n; i++){
		   cout<<"Minimo por fila:"<< minimoPorFila[i]<<"\n";
     	}
    cout<< "Imprimo maximos por columnas \n"; 	
     	
     	for(j=0; j<n; j++){
			cout<< "Maximo por columna:"<<maximoPorColumna[j]<<"\n";

	    	}

	
	
		
	
	return 0;
}


