/*
Dado tres valores determinar e imprimir una leyenda según sea: “Forman triangulo” o
“No forman triangulo”.

*/
#include <iostream>

using namespace std;

int main()
{
    int a,b,c;

    cout << "Ingrese los 3 lados del triangulo" << endl;
    cin>>a>>b>>c;

    cout<< "Si uno de los lados mide mas que la suma de los otros dos,entonces el triangulo no podra dibujarse.\n"<<endl;
    if(a+b>c ||a+c>b ||c+b>a ){
        cout<< "No forman triangulo.";
    }else{
      cout<< "Forman triangulo.";

    }
    return 0;
}
