#include<stdio.h>
#include<stdlib.h>
#include "listaEnlazada.h"


int main(){

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

	printf("\n1.Creo una lista y la inicializo en lista vacia.\n");
	Lista L = crearListaVacia();

	printf("\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': ");
    if(esListaVacia(L))
		printf("Lista Vacia\n");
	else
	    printf("Lista NO Vacia\n");
	    
    printf("\n3.Muestro la lista vacia por pantalla: ");
    mostrar(L);

    printf("\n4.Escribo la cantidad de elementos de una lista vacia: %d \n", longitud(L));

    printf("\n5.Escribo el valor del primer elemento de una lista vacia: %d \n", primerElemento(L));

    printf("\n6.Inserto un elemento en la lista\n");
	L=insertar(L,1);

	printf("\n6.Pruebo la función esListaVacia. Mensaje esperado 'Lista NO Vacia': ");
    if(esListaVacia(L))
		printf("Lista Vacia\n");
	else
		printf("Lista NO Vacia\n");

	printf("\n7.Borro un elemento de la lista\n");
	L = borrar(L);

	printf("\n8.Muestro la lista vacia por pantalla: ");
	mostrar(L);

	printf("\n9.Inserto 5 elementos en la lista\n");
	L=insertar(L,1);
	L=insertar(L,2);
	L=insertar(L,3);
	L=insertar(L,4);
	L=insertar(L,5);

    printf("\n10.Escribo la cantidad de elementos de la lista: %d \n", longitud(L));

    printf("\n11.Escribo el valor del primer elemento de la lista vacia: %d \n", primerElemento(L));

    printf("\n12.Muestro la lista de 5 elementos por pantalla: ");
    mostrar(L);

    printf("\n13.Busco si pertenece el valor 100 en la lista. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(L, 100))
		printf("Pertenece\n");
	else
	    printf("NO Pertenece\n");
    
    printf("\n14.Busco si pertenece el valor 3 en la lista. Mensaje esperado: 'Pertenece': ");

    if(pertenece(L, 3))
    		printf("Pertenece\n");
    	else
    	    printf("NO Pertenece\n");


    printf("\n----INICIO DEL EXAMEN------\n");

    printf("n\Numeros mayores que 2: %d\n", contarMayoresQue(L, 2));



    printf("\n15.Libero la memoria reservada en forma dinámica\n");
    while(!esListaVacia(L))
    	L=borrar(L);
    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");





    return 0;
}
