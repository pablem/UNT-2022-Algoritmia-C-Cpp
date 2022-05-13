/* Alumno: Juarez Palmieri
 * Pila enlazada de n�meros enteros
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definicion del TIPO DE DATO de la Pila
typedef int item;
const item indefinido = 9999;

//Definicion del NODO de la Pila
struct nodo{
	item dato;
	struct nodo *siguiente;
};

//Definicion de la CABECERA de la Pila
typedef struct {
	struct nodo *cabecera;
	int altura;
} Pila;


//PROTOTIPO DE LAS OPERACIONES de la Pila
Pila PilaVacia();
int EsPilaVacia(Pila P);
item Top(Pila P);
int AlturaPila(Pila P);
void MostrarPila(Pila P);
//1.-
Pila Push(Pila P, item x);
Pila Pop(Pila P);
Pila PushFondo(Pila P, item x);
bool Pertenece(Pila P, item x);
//2.-
Pila PopN(Pila P, int n);


//IMPLEMENTACION DE LAS OPERACIONES de la Pila

Pila PilaVacia(){
	Pila P;
	P.cabecera = NULL;
	P.altura = 0;
	return P;
}

int EsPilaVacia(Pila P){
	return P.cabecera==NULL;
}

item Top(Pila P){
	if(P.cabecera==NULL){
		return indefinido;
	}
	else
		return P.cabecera->dato;
}

int AlturaPila(Pila P){
	return P.altura;
}

void MostrarPila(Pila P){
	printf("P --> ");
	while(P.cabecera!=NULL){
		printf("%d -> ", P.cabecera->dato);
		P.cabecera = P.cabecera->siguiente;
	}
	printf("NULL\n");
}

//1.-

Pila Push(Pila P, item x)
{
	struct nodo* nuevo;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo));
	nuevo->dato = x;
	nuevo->siguiente = P.cabecera;
	P.cabecera = nuevo;
	P.altura = P.altura + 1;

	return P;
}

Pila Pop(Pila P)
{
	struct nodo* aux;
	if (EsPilaVacia(P)) {
		return P;
	} else {
		aux = P.cabecera;
		P.cabecera = P.cabecera->siguiente;
		P.altura = P.altura - 1;
		free(aux);
	}
	return P;
}

// Pila PushFondo(Pila P, item x)
// {
// 	while(P.cabecera->siguiente != NULL) { //r
// 		if(EsPilaVacia(P)) {
// 			return Push(P, x);
// 		} else {
// 			P.cabecera = P.cabecera->siguiente;
// 		}
// 	}
// }

Pila PushFondo(Pila P, item x)
{
	item k;
	if(!EsPilaVacia(P)) {
		if(P.cabecera->siguiente == NULL) {
			return Push(P, x);
		} else {
			k = P.cabecera->dato;
			P.cabecera = P.cabecera->siguiente;
			return Push(PushFondo(P, k), x);
			}
	}
}

bool Pertenece(Pila P, item x)
{
	if(EsPilaVacia(P)) {
		return false;
	} else {
		P.cabecera = P.cabecera->siguiente;
		return Top(P) == x && Pertenece(P, x);
	}
}
//2.-
Pila PopN(Pila P, int n)
{
	if(EsPilaVacia(P) || n == 0 ) {
		return P;
	} else {
		return PopN(Pop(P), n-1);
	}
}
