#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

int main() {

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

	printf("\n1.Creo una fila y la inicializo en fila vacia.\n");
	FILA F = filaVacia();

	printf("\n2.Pruebo la funcion esFilaVacia. Mensaje esperado 'Fila Vacia': ");
    if(esFilaVacia(F))
		printf("Fila Vacia\n");
	else
	    printf("Fila NO Vacia\n");
	    
    printf("\n3.Muestro la fila vacia por pantalla: ");
    mostrar(F);

    printf("\n4.Escribo la cantidad de elementos de una fila vacia: %d \n", longitud(F));

    printf("\n5.Escribo el valor del FRENTE de una fila vacia: %d \n", frente(F));

    printf("\n6.Inserto un elemento en la fila\n");
	F=enfila(F,1);

	printf("\n6.Pruebo la funci�n esFilaVacia. Mensaje esperado 'Fila NO Vacia': ");
    if(esFilaVacia(F))
		printf("Fila Vacia\n");
	else
		printf("Fila NO Vacia\n");

	printf("\n7.Borro un elemento de la fila\n");
	F = defila(F);

	printf("\n8.Muestro la fila vacia por pantalla: ");
	mostrar(F);

	printf("\n9.Inserto 5 elementos en la fila\n");
	F=enfila(F,1);
	F=enfila(F,2);
	F=enfila(F,3);
	F=enfila(F,4);
	F=enfila(F,5);

    printf("\n10.Escribo la cantidad de elementos de la fila: %d \n", longitud(F));

    printf("\n11.Escribo el valor del FRENTE de la fila: %d \n", frente(F));

    printf("\n12.Muestro la fila de 5 elementos por pantalla: ");
    mostrar(F);

    printf("\n13.Busco si pertenece el valor 100 en la fila. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(F, 100))
		printf("Pertenece\n");
	else
	    printf("NO Pertenece\n");
    
    printf("\n14.Busco si pertenece el valor 3 en la fila. Mensaje esperado: 'Pertenece': ");

    if(pertenece(F, 3))
    		printf("Pertenece\n");
    	else
    	    printf("NO Pertenece\n");

	printf("\n14.Borro el elemento en el frente de la fila, resultado: \n");
	F = defila(F);
	mostrar(F);

	printf("\n14.Borro el elemento en el frente de la fila, resultado: \n");
	F = defila(F);
	printf("\n14.Fila F1: ");
	mostrar(F);

	printf("\n14.Creo una fila nueva F2: ");
	FILA F2 = filaVacia();
	F2=enfila(F2,1);
	F2=enfila(F2,4);
	F2=enfila(F2,5);
	F2=enfila(F2,7);
	mostrar(F2);
	
	// printf("\n14.Comparo F1 con F2. Mensaje esperado: 'NO son iguales':  ");
 	// if(igualF(F, F2))
    // 	printf("Son iguales\n");
    // else
    // 	printf("NO son iguales\n");

	printf("\n14.Mezclo F1 con F2. Fila resultante: ");
	FILA F3;
	F3 = mezclar(&F, &F2);
	mostrar(F3);


    printf("\n15.Libero la memoria reservada en forma din�mica\n");
    while(!esFilaVacia(F))
    	F=defila(F);
    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");


    return 0;
}
