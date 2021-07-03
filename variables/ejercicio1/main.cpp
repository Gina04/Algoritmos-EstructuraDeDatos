//Dado dos valores enteros A y B, informar la suma, la resta y el producto.
#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cout << "Ingrese dos valores:" << endl;
    cin>>a>>b;

    int suma = a+b;
    int resta = a-b;
    int producto = a*b;

    cout<<"La suma de a y b da: "<< suma <<endl;
    cout<<"La resta de a y b da: "<< resta << endl;
    cout<< "El producto a y b da: "<< producto <<endl;



    return 0;
}
