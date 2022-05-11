#include<stdio.h>
#include<stdlib.h>

typedef int item;
const item indefinido=9999;

struct nodo{
                    item dato;
                    struct nodo *siguiente;
};

typedef struct {
                   struct nodo *cabecera;
                   int altura;
}Pila;


int sumarImpares(Pila P);

int main(int argc, char const *argv[])
{

    printf("%d", 7%2);
    
    return 0;
}

int sumarImpares(Pila P) {

    int cont = 0;

    while (P.cabecera != NULL)
    {
        if(P.cabecera->dato %2 == 0) {
            cont += P.cabecera->dato;
        }
        P.cabecera = P.cabecera->siguiente;
    }
    return cont;
}
