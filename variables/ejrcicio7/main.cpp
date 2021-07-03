/*
Calcular la velocidad (metros/segundo) de los participantes de una carrera de 1500mts
dado el tiempo en segundos en recorrerla y determinar el nombre del mas veloz. Y si el
tiempo fuera en minutos + segundos?

*/
#include <iostream>
#include <string.h>
#include<conio.h>

using namespace std;
//Prototipo
int calcularVelocidad(int tiempo){
    int velocidad = 1500/tiempo;
    return velocidad;

}

struct Participante{
    char nombre[30];
    int tiempo;

}corredores[1000];

int main()
{
    int cantidad, rapido=0, lento=0, pos;
    //struct Participante corredores[cantidad];

    //cargo el tamanio del array
    cout<< "Ingrese la cantidad de correrdores que participaron en la carrera: ";
    cin>>cantidad;

    //cargo el array de struct
    for(int i=0; i< cantidad; i++){
    fflush(stdin);
    cout << "Digite el nombre:" << endl;
    cin.getline(corredores[i].nombre,30,'\n');

    cout<<"Digite el tiempo: "<<endl;
    cin>>corredores[i].tiempo;

}
   //verifico el corredor mas rapido
    for(int i=0; i<cantidad; i++){

    if(calcularVelocidad(corredores[i].tiempo)> rapido){
        rapido= corredores[i].tiempo;
        pos=i;
    }else{
        lento=corredores[i+1].tiempo;

    }

    }
    cout<<"El corredor mas veloz se llama:"<< corredores[pos].nombre<<endl;





    getch();
    return 0;
}
