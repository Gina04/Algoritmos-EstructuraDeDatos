#include <iostream>
using namespace std;


int main() {
	
	int tiradas[50],valor1, valor2,i; 
	int v2=0,v3=0,v4=0,v5=0,v6=0,v7=0,v8=0,v9=0,v10=0,v11=0,v12=0;

	
	for(i=0; i<5; i++){
		
	cout<<"Tirada1:";
	cin>> valor1;
	
	cout<< "Tirada2:";
	cin>> valor2;
	tiradas[i] =valor1 + valor2;
	
    switch(tiradas[i]){
		case 2: v2++; 
		break;
		case 3: v3++; 
		break;
		case 4: v4++; 
		break;
		case 5: v5++; 
		break;
		case 6: v6++; 
		break;
		case 7: v7++; 
		break;
		case 8: v8++; 
		break;
		case 9: v9++; 
		break;
		case 10:v10++; 
		break;
		case 11:v11++; 
		break;
		case 12:v12++; 
		break;
		
    	}
	
	
	}
	
	
	cout<< "El 2 salio:" << v2++ <<endl;
	cout<< "El 3 salio:" << v3++ <<endl;
	cout<< "El 4 salio:" << v4++ <<endl;
	cout<< "El 5 salio:" << v5++ <<endl;
	cout<< "El 6 salio:" << v6++ <<endl;
	cout<< "El 7 salio:" << v7++ <<endl;
	cout<< "El 8 salio:" << v8++ <<endl;
	cout<< "El 9 salio:" << v9++ <<endl;
	cout<< "El 10 salio:"<< v10++ <<endl;
	cout<< "El 11 salio:"<< v11++ <<endl;
	cout<< "El 12 salio:"<< v12++ <<endl;
	
	
	return 0;
}
