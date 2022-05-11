#include<stdio.h>
#include<stdlib.h>
#include "comision.h"

int main(){

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

	printf("\n1.Creo una comision y la inicializo en comision vacia.\n");
	Comision M = comisionVacia();

	printf("\n2.Pruebo la funcion estaVacia. Mensaje esperado 'Comision Vacia': ");
    if(estaVacia(M))
		printf("Comision Vacia\n");
	else
	    printf("Comision NO Vacia\n");
	    
    // printf("\n3.Muestro la Comision vacia por pantalla: ");
    // mostrar(M);

    printf("\n4.Escribo la cantidad de alumnos de una Comision vacia: %d \n", cantidad(M));

    printf("\n5.Escribo el apellido del ultimo alumno de una Comision vacia: %c \n", ultimoInscripto(M));

    printf("\n6.Inserto un elemento en la Comision\n");
	M=altaAlumno(M,'p');

	printf("\n6.Pruebo la funci�n estaVacia. Mensaje esperado 'Comision NO Vacia': ");
    if(estaVacia(M))
		printf("Comision Vacia\n");
	else
		printf("comision NO Vacia\n");

	printf("\n7.Borro el ultimo alumno de la comision\n");
	M = bajaUltimo(M);

	// printf("\n8.Muestro la comision vacia por pantalla: ");
	// mostrar(M);

	printf("\n9.Agrego 5 alumnos en la comision\n");
	M=altaAlumno(M,'a');
	M=altaAlumno(M,'b');
	M=altaAlumno(M,'c');
	M=altaAlumno(M,'d');
	M=altaAlumno(M,'e');

    printf("\n10.Escribo la cantidad de alumnos de la comision: %d \n", cantidad(M));

    printf("\n11.Escribo el valor del ultimo alumno de la comision: %c \n", ultimoInscripto(M));

    // printf("\n12.Muestro la comision de 5 alumnos por pantalla: ");
    // mostrar(M);

    printf("\n13.Busco si pertenece el alumno (f) a la comision. Mensaje esperado 'NO Pertenece': ");
    if(esta(M, 'f'))
		printf("Pertenece\n");
	else
	    printf("NO Pertenece\n");
    
    printf("\n14.Busco si pertenece el alumno (c) a la comision. Mensaje esperado: 'Pertenece': ");

    if(esta(M, 'c'))
    		printf("Pertenece\n");
    	else
    	    printf("NO Pertenece\n");

    printf("\n15.Libero la memoria reservada en forma dinamica\n");
    while(!estaVacia(M))
    	M=bajaUltimo(M);
    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");

    return 0;
}
