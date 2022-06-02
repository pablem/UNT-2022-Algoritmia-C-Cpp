#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <conio.h>
#include "arbolBinario.h"

const float frecuancas[] = {
    0.45,
    0.13,
    0.12,
    0.16,
    0.09,
    0.05 };
// float frecuancas[] = { // 26 letras
//     0.110845, // A (0)
//     0.010895,
//     0.048778,
//     0.049769,
//     0.133336,
//     0.007965,
//     0.011638,
//     0.006108,
//     0.077790, // I (8)
//     0.002889,
//     0.000083,
//     0.053524,
//     0.026494,
//     0.073580,
//     0.093925,
//     0.026700,
//     0.008625,
//     0.061571, // R (17)
//     0.079605,
//     0.051378,
//     0.041887,
//     0.009698,
//     0.000041,
//     0.001940,
//     0.008336,
//     0.002600}; // Z (25)

size_t N = sizeof(frecuancas)/sizeof(frecuancas[0]);

typedef struct {
    float frec;
    AB arbol;
} tArboles;

typedef struct {    
    char letra;
	char cod[15];
} COD;

AB arbolHuffman(tArboles *A);
void listado(AB a, char arre[], int *cont, COD arresalida[]);

int main()
{
    // Armado del árbol de Huffman:

    AB T;
    tArboles arboles[N];
    char letra='a';

    for (size_t i = 0; i < N; i++) {
        arboles[i].frec = frecuancas[i];
        arboles[i].arbol = armarAB(NULL,letra++,NULL);
    }
    printf("\nÁrbol de Huffman: ");
    T = arbolHuffman(arboles);
    mostrarEnorden(T);
    printf("\n");

    // Invocación de la función Listado:

    char arre[15];		//Contiene el cóigo provisorio dentro del Listado
	COD arresal[26];	//Contiene la letra y su codigo 
	int cont=0;			//Mantiene el índice del arreglo arre

	listado(T, &arre[0], &cont, &arresal[0]);

    printf("\nCódigo letra 'a' = %c", arresal['a'-96].cod);
    printf("\nCódigo letra 'e' = %c", arresal['e'-96].cod);
    printf("\nCódigo letra 'f' = %c", arresal['f'-96].cod);

    liberarAB(T);

    return 0;
}

AB arbolHuffman(tArboles *A)
{
    float minIzq = A[0].frec;
    float minDer = A[0].frec;
    size_t p1 = 0;
    size_t p2 = 0;

    for (size_t j = 0; j < N-1; j++) {
        for (size_t i = 0; i < N; i++) {
            if(A[i].frec < 2) { 
                if(A[i].frec <= minIzq) {
                    minDer = minIzq;
                    minIzq = A[i].frec;
                    p2 = p1;
                    p1 = i;
                } else {
                    if(A[i].frec <= minDer) {
                        minDer = A[i].frec;
                        p2 = i;
                    }
                }
            }
        }
        A[p1].arbol = armarAB(A[p1].arbol,'*',A[p2].arbol);
        A[p1].frec = A[p1].frec + A[p2].frec;
        A[p2].frec = 2;
        minIzq = A[p1].frec;
        minDer = A[p2].frec;
    }
    return A[p1].arbol;
}

void listado(AB a, char arre[], int *cont, COD arresalida[])
{
	if(!esABvacio(a))
	{	if(!esABvacio(Izquierdo(a)))
		{	(*cont)++;
			arre[*cont]='0';
		}
		listado(Izquierdo(a),&arre[0], cont, &arresalida[0]);
		if(esHoja(a))
		{	char car=Raiz(a);
			arre[(*cont)+1]='\x0';
			arresalida[car-96].letra=car;
			strcpy(arresalida[car-96].cod,&arre[1]);
			printf("%s --> %c\n",arresalida[car-96].cod,arresalida[car-96].letra); //Esto permite ver por pantalla el código generado 
                        // getchar();												   //para la letra que se encuentra en la raiz de la hoja	
		}
		if(!esABvacio(Derecho(a)))
		{	(*cont)++;
			arre[*cont]='1';
		}
		listado(Derecho(a),&arre[0], cont, &arresalida[0]);
		(*cont)--;
	}
}