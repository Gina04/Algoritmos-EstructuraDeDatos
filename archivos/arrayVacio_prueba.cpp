#include <iostream>
#include<cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char cadena[3]={'h', 'o', 'l'};

		
	for(int i=0; i<3; i++){
		if(cadena[i] != '\0'){
			cout<< cadena[i];
		}
	}
	return 0;
}
