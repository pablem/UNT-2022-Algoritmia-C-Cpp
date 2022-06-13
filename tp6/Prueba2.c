#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

int main() {

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");


    printf("\n6.Inserto 3 elementos en 10 filas\n");
	FILA C[10];
    for (size_t i = 0; i < 10; i++) {
        C[i] = filaVacia();
    }
	for (size_t i = 0; i < 10; i++) {
        C[i] = enfila(C[i],i+1);
		C[i] = enfila(C[i],i+2);
		C[i] = enfila(C[i],i+3);
    }
	printf("\n10.Muestro las filas: \n");
	for (size_t i = 0; i < 10; i++) {
        mostrar(C[i]);
    }

    printf("\n24.Libero la memoria reservada en forma din�mica\n");
	for (size_t i = 0; i < 10; i++) {
        while(!esFilaVacia(C[i])) {
    	C[i]=defila(C[i]);
		mostrar(C[i]);
		}
    }
    
	printf("\n15.Escribo el valor del FRENTE de las filas:\n");
	for (size_t i = 0; i < 10; i++) {
        printf("%d\n",frente(C[i]));
    }

    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");


    return 0;
}
