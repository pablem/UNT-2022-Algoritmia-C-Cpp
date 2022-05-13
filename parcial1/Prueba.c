/* Alumno: Juarez Palmieri */
#include<stdio.h>
#include<stdlib.h>
#include "AEDI.H"

int main(){

    Pila P = PilaVacia();

    printf("\nMostrar pila vacía:");
    MostrarPila(P);

    P = Push(P, 50);
    printf("\na) push del elemento 50:\n");
    MostrarPila(P);

    P = Pop(P);
    printf("\nb) Quito el último elemento ingresado: \n");
    MostrarPila(P);

    P = Pop(P);
    printf("\nb) Quito el último elemento ingresado: \n");
    MostrarPila(P);

    P = Push(P, 40);
    P = Push(P, 33);
    P = Push(P, 22);
    P = Push(P, 11);
    printf("\na) push de los elementos 33, 22, 11, 40:\n");
    MostrarPila(P);

    printf("\nd) Pruebo si está el elemento 22:\n");
    if(Pertenece(P, 22)) 
        printf("\nSi pertenece!\n");
    else 
        printf("\nNo pertenece :(\n");

    printf("\nd) Pruebo si está el elemento 5:\n");
    if(Pertenece(P, 5)) 
        printf("\nSi pertenece!\n");
    else 
        printf("\nNo pertenece :(\n");

    P = PushFondo(P, 7);
    printf("\nc) PushFondo el elemento 7:\n");
    MostrarPila(P);

    P = PopN(P, 3);
    printf("\n2.- Borro los últimos 3 elementos:\n");
    MostrarPila(P);

    return 0;
}
