/** DISEÑO DE ALGORITMOS RECURSIVOS **/

#include<stdlib.h>
#include<stdio.h>

/** 2. Dado un número entero positivo, diseñe dos algoritmos recursivos para obtener los 
siguientes resultados:

a. Escriba las cifras del número separadas por un espacio.
Por ejemplo: si número es 7254, la salida debe ser: 7 2 5 4.  

b. Cuente la cantidad de veces que aparece un dado dígito en el número.
Por ejemplo: si el número es 13234 y el digito es 3, el resultado debe ser 2. **/

void separar(int num);
int contar(int num, int d);


int main(int argc, char const *argv[])
{
    int num = 9795999;
    int d = 9;

    printf("\nEj 1)\n");
    separar(num);

    printf("\n\nEj 2)\n");
    printf("Num = %d, Dig = %d, Resultado= %d\n", num, d, contar(num,d));

    return 0;
}

void separar(int num)
{
    if (num < 10) {
        printf("%d ", num);
    } else {
        separar(num/10);
        printf("%d ", num % 10);
    }
}

int contar(int num, int d)
{
    if (num == 0) {
        return 0;
    } else {
        if (num % 10 == d) {
            return 1 + contar(num/10, d);
        } else {
            return contar(num/10, d);
        }
    }
}