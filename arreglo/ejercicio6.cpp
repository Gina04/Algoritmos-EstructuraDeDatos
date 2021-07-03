#include <iostream>
using namespace std;

int main() {

    int nroSocio;
	int codigoDeporte[20]={0};	
	int  j= 0, i=0;
	int codigo, mayorInscriptos=0, codmayor;
	
	
    cout<< "Ingrese Nro de socio:";
    cin>>nroSocio;
     
    while(nroSocio!= 0){
    	 cout<< "Ingrese codigo deporte del (1..20)";
	     cin>>codigo;
        
        for(j=0;j<20; j++){
	    	if(j == codigo){
			codigoDeporte[j]++;
			
			//cout<<"el indice del vector: " << codigoDeporte[j]<< endl;- prueba
		    }
	    } 
	    
	    cout<< "Ingrese Nro de socio:";
        cin>>nroSocio;
       
	}
		
	
	for(i=0;i<20;i++){

        cout<<"la cantidad de inscriptos en el deporte "<<i<<" son: "<<codigoDeporte[i]<< endl;
        cout<< "\n";

        if(codigoDeporte[i]>mayorInscriptos){
            mayorInscriptos=codigoDeporte[i];
            codmayor=i;
        }
    }
    cout<< "\n";
    
    cout<<"El deporte con mas cantidad de inscriptos es: "<<codmayor<<endl;
	
	return 0;
}
