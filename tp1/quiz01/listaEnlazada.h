/* APELLIDO Y NOMBRE: 
 * Lista enlazada de números enteros
 */

#include<stdio.h>
#include<stdlib.h>

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
Lista crearListaVacia();
int esListaVacia(Lista L);
Lista insertar(Lista L, item x);
void mostrar(Lista L);
Lista borrar(Lista L);
int longitud(Lista L);
int pertenece(Lista L, item X);
item primerElemento(Lista L);

int contarMayoresQue(Lista L, item k);


//IMPLEMENTACION

Lista crearListaVacia(){
	return NULL;
}

int esListaVacia(Lista L){
	return L==NULL;
}

Lista insertar(Lista L, item x){
	struct nodo* nuevo;
	nuevo = (struct nodo*) malloc(sizeof( struct nodo));
	nuevo->dato = x;
	nuevo->siguiente = L;
	L=nuevo;
	return L;
}

void mostrar(Lista L){
	printf("L --> ");
	while(L!=NULL){
		printf("%d -> ", L->dato);
		L = L->siguiente;
	}
	printf("NULL\n");
}

Lista borrar(Lista L){
	struct nodo*aux;
	if(L!=NULL){
		aux = L;
		L = L->siguiente;
		free(aux);
	}
	return L;
}

int longitud(Lista L){
	int cont=0;
	while(L!=NULL){
		cont++;
		L = L->siguiente;
	}
	return cont;
}

int pertenece(Lista L, item X){
	while(L!=NULL && L->dato!=X){
		L = L->siguiente;
	}
	return L!=NULL;
}

item primerElemento(Lista L){
	if(L==NULL){
		return indefinido;
	}
	else
		return L->dato;
}

int contarMayoresQue(Lista L, item k) {

	int cont = 0;

	while(L != NULL) { //while(esListaVacia(L))

		if(L->dato > k) {
			cont++;
		}
		L = L->siguiente;
	}
	return cont;
}
