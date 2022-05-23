#include <stdio.h>
#include <stdlib.h>
#include "arbolBinario.h"

float frecuancas[] = {
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

    const size_t N = sizeof(frecuancas)/sizeof(frecuancas[0]);

typedef struct {
    float frec;
    AB arbol;
} tArboles;

AB arbolHuffman(tArboles *A);

int main()
{
    AB T, Tprueba, cb, fe;
    tArboles arboles[N];
    char letra = 'A';

    cb = armarAB(armarAB(NULL,'c',NULL),'*',armarAB(NULL,'b',NULL));
    fe = armarAB(armarAB(NULL,'f',NULL),'*',armarAB(NULL,'e',NULL));
    Tprueba = armarAB(armarAB(NULL,'a',NULL),'*',armarAB(cb,'*',armarAB(fe,'*',armarAB(NULL,'d',NULL))));
    mostrarPost(Tprueba);
    liberarAB(Tprueba);
    printf("\n");

    for (size_t i = 0; i < N; i++) {
        arboles[i].frec = frecuancas[i];
        arboles[i].arbol = armarAB(NULL,letra++,NULL);
    }
    T = arbolHuffman(arboles);
    mostrarPost(T);
    liberarAB(T);
  
    for (size_t i = 0; i < N; i++) {
        free(arboles[i].arbol);
    }
    
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