#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definicion del TIPO DE DATO de la FILA
typedef int item;
const item indefinido = -9999;

//Definicion del NODO de la FILA
struct nodo {
	item dato;
	struct nodo *siguiente;
};

//Definicion de la CABECERA de la FILA
typedef struct {
	int altura;
	struct nodo *frente;
	struct nodo *final;
} FILA;


//PROTOTIPO DE LAS OPERACIONES de la FILA

FILA filaVacia();
bool esFilaVacia(FILA );
item frente(FILA );
FILA enfila(FILA , item );
FILA defila(FILA );
//
void mostrar(FILA );
int longitud(FILA );
bool pertenece(FILA F, item X);
bool igualF(FILA F1, FILA F2);
//
// FILA concat(FILA F1, FILA F2);
// FILA invertir(FILA F);
//
FILA mezclar(FILA *, FILA *);
FILA mezclar2(FILA *, FILA *, FILA);
//
item sumarPositivos(FILA *F);

//IMPLEMENTACION

FILA filaVacia() 
{
	FILA F;
	F.altura = 0;
	F.frente = NULL;
	F.final = NULL;
	return F;
}

bool esFilaVacia(FILA F)
{
	return F.frente == NULL && F.final == NULL;
	// return F.frente == NULL;
}

item frente(FILA F)
{
	if (esFilaVacia(F))
		return indefinido;
	else 
		return F.frente->dato;
}

FILA enfila(FILA F, item x)
{
	struct nodo* nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->dato = x;
	nuevo->siguiente = NULL;
	if(esFilaVacia(F)) {
		F.frente = nuevo;
	} else {
		F.final->siguiente = nuevo;
	}
	F.final = nuevo;
	F.altura++;
	return F;
}

FILA defila(FILA F) 
{
	struct nodo*aux;
	if(!esFilaVacia(F)) {
		if(F.frente->siguiente == NULL)
			F.final = NULL;
		aux = F.frente;
		F.frente = F.frente->siguiente;
		F.altura--;
		free(aux);
	}
	return F;
}

void mostrar(FILA F) 
{
	printf("Frente--> ");
	while(F.frente != NULL) {
		printf("%d -> ", F.frente->dato);
		F.frente = F.frente->siguiente;
	}
	printf("NULL\n");
}

int longitud(FILA F) {
	return F.altura;
}

bool pertenece(FILA F, item X) 
{
	while(F.frente != NULL && F.frente->dato != X) {
		F.frente = F.frente->siguiente;
	}
	return F.frente != NULL;
}

bool igualF(FILA F1, FILA F2) 
{
	while(F1.frente != NULL && F2.frente != NULL && frente(F1) == frente(F2)) {
		F1.frente = F1.frente->siguiente;
		F2.frente = F2.frente->siguiente;
	}
	return F1.frente == NULL && F2.frente == NULL;
}

//función punto 4) 

FILA mezclar(FILA *F1, FILA *F2)
{
	item aux;

	if(esFilaVacia(*F1) && esFilaVacia(*F2)) { 
		return filaVacia();
	} else {
		if(esFilaVacia(*F1) || esFilaVacia(*F2)) {
			if(esFilaVacia(*F1)) {
				aux = frente(*F2);
				*F2 = defila(*F2);
			} else {
				aux = frente(*F1);
				*F1 = defila(*F1);
			}
		} else {
			if(frente(*F1) < frente(*F2)) {
				aux = frente(*F1);
				*F1 = defila(*F1);
			} else {
				aux = frente(*F2);
				*F2 = defila(*F2);
			}
		}
		return enfila(mezclar(F1,F2), aux);
	}
}

FILA mezclar2(FILA *F1, FILA *F2, FILA F3) //REACER!
{
	item aux;

	if(esFilaVacia(*F1) && esFilaVacia(*F2)) { 
		return F3;
	} else {
		if(esFilaVacia(*F1) || esFilaVacia(*F2)) {
			if(esFilaVacia(*F1)) {
				aux = frente(*F2);
				*F2 = defila(*F2);
				F3 = enfila(mezclar2(F1, F2, F3), aux);
			} else {
				aux = frente(*F1);
				*F1 = defila(*F1);
				F3 = enfila(mezclar2(F1, F2, F3), aux);
			}
		} else {
			if(frente(*F1) >= frente(*F2)) {
				aux = frente(*F1);
				*F1 = defila(*F1);
				F3 = enfila(mezclar2(F1, F2, F3), aux);
			} else {
				aux = frente(*F2);
				*F2 = defila(*F2);
				F3 = enfila(mezclar2(F1, F2, F3), aux);
			}
		}
	}
}

item sumarPositivos(FILA *F)
{
    item suma = 0;
    while(!esFilaVacia(*F)) {
        if(frente(*F) > 0) {
            suma += frente(*F);
        }
        *F = defila(*F);
    }
    return suma;
}