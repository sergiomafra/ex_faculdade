/**
 **
 ** Alunos:
 **
 ** 1412130044 - Higor José Pereira
 ** 1412130060 - Matheus Victor
 ** 1422130029 - Sérgio de Castilho Mafra
 **
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/** Tamanho padrão para strings **/
#define TAM 100

/** Estruturas **/

/** Opcao remete aos valores fornecidos pelo usuario **/
typedef struct Opcoes {
	char arq_modelo[TAM+1];
	int num_char;
	char arq_destino[TAM+1];
} Opcao;

/** Estrutura para salvar a letra e sua respectiva porcentagem acumulada **/
struct Listas {
	char letra;
	double ratio;
	struct Listas* prox;
};
typedef struct Listas Lista;

/** Funcoes **/
void limparTela();
void menu(Opcao *op);
void criarLista(FILE *abrir_arq, Lista *head);
void inserirLista(char aux[], Lista *head);
void imprimeLista(Lista *head);
void gerarArquivo(FILE *criar_arq, Lista *head, int num_char);


/** Programa principal **/
int main(void) {
	int flag = 1;								 /** Flag para o input do menu **/
	Opcao op;									 /** Armazenar input **/
	FILE *abrir_arq, *criar_arq;				 /** Ponteiros para arquivos **/
	Lista *head = (Lista*)malloc(sizeof(Lista)); /** Cabeca da lista **/
	head->prox = NULL;							 /** Inicializando a lista **/
	head->ratio = 0;							 /** cont. **/

	/**
		Looping para o menu.
		Caso o usuario digite um arquivo invalido, a flag se torna 0 e o menu()
		volta a ser chamado para que o usuario digite novamente as informacoes.
	 **/
	do {
		menu(&op);
		abrir_arq = fopen(op.arq_modelo, "r");
		if (abrir_arq == NULL) {
			limparTela();
			printf("\n\n\tProblema ao abrir o arquivo ou o arquivo nao existe.");
			flag = 0;
		} else {
			limparTela();
			flag = 1;
		}
	} while (flag == 0);

	/** Criacao da lista com os valores do modelo gerado pelo programa Desafio-01 **/
	criarLista(abrir_arq, head);
	fclose(abrir_arq);

	/** Gera o arquivo em cima do modelo inputado pelo usuario **/
	criar_arq = fopen(op.arq_destino, "a");
	gerarArquivo(criar_arq, head, op.num_char);
	fclose(criar_arq);

	/** Confirma que o arquivo foi gerado e encerra o programa **/
	printf("\n\tArquivo %s gerado com exito.\n\n", op.arq_destino);
	return 0;
}

/** Funcao simples para limpeza da tela do terminal / cmd **/
void limparTela() {
	system("cls || clear");
}

/** Funcao do menu **/
void menu(Opcao *op) {
	char aux[20];
	int aux2;

	/** Limpeza da tela e apresentacao **/
	limparTela();
	printf("\n\n\tGerador de texto\n");

	/**
		O programa requisita dados do usuario e os salva na memoria
		atraves do ponteiro que foi passado para a funcao. Estes dados
		sao: Nome do arquivo modelo, numero de caracteres que serao ge-
		rados no arquivo de destino e o nome do arquivo de destino.
	 **/
	printf("\n\tDigite o nome do arquivo com o modelo: ");
	fgets(op->arq_modelo, TAM, stdin);
	op->arq_modelo[strlen(op->arq_modelo)-1] = '\0';

	printf("\n\tDigite o numero de caracteres a ser gerado: ");
	fgets(aux, 20, stdin);
	op->num_char = atoi(aux);

	printf("\n\tDigite o nome do arquivo destino: ");
	fgets(op->arq_destino, TAM, stdin);
	op->arq_destino[strlen(op->arq_destino)-1] = '\0';
}

/**
	Funcao que cria a lista simplesmente encadeada com os dados do
	modelo original.
 **/
void criarLista(FILE *abrir_arq, Lista *head) {
	char aux[TAM+1];

	while(!feof(abrir_arq)) {
		fgets(aux, TAM, abrir_arq);
		aux[strlen(aux)-1] = '\0';
		inserirLista(aux, head);
	}
}

/** 
	Funcao para inserir uma nova letra na lista, juntamente com sua porcentagem acumulada
 **/
void inserirLista(char aux[], Lista *head) {
	int i;
	double tmp;
	char aux2[TAM-2];
	Lista *p;

	for(p = head; p != NULL; p = p->prox) { /** Caminha ate o último no da lista **/
		if(p->prox == NULL) {				/** Atribui a porcentagem acumulada **/
			tmp = p->ratio;					/** ate o presente no a tmp **/
			break;
		}
	}

	Lista *nova = (Lista*)malloc(sizeof(Lista));
	nova->letra = aux[0];

	for(i = 2; i < strlen(aux); i++) {
		aux2[i-2] = aux[i];
	}

	nova->ratio = atof(aux2) + tmp;			/** Atribui a ratio a porcentagem **/ 

	p->prox = nova;
	nova->prox = NULL;
}

/** Gera o arquivo final com as letras inseridas randomicamente **/
void gerarArquivo(FILE *criar_arq, Lista *head, int num_char) {
	double rand_num;
	int i;
	Lista *p;

	srand((unsigned)time(NULL)); /** modifica a semente da funcao rand() **/

	for(i = 0; i < num_char; i++) {
		rand_num = (rand() % (int)(pow(10,8)+1)) / pow(10,6);

		for(p = head; p != NULL; p = p->prox) {
			if(rand_num <= p->ratio || p->prox == NULL) {
				break;
			}
		}

		fprintf(criar_arq, "%c", p->letra);
	}
}