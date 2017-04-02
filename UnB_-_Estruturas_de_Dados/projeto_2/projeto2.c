/* 
 * Arquivo: 	projeto2.c
 * Autor: 		Sergio de Castilho Mafra
 * Matricula: 	08/40769
 * Estruturas de Dados - UnB - 2017/1
 *
 * Criado em 02 de Abril de 2017, 02:40
 */

/* *** Bibliotecas *** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/* *** Constantes *** */
#define TAM_PALAVRA 46 // Maior palavra do português possui 46 letras
#define TAM_ARQUIVO 50

/* *** Estrutura *** */
typedef struct Lista_de_Palavras {
	char palavra[TAM_PALAVRA+1];
	int quantidade; // Relativa a quantidade de vezes que uma palavra aparece em um documento
	struct Lista_de_Palavras *proxima;
} Lista;

/* *** Funções *** */
void apresentacao();
int abrirArquivos(FILE **arquivo1, FILE **arquivo2);
void fecharArquivos(FILE **arquivo1, FILE **arquivo2);
void contadorDePalavras(FILE **arq, Lista *cabeca);
void limparString(char palavra[]);
int validarCaracter(char c);
void removerCaracterInicio(char palavra[]);
void removerCaracterFinal(char palavra[]);
void inserirNaLista(Lista *cabeca, char palavra[]);
void ordenarLista(Lista *p, int esquerdo, int direito);
int dividirParaConquistar(Lista *p, int esquerdo, int direito, int pivo);
Lista *percorrerLista(Lista *p, int pos);
void trocarValor(Lista *p, int pos, int pos2);
int tamanhoDaLista(Lista *cabeca);
void imprimir(Lista *cabeca);

/* *** main *** */
/* Corpo do programa */
int main() {
	/* Variáveis */
	FILE *arquivo1 = NULL;
	FILE *arquivo2 = NULL;
	int flag = 0; // Variável de controle - 1 para arquivos inexistentes e 0 para arquivos abertos com sucesso
	Lista *lista_arq1 = (Lista*)malloc(sizeof(Lista));
	Lista *lista_arq2 = (Lista*)malloc(sizeof(Lista));

	strcpy(lista_arq1->palavra,"TOTAL DE PALAVRAS\0");
	lista_arq1->quantidade = 0;
	lista_arq1->proxima = NULL;

	strcpy(lista_arq2->palavra,"TOTAL DE PALAVRAS\0");
	lista_arq2->quantidade = 0;
	lista_arq2->proxima = NULL;

	/* Função para que o programa aceite caracteres da língua portuguesa */
	setlocale(LC_ALL, "Portuguese");

	/* Looping para garantir a correta abertura do programa */
	do {
		apresentacao();
		if(flag == 1) {
			printf("\tO ARQUIVO DIGITADO NÃO EXISTE. TENTE NOVAMENTE.\n\n");
		}
		flag = abrirArquivos(&arquivo1, &arquivo2); // Abrindo os arquivos necessários
	} while(flag);

	contadorDePalavras(&arquivo1, lista_arq1);
	//contadorDePalavras(&arquivo2, lista_arq2);

	imprimir(lista_arq1);

	return 0;
}

/* *** apresentacao *** */
/* Explica para o usuário o que o programa faz */
void apresentacao() {
	system("clear");
	printf("\n\n\tProjeto 02 - Estruturas de Dados - Turma C");
	printf("\n\tUnB - Universidade de Brasília");
	printf("\n\tAluno: Sérgio de Castilho Mafra");
	printf("\n\tMatrícula: 08/40769");
	printf("\n\n\tCOMPARADOR DE TEXTOS");
	printf("\n\n\t\tEste programa comparará dois textos fornecidos por você, usuário,\n\te imprimirá na tela um valor que representa quão parecidos os textos são.\n\tAcima de 50%%, os textos serão considerados plágio.\n\n");
}

/* *** abrirArquivos *** */
/* Coleta do usuário os nomes dos arquivos e os abre */
int abrirArquivos(FILE **arquivo1, FILE **arquivo2) {
	char arq1[TAM_ARQUIVO+1], arq2[TAM_ARQUIVO+1];

	/* Coletando o nome dos arquivos e verificando a existência dos mesmos */
	// Arquivo 1
	printf("\tDigite o nome do primeiro arquivo: ");
	fgets(arq1, TAM_ARQUIVO, stdin);
	arq1[strlen(arq1)-1] = '\0';

	if((*arquivo1 = fopen(arq1, "r")) == NULL) {
		return 1;
	}

	// // Arquivo 2
	// printf("\tAgora, digite o nome do segundo: ");
	// fgets(arq2, TAM_ARQUIVO, stdin);
	// arq2[strlen(arq2)-1] = '\0';

	// if((*arquivo2 = fopen(arq2, "r")) == NULL) {
	// 	return 1;
	// }

	// Flag 0, se os arquivos forem abertos com sucesso
	return 0;
}

/* *** contadorDePalavras *** */
/* Percorre o arquivo, conta as palavras e as envia para a função inserirNaLista. Por fim, organiza as palavras em ordem alfabética */
void contadorDePalavras(FILE **arq, Lista *cabeca) {
	int i;
	char palavra[TAM_PALAVRA+1];
	fseek(*arq,0,SEEK_SET); //Posiciona o cursor na posição 0 do arquivo

	while ((fscanf(*arq, "%s", palavra)) != EOF) {
		for(i = 0; i < strlen(palavra); i++) {
			palavra[i] = tolower(palavra[i]);
		}

		/* Eliminação de caractes indesejados */
		limparString(palavra);

		/* Enviando as palavras pra serem inseridas na lista */
		if(strlen(palavra) != 0)
        	inserirNaLista(cabeca, palavra);
	}

	ordenarLista(cabeca->proxima, 1, tamanhoDaLista(cabeca));
	printf("\n\n\tNúmero de palavras diferentes: %d", tamanhoDaLista(cabeca));

	fclose(*arq);
}

void limparString(char palavra[]) {
	int i;

	/* Eliminação de caracteres indesejados no início */
	for(i = 0; i < strlen(palavra); i++) {
		if (validarCaracter(palavra[i]) == 0)
			break;
		else
			removerCaracterInicio(palavra);
	}

	/* Eliminação de caracteres indesejados no final */
	for(i = strlen(palavra)-1; i >= 0; i--) {
		if (validarCaracter(palavra[i]) == 0)
			break;
		else
			removerCaracterFinal(palavra);
	}
}

int validarCaracter(char c) {
	switch(c) {
		case ',': return 1;
		case '.': return 1;
		case '?': return 1;
		case ':': return 1;
		case '!': return 1;
		case '-': return 1;
		case '\"': return 1;
		case ';': return 1;
		default: return 0;
	}
}

void removerCaracterInicio(char palavra[]) {
	int i;

	for(i = 0; i < strlen(palavra)-1; i++) {
		palavra[i] = palavra[i+1];
	}

	removerCaracterFinal(palavra);
}

void removerCaracterFinal(char palavra[]) {
	palavra[strlen(palavra)-1] = '\0';
}

/* *** inserirNaLista *** */
/* Se a palavra for nova na lista, insere-a no final. Se a palavra já existir na lista, incrementa o contator da mesma */
void inserirNaLista(Lista *cabeca, char palavra[]) {
	Lista *p;
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	strcpy(novo->palavra, palavra);
	cabeca->quantidade++;

	for(p = cabeca; p != NULL; p = p->proxima) {
		if(strcmp(p->palavra, palavra) == 0) {
			p->quantidade++;
			return;
		}

		if(p->proxima == NULL) {
			break;
		}
	}

	p->proxima = novo;
	novo->proxima = NULL;

	novo->quantidade = 1;
}

/* *** ordenarLista *** */
void ordenarLista(Lista *p, int esquerdo, int direito) {
    if (direito > esquerdo) {
    	int pivo = (esquerdo+direito)/2;
     	int pos = dividirParaConquistar(p, esquerdo, direito, pivo);
      	ordenarLista(p, esquerdo, pos - 1);
      	ordenarLista(p, pos + 1, direito);
    }
}

int dividirParaConquistar(Lista *p, int esquerdo, int direito, int pivo) {
    int pos,i;
    Lista *tmp, *tmp2;
    
    trocarValor(p, pivo, direito);
    pos = esquerdo;
    for (i = esquerdo; i < direito; i++) {
    	tmp = percorrerLista(p, i);
        tmp2 = percorrerLista(p, direito);
        if (strcmp(tmp->palavra, tmp2->palavra) < 0) {
            trocarValor(p, i, pos);
            pos++;
        }
    }
    trocarValor(p, direito, pos);
    return pos;
}

Lista *percorrerLista(Lista *p, int pos) {
	int i = 1;
	
	Lista *tmp = p;
	while (tmp->proxima != NULL && i<pos) {
		tmp = tmp->proxima;
		i++;
	}
	return tmp;
}

void trocarValor(Lista *p, int pos, int pos2) {
    Lista *tmp, *tmp2;
    char aux[TAM_PALAVRA + 1];

    int q1, q2;
	
    tmp = percorrerLista(p, pos);
    tmp2 = percorrerLista(p, pos2);
	
	strcpy(aux, tmp->palavra);
    strcpy(tmp->palavra, tmp2->palavra);
    strcpy(tmp2->palavra, aux);

    q1 = tmp->quantidade;
    q2 = tmp2->quantidade;

    tmp->quantidade = q2;
    tmp2->quantidade = q1;
}

int tamanhoDaLista(Lista *cabeca) {
	int tam = -1;
	Lista *p;

	for(p = cabeca; p != NULL; p = p->proxima) {
		tam++;
		if(p->proxima == NULL) {
			break;
		}
	}

	return tam;
}

/* *** imprimir *** */
void imprimir(Lista *cabeca) {
	Lista *p;

	for(p = cabeca; p != NULL; p = p->proxima) {
		printf("\n\t%s: %d", p->palavra, p->quantidade);
	}
	puts("\n");
}