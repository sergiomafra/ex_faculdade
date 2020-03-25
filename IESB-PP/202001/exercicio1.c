#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define tam 150

int funcao_pesada(int x);
void mostrar_vetor(int * vet, int x);

int main()
{
    double t1,t2;
    int i,j,aux,vet[tam];

    t1 = omp_get_wtime();

    j=5;

    #pragma omp parallel for
    for(i=0;i<tam;i++)
    {
        aux = j + (i+1)*2;
        vet[i] = funcao_pesada(aux);
    }

    t2 = omp_get_wtime();

   // mostrar_vetor(vet,tam);

    printf("\n Tempo total: %lf",t2-t1);
    return 0;
}

int funcao_pesada(int x)
{
    int i,j,k;
    for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++)
        {
            for(k=0;k<100;k++)
            {
                x = x;
            }
        }
    }
    return x;
}

void mostrar_vetor(int * vet, int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        printf("\n%d",vet[i]);
    }
    printf("\n");
}
