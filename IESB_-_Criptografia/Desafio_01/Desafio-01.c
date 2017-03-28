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
#include <ctype.h>

/** GLOBAL ESCOPE **/
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,espaco; /** ocorrência de cada letra **/
char z26[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};/** definição do alfabeto z26 que será utilizado para comparar com o caractere recebido do texto **/
char z27[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
int totalZ27 = 0, totalZ26 = 0, cont = 0;
FILE *arq, *destino;
char ch;

/** FUNCTION PROTOTYPE **/
void frequencia(char letra);
int validaLetra(char letra, int alfabeto); 
int z26_init(FILE *arq, FILE *destino, int comando);
int z27_init(FILE *arq, FILE *destino, int comando);
void imprimePercetual(char letra, int comando, FILE*destino);
void dump();
void contagem(char letra);

void main(){

    char url[30];
    int comando = 1;

    while(comando)
    {

        system("cls || clear");system("dir *.txt");
        printf("\n\tGeracao de modelo de ordem 1\n\n");
        printf("Selecione a opcao desejada: \n");
        printf("\t1 - z26\n");
        printf("\t2 - z27\n");
        printf("\t0 - sair\n");
        scanf("%d",&comando);  
        system("cls || clear");
        switch(comando)
        {
            case 1:
            { 
                printf("Digite o nome do arquivo amostra (.txt): ");
                scanf("%s",url);
                arq = fopen(url, "r");
                printf("Digite o nome do arquivo para armazenamento (.txt): ");
                scanf("%s",url);
                destino = fopen(url, "w");      
                z26_init(arq,destino,comando); 
                break;
            }
            case 2:
            {
                printf("Digite o nome do arquivo amostra (.txt): ");
                scanf("%s",url);
                arq = fopen(url, "r");
                printf("Digite o nome do arquivo para armazenamento (.txt): ");
                scanf("%s",url);
                destino = fopen(url, "w");                  
                z27_init(arq,destino,comando); 
                break;
            }
            case 3: break;
            case 0: break;
        }
    }  
}

void contagem(char letra){
    switch(letra){
        case 'A': a++; break;
        case 'B': b++; break;
        case 'C': c++; break;
        case 'D': d++; break;
        case 'E': e++; break;
        case 'F': f++; break;
        case 'G': g++; break;
        case 'H': h++; break;
        case 'I': i++; break;
        case 'J': j++; break;
        case 'K': k++; break;
        case 'L': l++; break;
        case 'M': m++; break;
        case 'N': n++; break;
        case 'O': o++; break;
        case 'P': p++; break;
        case 'Q': q++; break;
        case 'R': r++; break;
        case 'S': s++; break;
        case 'T': t++; break;
        case 'U': u++; break;
        case 'V': v++; break;
        case 'W': w++; break;
        case 'X': x++; break;
        case 'Y': y++; break;
        case 'Z': z++; break;
        case ' ': espaco++; break;
    }
}

void imprimePercetual(char letra, int comando, FILE *destino){
    int total;
    if (comando == 1)
        total = totalZ26; /** atribui a variável local total com o valor da variável global responsável **/
                          /** por guardar a quantidade total de caracteres de z26 **/ 
    else if (comando == 2)/** atribui a variável local total com o valor da variável global responsável **/
                          /** por guardar a quantidade total de caracteres de z27 **/
        total = totalZ27;
    switch(letra){
        /** calcula percentual de todas as letras **/
        case 'A':
        {
            printf("A: %f%% \n", ((float)a/total) * 100); /* mostra na tela **/
            fprintf(destino,"A:%f \n", ((float)a/total) * 100); /** escreve no arquivo **/
            break;
        }
        case 'B':{
            printf("B: %f%% \n", ((float)b/total) * 100);
            fprintf(destino,"B:%f \n", ((float)b/total) * 100); 
            break;
        }
        case 'C':
        {
            printf("C: %f%% \n", ((float)c/total) * 100); 
            fprintf(destino,"C:%f \n", ((float)c/total) * 100);
            break;
        }
        case 'D':
        {
            printf("D: %f%% \n", ((float)d/total) * 100);
            fprintf(destino,"D:%f \n", ((float)d/total) * 100); 
            break;   
        }
        case 'E':
        {
            printf("E: %f%% \n", ((float)e/total) * 100);
            fprintf(destino,"E:%f \n", ((float)e/total) * 100); 
            break;
        }
        case 'F':
        {
            printf("F: %f%% \n", ((float)f/total) * 100);
            fprintf(destino,"F:%f \n", ((float)f/total) * 100); 
            break;            
        }
        case 'G':
        {
            printf("G: %f%% \n", ((float)g/total) * 100);
            fprintf(destino,"G:%f \n", ((float)g/total) * 100); 
            break;
        }
        case 'H':
        {
            printf("H: %f%% \n", ((float)h/total) * 100);
            fprintf(destino,"H:%f \n", ((float)h/total) * 100); 
            break;
        }
        case 'I':
        {
            printf("I: %f%% \n", ((float)i/total) * 100);
            fprintf(destino,"I:%f \n", ((float)i/total) * 100);
            break;
        }
        case 'J':
        {
            printf("J: %f%% \n", ((float)j/total) * 100);
            fprintf(destino,"J:%f \n", ((float)j/total) * 100); 
            break;
        }
        case 'K':
        {
            printf("K: %f%% \n", ((float)k/total) * 100);
            fprintf(destino,"K:%f \n", ((float)k/total) * 100); 
            break;
        }
        case 'L':
        {
            printf("L: %f%% \n", ((float)l/total) * 100);
            fprintf(destino,"L:%f \n", ((float)l/total) * 100); 
            break;
        }
        case 'M':
        {
            printf("M: %f%% \n", ((float)m/total) * 100);
            fprintf(destino,"M:%f \n", ((float)m/total) * 100); 
            break;
        }
        case 'N':
        {
            printf("N: %f%% \n", ((float)n/total) * 100);
            fprintf(destino,"N:%f \n", ((float)n/total) * 100); 
            break;
        }
        case 'O':
        {
            printf("O: %f%% \n", ((float)o/total) * 100);
            fprintf(destino,"O:%f \n", ((float)o/total) * 100); 
            break;   
        }
        case 'P':
        {
            printf("P: %f%% \n", ((float)p/total) * 100);
            fprintf(destino,"P:%f \n", ((float)p/total) * 100); 
            break;
        }
        case 'Q':
        {
            printf("Q: %f%% \n", ((float)q/total) * 100);
            fprintf(destino,"Q:%f \n", ((float)q/total) * 100); 
            break;            
        }
        case 'R':
        {
            printf("R: %f%% \n", ((float)r/total) * 100);
            fprintf(destino,"R:%f \n", ((float)r/total) * 100); 
            break;
        }
        case 'S':
        {
            printf("S: %f%% \n", ((float)s/total) * 100);
            fprintf(destino,"S:%f \n", ((float)s/total) * 100); 
            break;
        }
        case 'T':
        {
            printf("T: %f%% \n", ((float)t/total) * 100); 
            fprintf(destino,"T:%f \n", ((float)t/total) * 100);
            break;
        }
        case 'U':
        {
            printf("U: %f%% \n", ((float)u/total) * 100);
            fprintf(destino,"U:%f \n", ((float)u/total) * 100); 
            break;
        }
        case 'V':
        {
            printf("V: %f%% \n", ((float)v/total) * 100);
            fprintf(destino,"V:%f \n", ((float)v/total) * 100); 
            break;
        }
        case 'W':
        {
            printf("W: %f%% \n", ((float)w/total) * 100);
            fprintf(destino,"W:%f \n", ((float)w/total) * 100); 
            break;
        }
        case 'X':
        {
            printf("X: %f%% \n", ((float)x/total) * 100);
            fprintf(destino,"X:%f \n", ((float)x/total) * 100); 
            break;
        }
        case 'Y':
        {
            printf("Y: %f%% \n", ((float)y/total) * 100); 
            fprintf(destino,"Y:%f \n", ((float)y/total) * 100);
            break;
        }
        case 'Z':
        {
            printf("Z: %f%% \n", ((float)z/total) * 100); 
            fprintf(destino,"Z:%f \n", ((float)z/total) * 100);
            break;
        }
        case ' ':
        {
            printf("Espaco: %f%% \n", ((float)espaco/total) * 100);
            fprintf(destino," :%f \n", ((float)espaco/total) * 100); 
            break;
        }
    }
}

void dump(){
    a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0,espaco=0;
    totalZ27 = 0,totalZ26 = 0, cont = 0;
    fclose(destino);
    fclose(arq);
}

int z26_init(FILE *arq, FILE *destino, int comando){

    if(arq == NULL)
    {
       printf("\nErro, nao foi possivel abrir o arquivo\n");
       return 0;
    }
    while((ch = fgetc(arq)) != EOF )/** lê caractere por caractere do arquivo **/
    {

        ch = toupper(ch); /** coverte os caracteres para maiúsculo, usado aqui para não dar conflito na compração ch = EOF **/
        if(validaLetra(ch,1))/** valida letra para o alfabeto z27 **/
        {
            contagem(ch); /** chama a contagem da letra lida **/
            totalZ26++; /** incrementa o total de letras lidas **/
        }
    }
    printf("\n\tZ26\n");
    for (cont = 0; cont<26; cont++){
        imprimePercetual(z26[cont],comando,destino); /** função para impressão das letras e seus respectivos percentuais **/
    } 
    printf("\nTotal de caracteres lidos: %i\n\n", totalZ26);
    dump(); 
    system("\npause");
    return 1;
}

int z27_init(FILE *arq, FILE *destino, int comando){
    if(arq == NULL)
    {
       printf("\nErro, nao foi possivel abrir o arquivo\n");
       return 0;
    }
    while((ch = fgetc(arq)) != EOF )/** lê caractere por caractere do arquivo **/
    {
        ch = toupper(ch); /** coverte os caracteres para maiúsculo, usado aqui para não dar conflito na compração ch = EOF **/
        if(validaLetra(ch,2))/** valida letra para o alfabeto z27 **/
        {
            contagem(ch); /** conta o caracter lido **/
            totalZ27++; /** imcrementa o total de caracteres lidos de z27 **/
        }
    }
    printf("\n\tZ27\n");
    for (cont = 0; cont<27; cont++){
        imprimePercetual(z27[cont],comando,destino); /** função para impressão das letras e seus respectivos percentuais **/
    }       
    printf("\nTotal de caracteres lidos: %i\n\n", totalZ27);
    dump(); 
    system("pause");
    return 1;    
}

int validaLetra(char letra, int alfabeto){
/**  alfabeto 1 = z26
    alfabeto 2 = z27
    alfabeto 3 = z256 **/
    int cont = 0;

    if (alfabeto == 1){
        for (cont=0; cont<26;cont++)
        {
            if(z26[cont] == letra){
                return 1; /** se pertence ao conjunto z26 é verdadeiro **/
            }
        }
        return 0; /** caso contrário é falso **/
    }
    if (alfabeto == 2)
    {
        for (cont=0; cont<27; cont++)
        {   
            if(z27[cont] == letra)
            {
                return 1; /** se pertence ao conjunto z27 é verdadeiro **/
            }
        }
        return 0; /** caso contrário é falso **/
    }
}