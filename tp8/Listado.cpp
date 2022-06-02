
//Lic. María Cristina Werenitzky Curia
/*

La función Listado se encarga de recuperar los códigos de Huffman para cada letra.

  PARAMETROS: 
			 - a: Árbol de Huffman
			 - arre[]: arreglo de caracteres que se usa para almacenar el código provisoriamente
			 - cont: entero que indica la posición del último valor almacenado en arre
			 - arresalida[]: arreglo del tipo COD que contiene en cada posición una letra y el código de Huffman correpondiente


  Invocación de la función Listado:

    char arre[15];		//Contiene el cóigo provisorio dentro del Listado
	COD arresal[26];	//Contiene la letra y su codigo 
	int cont=0;			//Mantiene el índice del arreglo arre
	AB ABHuff;
	....
	ABHuff=Huffman( ... );
	listado(ABHuff, &arre[0], &cont, &arresal[0]);
	....

  Para recuperar el código de una letra determinada deben escribir:
																	arresal[letra-96].cod


*/
#include "arbolBinario.h"
#include<stdio.h>
#include<string.h>
#include<conio.h>

struct COD{  char letra;
			 char cod[15];
			};

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
                        getch();												   //para la letra que se encuentra en la raiz de la hoja	
		}
		if(!esABvacio(Derecho(a)))
		{	(*cont)++;
			arre[*cont]='1';
		}
		listado(Derecho(a),&arre[0], cont, &arresalida[0]);
		(*cont)--;
	}
}
