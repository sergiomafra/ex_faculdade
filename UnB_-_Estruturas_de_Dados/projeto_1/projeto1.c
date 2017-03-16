/**
 *	Este programa foi escrito por:
 *  Autor: Sérgio de Castilho Mafra
 *  Matrícula: 08/40769
 *  Aluno do 7 semestre de Engenharia Mecânica, UnB
 **/

#include <stdio.h>										// Para o printf e scanf
#include <stdlib.h>										// Função system

#define TAM 13											// Definição do tamanho padrão para tamanhos de vetores e iterações

// Declaração das funcões
void ordena(int *cres[], int esq, int dir);
void reverte(int *cres[], int *decres[]);
void imprime(int *cres[], int vet[], int *decres[]);

// Função main
int main() {
	int i;												// Iterador padrão.
	int vetor[TAM];										// Vetor que armazenará os números digitados pelo usuário.
	int *cres[TAM], *decres[TAM];						// Vetores de ponteiros que armazenaram os endereços dos números em ordem
														// crescente ou decrescente.

	system("clear");									// Limpando a tela

	for(i = 0; i < TAM; i++) {							// Coletando os numeros digitados pelo usuário e salvando em vetor[],
		printf("\tDigite o %d inteiro: ", i+1);			// além de atribuir à mesma posição de cres[i] o endereço de vetor[i].
		scanf("%d", &vetor[i]);
		cres[i] = &vetor[i];
	}

	ordena(cres, 0, TAM-1);								// Invoca a função ordena
	reverte(cres, decres);								// Invoca a função reverte

	imprime(cres, vetor, decres);						// Imprime na tela a tabela

	return 0;											// Encerra o programa
}

// Função ordena
void ordena(int *cres[], int esq, int dir) {			// Recebe como parâmetros o vetor de ponteiros para inteiros cres e os valores
	int pivo = esq, i, j, *ch;							// esq e dir, correspondentes a um índice válido do vetor.
														// A função ordena utiliza o algoritmo QuickSort para ordenação do vetor da
	for(i = esq + 1; i <= dir; i++) {					// seguinte maneira: cada índice do vetor cres aponta inicialmente para o
		j = i;											// índice correspondente do vetor desordenado vetor. O algoritmo QuickSort
		if(*cres[j] < *cres[pivo]) {					// se baseia no valor apontado pelos ponteiros do vetor cres para ordená-lo,
			ch = cres[j];								// mudando o endereço que estão apontando. Ao final, cada ponteiro do vetor
			while(j > pivo) {							// cres estará apontando para um índice do vetor vetor de modo que quando
				cres[j] = cres[j-1];					// o valor apontado por cres seja impresso, o conjunto gerado esteja ordenado
				j--;									// e nenhum valor do vetor original seja alterado ou mudado de local e nenhum
			}											// vetor ou cópia sejam gerados no processo.
			cres[j] = ch;								// O algoritmo quicksort foi copiado do site Wipédia e adaptado ao programa.
			pivo++;
		}
	}

	if(pivo - 1 >= esq) {
		ordena(cres, esq, pivo-1);
	}

	if(pivo + 1 <= dir) {
		ordena(cres, pivo+1, dir);
	}
}

// Função inverte
void reverte(int *cres[], int *decres[]) {				// Reverte recebe como parâmetros os vetores de ponteiros para inteiros cres
	int i, j;											// e decres. Em um laço for, atribui o ponteiro do primeiro índice de cres
														// à última posição de decres, o ponteiro do segundo índice ao penúltimo, e 
	for(i = 0, j = TAM - 1; i < TAM; i++, j--) {		// assim sucessivamente. Ao final do processo, o vetor decres é o reverso de
		decres[j] = cres[i];							// cres.
	}
}

void imprime(int *cres[], int vet[], int *decres[]) {	// Imprime de forma tabulada os dados
	int i;

	printf("\n\n\t  Crescente cres\t\t  Vetor Original\t\t Decrescente decres\n\n");

	for(i = 0; i < TAM; i++) {
		printf("\t%d\t%p\t\t%d\t%p\t\t%d\t%p\n", *cres[i], cres[i], vet[i], &vet[i], *decres[i], decres[i]);
	}
}