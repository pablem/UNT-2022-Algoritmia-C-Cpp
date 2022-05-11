/** ESQUEMA DIVIDE & CONQUER **/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/** 4. (MIDIFICADO) Dado un vector de números enteros , diseñe una función que 
devuelva el valor acumulado de los elementos del vector teniendo en cuenta que 
los números (EN POSICIONES) pares se suman y los números (EN POSICIONES) impares se restan. **/

int suma(int *, int );

int main()
{
    int n = 10;
    int vector[] = {85,99,87,41,13,34,55,85,73,21};     

    return 0;
}

int suma(int *v, int n)
{
    if (n == 0) {
        return v[0];
    }
    else
    {
        if (n%2 == 0) {
            return v[n] + suma(v,n);
        } else {
            return -v[n] + suma(v,n);
        }
    }
    
}