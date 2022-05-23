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


//PROTOTIPO DE LAS OPERACIONES de la LC

AB ABVacio();
AB armarAB(AB, item, AB);
bool esABVacio(AB );
AB izquierdo(AB );
item raizAB(AB );
AB derecho(AB );
bool pertenece(AB , item );
//
bool esHoja(AB );
void mostrarPost(AB );
AB borrarAB(AB );
void liberarAB(AB );
// int longitud(LC );
// //
// int ContarK(LC *, item);
// int ContarK2(LC , item, size_t);

// //IMPLEMENTACION

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
bool esABVacio(AB T)
{
	return T == NULL;
}
AB izquierdo(AB T) 
{
	return T->izquierdo;
}
item raizAB(AB T)
{
	return T->raiz;
}
AB derecho(AB T)
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
void mostrarPost(AB T)
{
	if(T != NULL) {
		if(esHoja(T)) {
			
		} else {
			if(T->izquierdo != NULL) {
				mostrarPost(T->izquierdo);
			} 
			if(T->derecho != NULL) {
				mostrarPost(T->derecho);
			}
		}
		printf("%c ", T->raiz);
	} else {
		printf("T->NULL\n");
	}
}
AB borrarAB(AB T)
{
	free(T);
	return NULL;
}
void liberarAB(AB T)
{
	if(T != NULL) {
		if(esHoja(T)) {
			T = borrarAB(T);
		} else {
			liberarAB(T->izquierdo);
			liberarAB(T->derecho);
		}
	}
}
// LC LCBorrar(LC lc) 
// {
// 	struct nodo *aux;
// 	if(!esLCVacia(lc)) {
// 		aux = lc.cabecera->siguiente;
// 		if(lc.cabecera->siguiente == lc.cabecera)
// 			lc.cabecera = NULL;
// 		else {
// 			lc.cabecera->siguiente = aux->siguiente;
// 		}
// 		free(aux);
// 		lc.altura--;
// 	}
// 	return lc;
// }

// int longitud(LC lc) {
// 	return lc.altura;
// }

