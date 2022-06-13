#include<stdio.h>
#include<math.h>
#include<time.h>
#include "../tp6/fila.h"

void RadixSort(int A[], int n, int k);

int main(int argc, char const *argv[])
{
    int A[] = {123, 555, 1, 210, 177, 36, 110, 134, 18};
    int n = sizeof(A)/sizeof(A[0]);
    int k = 3;
    clock_t t;

    t=clock();
    RadixSort(A,n,k);
    t=clock()-t;
    printf("\nA ordenado = { ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ",A[i]);
    }
    printf("}\n");
    printf("Tiempo de ejecucuion = %E\n", (double)t/CLOCKS_PER_SEC);
    return 0;
}

void RadixSort(int A[], int n, int k)
{
    int ind;
    int l;
    FILA C[10];
    for (size_t i = 0; i < 10; i++) {
        C[i] = filaVacia();
    }
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            ind = A[j]%((int)pow(10,i+1))/((int)pow(10,i));
            C[ind] = enfila(C[ind],A[j]);
        }
        l = 0;
        for (size_t j = 0; j < n; j++)
        {
            while (esFilaVacia(C[l]))
                l++;
            A[j] = frente(C[l]);
            C[l] = defila(C[l]);
        }
    }
}