#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definicion del TIPO DE DATO del Árbol Binario
typedef char item;
const item indefinido = '!';

//Definicion del NODO
struct nodo {
	item raiz;
	struct nodo *derecho;
	struct nodo *izquierdo;
};
typedef struct nodo* AB;


//PROTOTIPO DE LAS OPERACIONES de Arbol Binario

AB ABVacio();
AB armarAB(AB, item, AB);
bool esABvacio(AB );
AB Izquierdo(AB );
item Raiz(AB );
AB Derecho(AB );
bool pertenece(AB , item );
//
bool esHoja(AB );
void mostrarEnorden(AB );
void mostrarPreorden(AB );
void mostrarPostorden(AB );
AB borrarAB(AB );
void liberarAB(AB );
//
int numeroHojas(AB );

// IMPLEMENTACIÓN ---------------

AB ABVacio() 
{
	return NULL;
}
AB armarAB(AB izq, item r, AB der)
{
	struct nodo* nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->raiz = r;
	nuevo->izquierdo = izq;
	nuevo->derecho = der;
	return nuevo;
}
bool esABvacio(AB T)
{
	return T == NULL;
}
AB Izquierdo(AB T) 
{
	return T->izquierdo;
}
item Raiz(AB T)
{
	return T->raiz;
}
AB Derecho(AB T)
{
	return T->derecho;
}
bool pertenece(AB T, item x)
{
	if(T == NULL) {
		return false;
	} else {
		return T->raiz == x || pertenece(T->derecho, x) || pertenece(T->izquierdo, x); 
	}
}
bool esHoja(AB T)
{
	return T->derecho == NULL && T->izquierdo == NULL;
}
void mostrarEnorden(AB T)
{
	if(T != NULL) {
		mostrarEnorden(T->izquierdo);
		printf("%c", T->raiz);
		mostrarEnorden(T->derecho);
	}
}
void mostrarPreorden(AB T)
{
	if(T != NULL) {
		printf("%c", T->raiz);
		mostrarPreorden(T->izquierdo);
		mostrarPreorden(T->derecho);
	}
}
void mostrarPostorden(AB T)
{
	if(T != NULL) {
		mostrarPostorden(T->izquierdo);
		mostrarPostorden(T->derecho);
		printf("%c", T->raiz);
	}
}
void liberarAB(AB T)
{
	liberarAB(T->izquierdo);
	liberarAB(T->derecho);
	free(T);
}
int numeroHojas(AB T)
{
	if(esABvacio(T)) {
		return 0;
	} else {
		if(esHoja(T)) {
			return 1;
		} else {
			return numeroHojas(Izquierdo(T)) + numeroHojas(Derecho(T));
		}
	}
}