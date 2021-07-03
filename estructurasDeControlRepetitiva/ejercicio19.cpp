#include <iostream>
using namespace std; 
//Prototipo 
void CargoCelular(float,float,float,float, float&, float&);

int main() {
	float abono, minAbono, cargoExcedente, minUtilizados, minExcedidos,montoTotal;
	cout<< "Ingrese Abono: ";
	cin>> abono;
	
	cout<< "Minutos que incluye el abono: "<<endl;
	cin>>minAbono;
	
	cout<< "Ingrese el cargo por cada minuto excedente : "<<endl;
	cin>> cargoExcedente; 
	
	cout<<"Ingrese minutos utilizados por el cliente: "<<endl;
	cin>> minUtilizados;
	
	CargoCelular(abono, minAbono, cargoExcedente, minUtilizados, minExcedidos,montoTotal);
	
    cout<< " Los minutos excedidos: "<< minExcedidos<<endl;
	cout<<"El monto total: " <<  montoTotal ;
	return 0;
}

//Desarrollo del procedimiento CargoCelular()

void CargoCelular(float abono,float minAbono, float cargoExcedente,
 float minUtilizados, float & minExcedidos, float & montoTotal ){
 	int iva;
    //minutos excedidos 
	 minUtilizados = minAbono - minUtilizados;
	
    //verifico si el usuario se excedio en minutos;
	if(minUtilizados< 0){
	   	minExcedidos = minUtilizados * (-1);
	}	
	//falta el IVA
	iva = abono * 0.21; 
	montoTotal = abono + (minExcedidos*cargoExcedente) + iva;
	
	cout<<"El monto total a pagar :" << montoTotal;
	
	return;
			 	
}

