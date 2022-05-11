/* APELLIDO Y NOMBRE: 
 * Lista enlazada de n�meros enteros
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definicion del TIPO DE DATO de la PILA
typedef int item;
const item indefinido = 9999;

//Definicion del NODO de la PILA
struct nodo{
	item dato;
	struct nodo *siguiente;
};

//Definicion de la CABECERA de la PILA
typedef struct {
	int altura;
	struct nodo *cabecera;	
} Pila;


//PROTOTIPO DE LAS OPERACIONES de la PILA
Pila pilaVacia();
bool esPilaVacia(Pila );
Pila enfila(Pila , item );
Pila defila(Pila );
item top(Pila );


void mostrar(Pila L);

int longitud(Pila L);
int pertenece(Pila L, item X);


//IMPLEMENTACION

Pila pilaVacia() {
	Pila P;
	P.altura = 0;
	P.cabecera = NULL;
	return P;
}

bool esPilaVacia(Pila P)
{
	return P.cabecera == NULL;
}

Pila enfila(Pila P, item x){
	struct nodo* nuevo;
	nuevo = (struct nodo*) malloc(sizeof( struct nodo));
	nuevo->dato = x;
	nuevo->siguiente = P.cabecera;
	P.cabecera = nuevo;
	P.altura++;
	return P;
}

Pila defila(Pila P){
	struct nodo*aux;
	if(P.cabecera != NULL){
		aux = P.cabecera;
		P.cabecera = P.cabecera->siguiente;
		P.altura--;
		free(aux);
	}
	return P;
}

item top(Pila P)
{
	if (esPilaVacia(P))
		return indefinido;
	else 
		return P.cabecera->dato;
}

// int longitud(Pila L){
// 	int cont=0;
// 	while(L!=NULL){
// 		cont++;
// 		L = L->siguiente;
// 	}
// 	return cont;
// }

// int pertenece(Pila L, item X){
// 	while(L!=NULL && L->dato!=X){
// 		L = L->siguiente;
// 	}
// 	return L!=NULL;
// }

// void mostrar(Pila L){
// 	printf("L --> ");
// 	while(L!=NULL){
// 		printf("%d -> ", L->dato);
// 		L = L->siguiente;
// 	}
// 	printf("NULL\n");
// }

// int contarMayoresQue(Pila L, item k) {

// 	int cont = 0;

// 	while(L != NULL) { //while(esListaVacia(L))

// 		if(L->dato > k) {
// 			cont++;
// 		}
// 		L = L->siguiente;
// 	}
// 	return cont;
// }
