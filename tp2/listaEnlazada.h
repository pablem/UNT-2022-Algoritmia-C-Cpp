#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definicion del TIPO DE DATO de la Lista
typedef int item;
const item indefinido = 9999;

//Definicion del nodo de la Lista
struct nodo {
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
Lista borrarK(Lista L, item k); //tp1
bool estaContenida(Lista *L1, Lista L2); //tp1

/*2) Calcule el costo de las operaciones de la lista enlazada implementadas en el Práctico 1,
incluida la función del punto 3.*/

Lista crearListaVacia(){
	return NULL;	//--------------->O(1)
}

int esListaVacia(Lista L){
	return L==NULL;		//(condicional)--------->O(1) |
}						//---------------------->O(1) | ----> O(1)

Lista insertar(Lista L, item x){
	struct nodo* nuevo;	//------>O(1)							|
	nuevo = (struct nodo*) malloc(sizeof( struct nodo));//O(1)	|
	nuevo->dato = x;	//------>O(1)							|
	nuevo->siguiente = L;//----->O(1)							| ---> O(1)
	L=nuevo;			//------>O(1)							|
	return L;			//------>O(1)							|
}

void mostrar(Lista L){ 	//n = número de elementos de la lista	|
	printf("L --> ");	//------>O(1)							|
	while(L!=NULL){ // n iteraciones			|				|
		printf("%d -> ", L->dato);	//--->O(1)	| -----> O(n)	| ---> O(n)
		L = L->siguiente;			//--->O(1)	|				|
	}											
	printf("NULL\n");	//------>O(1)							|
}

Lista borrar(Lista L){		//------>O(1) |
	struct nodo*aux;		//------>O(1) |
	if(L!=NULL){			//------>O(1) |
		aux = L;			//------>O(1) | ---->O(1)
		L = L->siguiente;	//------>O(1) |
		free(aux);			//------> ?		
	}
	return L;	//------>O(1)
}

int longitud(Lista L){ //n = número de elementos de la lista
	int cont=0;	//------>O(1)								|
	while(L!=NULL){ // n iteraciones		|				|
		cont++;				//------>O(1)	| --->O(n)		| --->O(n)
		L = L->siguiente;	//------>O(1)	|				|
	}
	return cont; //------>O(1)								|
}

int pertenece(Lista L, item X){ //n = número de elementos de la lista			|
	while(L!=NULL && L->dato!=X){ 	// peor caso: n iteraciones |				|
		L = L->siguiente;			//------>O(1)				| ---> O(n)		| --->O(n)
	}
	return L!=NULL; //------>O(1)												|
}

item primerElemento(Lista L){	//							|
	if(L==NULL){				//------>O(1)	|			|
		return indefinido;		//------>O(1)	| --->O(1)	| --->O(1)
	}							//							|
	else						//							|
		return L->dato;			//------>O(1)				|
}

Lista borrarK(Lista L, item k) {
    struct nodo* temporal;		//------>O(1)													|
    struct nodo* anterior;		//------>O(1)													|
    if(L == NULL)				//------>O(1)													|
        return NULL;			//------>O(1)													|
    while (L != NULL && L->dato == k) { // peor caso: n it.						|				|
        L = borrar(L);			//------>O(1)									| ---> O(n)		|
    }							//																|
    if(L == NULL)				//------>O(1)													|
        return NULL;			//------>O(1)													|
    anterior = L;				//------>O(1)													|
    temporal = L->siguiente;	//------>O(1)													| ---->O(n)
    while (temporal != NULL) { // peor caso: n it.								|				|
        if(temporal->dato == k) {	//------>O(1)								|				|
            anterior->siguiente = temporal->siguiente; 	//O(1)	|				|				|
            free(temporal);								//O(1)	| ---> O(1)		|				|
            temporal = anterior->siguiente;				//O(1)	|				| --->O(n)		|
        } else {										//						|				|
            anterior = anterior->siguiente;				//O(1)	|				|				|
            temporal = temporal->siguiente;				//O(1)	| ---> O(1)		|				|
        }												//						|				|
    }													//						|				|
    return L;						//------>O(1)												|
}

bool estaContenida(Lista *L1, Lista L2) {	// n1, n2 cantidad de elem. en respectivas listas
    if(esListaVacia(*L1) || esListaVacia(L2))		//------>O(1)		|
        return false;								//------>O(1)		|
    while (!esListaVacia(*L1)) {	//O(1); peor caso n1 it.		|	|
        if( pertenece(L2, primerElemento(*L1)) ) {	//------>O(n2)	|	|
            *L1 = borrar(*L1);						//------>O(1)	|	|
        } else {									//				|	| --->O(n1*n2)
            return false;							//------>O(1)	|	|
        }											//				|	|
    }												//				|	|
    return true;									//------>O(1)	|	|
}													//					|
