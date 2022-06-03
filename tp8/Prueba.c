#include<stdio.h>
#include<stdlib.h>
#include "arbolBinario.h"

int main() {

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

	printf("\n1.Creo un AB nulo.\n");
	AB T = ABVacio();

	printf("\n2.Pruebo la funcion esABvacio. Mensaje esperado 'AB Vacío': ");
    if(esABvacio(T))
		printf("AB Vacio\n");
	else
	    printf("AB NO Vacio\n");
	    
    printf("\n3.Muestro el AB vacio por pantalla:\n");
    mostrarPreorden(T);

    printf("\n6.Inserto hojas y subarboles:\n");
	T = armarAB(armarAB(NULL,'b',NULL),'a',armarAB(armarAB(NULL,'d',armarAB(NULL,'f',NULL)),'c',armarAB(NULL,'e',NULL)));

//a
//----b*
//----c
//--------d
//------------f(der)*
//--------e*

	printf("\n7.Pruebo la funci�n esABvacio. Mensaje esperado 'AB NO Vacío': ");
    if(esABvacio(T))
		printf("AB Vacio\n");
	else
		printf("AB NO Vacio\n");
	
	// printf("\n8.Escribo la cantidad de elementos de la AB con un elemento: %d \n", longitud(T));

	// printf("\n9.Borro un elemento de la LC\n");
	// T = LCBorrar(T);

	// printf("\n10.Muestro la AB vacia por pantalla: \n");
	// mostrar(T);

    printf("\n16.Recorro el AB en orden posterior: \n");
    mostrarPostorden(T);

    printf("\n17.Busco si pertenece el valor 'z' en el AB. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(T, 'z'))
		printf("Pertenece\n");
	else
	    printf("NO Pertenece\n");
    
    printf("\n18.Busco si pertenece el valor 'b' en el AB. Mensaje esperado: 'Pertenece': ");
    if(pertenece(T, 'b'))
    		printf("Pertenece\n");
    	else
    	    printf("NO Pertenece\n");
	
	printf("\n20. Cuento el número de hojas. Cantidad: %d\n", numeroHojas(T));

	// printf("\n21. Muestro la AB luego de la funcion: \n");
	// mostrar(T);

	// printf("\n22.Inserto 5 elementos en la LC\n");
	// T=LCInsertar(T,4);
	// T=LCInsertar(T,2);
	// T=LCInsertar(T,4);
	// T=LCInsertar(T,4);
	// T=LCInsertar(T,5);
	// mostrar(T);

	// // printf("\n23. Funcion contar k=4. Cantidad: %d\n", ContarK(&T,4));

	// // printf("\n24. Funcion contar k=7. Cantidad: %d\n", ContarK(&T,7));

	// printf("\n24. Funcion borrar k=7. Cantidad: %d\n", LCBorrarK(T,7));

	// printf("\n25. Muestro la AB luego de la funcion: \n");
	// mostrar(T);

	// printf("\n23*. Funcion contar2 k=4. Cantidad: %d\n", ContarK2(T,4,longitud(T)));

	// printf("\n24*. Funcion contar2 k=7. Cantidad: %d\n", ContarK2(T,7,longitud(T)));

	// printf("\n25*. Muestro la AB luego de la funcion: \n");
	// mostrar(T);

    printf("\n26.Libero la memoria reservada en forma din�mica\n");
    liberarAB(T);

    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");


    return 0;
}
