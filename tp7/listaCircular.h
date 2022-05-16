#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definicion del TIPO DE DATO de la LC --> LISTA CIRCULAR
typedef int item;
const item indefinido = -9999;

//Definicion del NODO de la LC
struct nodo {
	item dato;
	struct nodo *siguiente;
};

//Definicion de la CABECERA de la LC
typedef struct {
	int altura;
	struct nodo *cabecera;
} LC;


//PROTOTIPO DE LAS OPERACIONES de la LC

LC LCVacia();
bool esLCVacia(LC );
item LCValor(LC );
LC LCInsertar(LC , item );
LC LCBorrar(LC );
LC LCRotar(LC );
//
void mostrar(LC );
int longitud(LC );
//
int ContarK(LC *, item);
int ContarK2(LC , item, size_t);

//IMPLEMENTACION

LC LCVacia() 
{
	LC lc;
	lc.altura = 0;
	lc.cabecera = NULL;
	return lc;
}

bool esLCVacia(LC lc)
{
	return lc.cabecera == NULL;
}

item LCValor(LC lc)
{
	if (esLCVacia(lc))
		return indefinido;
	else 
		return (lc.cabecera->siguiente)->dato;
}

LC LCInsertar(LC lc, item x)
{
	struct nodo* nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->dato = x;
	if(esLCVacia(lc)) {
		nuevo->siguiente = nuevo;
		lc.cabecera = nuevo;
	} else {
		nuevo->siguiente = lc.cabecera->siguiente;
		lc.cabecera->siguiente = nuevo;
	}
	lc.altura++;
	return lc;
}

LC LCBorrar(LC lc) 
{
	struct nodo *aux;
	aux = lc.cabecera->siguiente;
	if(!esLCVacia(lc)) {
		if(lc.cabecera->siguiente == lc.cabecera)
			lc.cabecera = NULL;
		else {
			lc.cabecera->siguiente = aux->siguiente;
		}
		free(aux);
		lc.altura--;
	}
	return lc;
}

void mostrar(LC lc) 
{
	printf("Ventana--> ");
	if(!esLCVacia(lc)) {
		lc.cabecera = lc.cabecera->siguiente;
		for (size_t i = 0; i < lc.altura; i++)
		{
			printf("%d -> ", lc.cabecera->dato);
			lc.cabecera = lc.cabecera->siguiente;
		}
	printf("Ventana");
	}
	printf("\n");
}

int longitud(LC lc) {
	return lc.altura;
}

LC LCRotar(LC lc) {
	lc.cabecera = lc.cabecera->siguiente;
	return lc;
}

//Función como usuario del ADT LC
int ContarK(LC *lc, item k) {
	if (esLCVacia(*lc)) {
		return 0;
	} else {
		int suma = 0;
		item aux = LCValor(*lc);
		*lc = LCBorrar(*lc);
		if (aux == k) {
			suma = 1 + ContarK(lc,k);
		} else {
			suma = ContarK(lc,k);
		}
		*lc = LCInsertar(*lc,aux);
		return suma;
	}
}

int ContarK2(LC lc, item k, size_t n)
{	
	if (n == 0) {
		return 0;
	} else {
		if (LCValor(lc)==k) {
			return 1 + ContarK2(LCRotar(lc),k,n-1);
		} else {
			return ContarK2(LCRotar(lc),k,n-1);
		}
	}
}
