#include <iostream>
using namespace std; 
//prototipos 
string Tendencia(int, int);

int main() {
	
	int a, b; 	
	cout<< "Ingrese dos valores:";
	cin>> a >> b;
	
	string tendencia = Tendencia(a,b);
	
	cout << "las tendencias segun los valores ingresados : " << tendencia;
	
	return 0;
}

//defino la funcion 

string Tendencia(int a, int b){
	
	if(b-a < 0 ){
		return "decreciente";
		
	} else if(b-a < (a * 0.05)){
		return "leve ascenso";
		
	}else if(b-a < (a* 0.02)){
		return "estable";
		
	}else{
		return "en ascenso";
	}

}
