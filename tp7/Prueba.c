#include<stdio.h>
#include<stdlib.h>
#include "listaCircular.h"

int main() {

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

	printf("\n1.Creo una LC y la inicializo en LC vacia.\n");
	LC lc = LCVacia();

	printf("\n2.Pruebo la funcion esLCVacia. Mensaje esperado 'LC Vacia': ");
    if(esLCVacia(lc))
		printf("LC Vacia\n");
	else
	    printf("LC NO Vacia\n");
	    
    printf("\n3.Muestro la LC vacia por pantalla:\n");
    mostrar(lc);

    printf("\n4.Escribo la cantidad de elementos de una LC vacia: %d \n", longitud(lc));

    printf("\n5.Escribo el valor de la VENTANA de una LC vacia: %d \n", LCValor(lc));

    printf("\n6.Inserto un elemento en la LC\n");
	lc=LCInsertar(lc,1);

	printf("\n7.Pruebo la funci�n esLCVacia. Mensaje esperado 'LC NO Vacia': ");
    if(esLCVacia(lc))
		printf("LC Vacia\n");
	else
		printf("LC NO Vacia\n");
	
	printf("\n8.Escribo la cantidad de elementos de la LC con un elemento: %d \n", longitud(lc));

	printf("\n9.Borro un elemento de la LC\n");
	lc = LCBorrar(lc);

	printf("\n10.Muestro la LC vacia por pantalla: \n");
	mostrar(lc);

	printf("\n11.Inserto 33, -9 y 4 en la LC: \n");
	lc=LCInsertar(lc,33);
	lc=LCInsertar(lc,-9);
	lc=LCInsertar(lc,4);
	mostrar(lc);
	
	printf("\n12.Borro los dos elementos y muestro:\n");
	lc = LCBorrar(lc);
	mostrar(lc);
	lc = LCBorrar(lc);
	mostrar(lc);
	lc = LCBorrar(lc);
	mostrar(lc);

	printf("\n13.Inserto 5 elementos en la LC\n");
	lc=LCInsertar(lc,1);
	lc=LCInsertar(lc,2);
	lc=LCInsertar(lc,3);
	lc=LCInsertar(lc,4);
	lc=LCInsertar(lc,5);

    printf("\n14.Escribo la cantidad de elementos de la LC: %d \n", longitud(lc));

    printf("\n15.Escribo el valor de la VENTANA de la LC: %d \n", LCValor(lc));

    printf("\n16.Muestro la LC de 5 elementos por pantalla: \n");
    mostrar(lc);

    // printf("\n17.Busco si pertenece el valor 100 en la LC. Mensaje esperado 'NO Pertenece': ");
    // if(pertenece(lc, 100))
	// 	printf("Pertenece\n");
	// else
	//     printf("NO Pertenece\n");
    
    // printf("\n18.Busco si pertenece el valor 3 en la LC. Mensaje esperado: 'Pertenece': ");
    // if(pertenece(lc, 3))
    // 		printf("Pertenece\n");
    // 	else
    // 	    printf("NO Pertenece\n");

	printf("\n19. Roto la Lista Circular: \n");
	for (size_t i = 0; i < 5; i++) {
		lc = LCRotar(lc);
		mostrar(lc);
	}
	
	printf("\n20. Funcion contar k=4. Cantidad: %d\n", ContarK(&lc,4));

	printf("\n21. Muestro la LC luego de la funcion: \n");
	mostrar(lc);

	printf("\n22.Inserto 5 elementos en la LC\n");
	lc=LCInsertar(lc,4);
	lc=LCInsertar(lc,2);
	lc=LCInsertar(lc,4);
	lc=LCInsertar(lc,4);
	lc=LCInsertar(lc,5);
	mostrar(lc);

	printf("\n23. Funcion contar k=4. Cantidad: %d\n", ContarK(&lc,4));

	printf("\n24. Funcion contar k=7. Cantidad: %d\n", ContarK(&lc,7));

	printf("\n25. Muestro la LC luego de la funcion: \n");
	mostrar(lc);

	printf("\n23*. Funcion contar2 k=4. Cantidad: %d\n", ContarK2(lc,4,longitud(lc)));

	printf("\n24*. Funcion contar2 k=7. Cantidad: %d\n", ContarK2(lc,7,longitud(lc)));

	printf("\n25*. Muestro la LC luego de la funcion: \n");
	mostrar(lc);

    printf("\n26.Libero la memoria reservada en forma din�mica\n");
    while(!esLCVacia(lc))
    	lc=LCBorrar(lc);

    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");


    return 0;
}
