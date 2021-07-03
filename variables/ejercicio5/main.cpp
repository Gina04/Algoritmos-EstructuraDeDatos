//Dado un triángulo representado por sus lados L1, L2, L3, determinar e imprimir una
//leyenda según sea: equilátero, isósceles o escalenos.
#include <iostream>

using namespace std;

int main()
{
    int l1,l2,l3;

    cout << "Ingrese los lados del triangulo" << endl;
    cin>>l1>>l2>>l3;

    if(l1==l2==l3){
        cout<< "Este es un Triangulo Equilatero (3 lados iguales)";
    }else if(l1 == l2 != l3){
        cout<<"Este es un Triangulo Isosceles(2 lados iguales y un lados distinto)";

    }else{
      cout<< "Este es un Triangulo Escaleno(3 lados distintos)";

    }
    return 0;
}
