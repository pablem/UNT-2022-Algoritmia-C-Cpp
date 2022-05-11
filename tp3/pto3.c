/** DISEÑO DE ALGORITMOS RECURSIVOS **/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

# define N 3

/** 3. Teniendo en cuenta la lista enlazada de números enteros implementada en el TP N° 1:
a. Diseñe una versión recursiva de la operación longitud.
b. Diseñe una función recursiva que determine si dos listas son iguales. **/

//Definicion del TIPO DE DATO de la Lista
typedef int item;
const item indefinido = 9999;

//Definicion del NODO de la Lista
struct nodo{
	item dato;
	struct nodo *siguiente;
};

//Definicion de la CABECERA de la Lista
typedef struct nodo* Lista;


//PROTOTIPO DE LAS OPERACIONES de la Lista Enlazada
int longitud(Lista );
bool sonIguales(Lista ,Lista );

Lista cargarLista(Lista, item );
Lista liberarLista(Lista );
Lista borrarNodo(Lista );

int main()
{
    Lista L1=NULL, L2=NULL;
    
    for (int i = 0; i < N; i++) {
        L1 = cargarLista(L1, i+3);
        L2 = cargarLista(L2, i);
    }
    
    printf("\nEj 1)\n");
    printf("Longitud: %d\n", longitud(L1));

    printf("\nEj 2)\n");
    if (sonIguales(L1, L2))
        printf("Son Iguales!\n");
    else 
        printf("No son iguales :(\n");

    L1 = liberarLista(L1);
    L2 = liberarLista(L2);

    return 0;
}

//IMPLEMENTACION

Lista cargarLista(Lista L, item x)
{
    struct nodo* nuevo;
    nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato = x;
    nuevo->siguiente = L;
    L = nuevo;

    return L;
}

Lista liberarLista(Lista L)
{
    struct nodo* aux;
    while (L != NULL) {
        aux = L;
        L = L->siguiente;
        free(aux);
    }
    return L;
}

int longitud(Lista L)
{
    if (L == NULL) {
        return 0;
    } else {
        L = L->siguiente;
        return 1 + longitud(L);
    }
}

bool sonIguales(Lista L1, Lista L2)
{
    if (!L1 && !L2) {
        return true;
    } else {
        if (!L1 || !L2) {
            return false;
        } else {
            return L1->dato == L2->dato && sonIguales(L1->siguiente, L2->siguiente);
        }
    }
}

