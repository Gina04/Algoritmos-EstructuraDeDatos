/*Se ingresa una edad, mostrar por pantalla alguna de las siguientes leyendas:
� �menor� si la edad es menor o igual a 12
� �cadete� si la edad esta comprendida entre 13 y 18
� �juvenil� si la edad es mayor que 18 y no supera los 26
� �mayor� en el caso que no cumpla ninguna de las condiciones anteriores
*/
#include <iostream>

using namespace std;

int main()
{
    int edad;

    cout << "Edad: " << endl;
    cin>>edad;

    if(edad<= 12){
        cout<<"Menor";
    }else if(13<edad <18){

        cout<<"Cadete";

    }else if(18 < edad < 26){
        cout<< "Juvenil";
    }else{
       cout<<"Mayor";

    }

    return 0;
}
