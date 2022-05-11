#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/* 1. Escriba una tipificación adecuada que 
defina LISTA como una lista enlazada: */

typedef int item;

struct Nodo {
    item dato;
    struct Nodo* siguiente;
};
typedef struct Nodo* Lista;

/* 2. Escriba las siguientes funciones básicas de lista enlazada: */

/* a) crearLista: crea una lista vacía. */
Lista crearLista();

/* b) esListaVacia: booleana, determina si la lista está vacía. */
bool esListaVacia(Lista L);

/* c) mostrar: muestra por pantalla el contenido de los nodos de la lista. */
void mostrar(Lista L);

/* d) primerElemento: retorna el primer elemento de la lista. */
item primerElemento(Lista L);

/* e) insertar: inserta un nodo al comienzo de la lista. */
Lista insertar(Lista L, item x);

/* f) borrar: borra el nodo del comienzo de la lista. */
Lista borrar(Lista L);

/* g) longitud: cuenta la cantidad de nodos que tiene una lista. */
int longitud(Lista L);

/* h) pertenece: booleana, determina si un dato pertenece a la lista. */
bool pertenece(Lista L, item x);

/* i) borrarK: borra todos los nodos cuyo valor sea igual a un elemento dado. */
Lista borrarK(Lista L, item k);

/* 3. Como usuario de la lista enlazada implemente una función booleana estaContenida que, dadas dos
listas enlazadas de números enteros, retorne verdadero si los elementos de la primera lista se
encuentran presentes en la segunda, caso contrario retorna falso. */
bool estaContenida(Lista *L1, Lista L2);

int main()
{
    Lista L, L0;

    L = crearLista();
    L = insertar(L, 12);
    L = insertar(L, 12);
    L = insertar(L, 5);
    L = insertar(L, 29);
    L = insertar(L, 12);
    L = insertar(L, 30);
    L = insertar(L, 12);
    L = insertar(L, 12);
    mostrar(L);

    L0 = crearLista();
    L0 = insertar(L0, 9);
    L0 = insertar(L0, 33);
    mostrar(L0);

    if(estaContenida(&L0, L)){
        printf("La lista está contenida.\n");
    } else {
        printf("La lista no está contenida.\n");
    }

    mostrar(L0);

    return 0;
}

Lista crearLista()
{
    return NULL;
}

Lista insertar(Lista L, item x)
{
    struct Nodo *nuevo;

    nuevo = (struct Nodo*)malloc(sizeof(nuevo));
    nuevo->dato = x;
    nuevo->siguiente = L;
    L = nuevo;

    return L;
}

bool esListaVacia(Lista L)
{
    if (L == NULL)
        return true;
    else
        return false;
}

void mostrar(Lista L)
{
    printf("H-->");
    while (!esListaVacia(L)) {
        printf("[%d]-->", L -> dato);
        L = L->siguiente;
    }
    printf("null\n");
}

item primerElemento(Lista L)
{
    if (esListaVacia(L)) {
        printf("La lista está vacía.\n");
        // return 0; //--> CONSULTA: el programa se detiene cuando quiero imprimir null?? 
    }
    return L->dato;
}

Lista borrar(Lista L)
{
    struct Nodo* aux;

    if(!esListaVacia(L)) {
        aux = L;
        L = L->siguiente;
        free(aux);
    }
    return L;
}

int longitud(Lista L)
{
    int cont = 0;

    while (!esListaVacia(L)) {
        cont++;
        L = L->siguiente;
    }
    return cont;
}

bool pertenece(Lista L, item x)
{
    while (!esListaVacia(L)) {
        if (x == L->dato) {
            return true;            
        }
        L = L->siguiente;
    }
    return false;
}

Lista borrarK (Lista L, item k)
{
    struct Nodo* temporal;
    struct Nodo* anterior;

    //H-->null
    if(L == NULL)
        return NULL;

    //H-->[k]-->[k]-->[noK]-->null
    while (L != NULL && L->dato == k) {
        L = borrar(L);
    }

    //H-->null
    if(L == NULL)
        return NULL;

    //H-->[noK]-->[K]-->null
    anterior = L;
    temporal = L->siguiente;

    while (temporal != NULL) {
        
        if(temporal->dato == k) {
            anterior->siguiente = temporal->siguiente;
            free(temporal);
            temporal = anterior->siguiente;
        } else {
            anterior = anterior->siguiente;
            temporal = temporal->siguiente;
        }
    }
    return L;
}

bool estaContenida(Lista *L1, Lista L2)
{
    if(esListaVacia(*L1) || esListaVacia(L2)) {
        return false;
    }
    //suponiendo L1<L2
    while (!esListaVacia(*L1)) {
        if( pertenece(L2, primerElemento(*L1)) ) {
            *L1 = borrar(*L1);
        } else {
            return false;
        }
    }
    return true;
}

/*  Correcciones: si se pasa el argumento L1 (por valor y no por ref)
    entonces si se libera la memoria L1 queda apuntando a memoria no asignada(?) */

