/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 11b - BibTeX */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Declaracao da estrutura de dados de cada referencia */
struct Article {
    char label[451];
    char author[501];
    char title[501];
    char journal[101];
    char year[51];
    char volume[51];
    char number[51];
    char pages[51];
};

typedef struct Article Article;

/* Prototipo das funcoes utilizadas */
void leEntradas(int nEntradas, Article entradas[]);
void insereValor(int inicio, Article entradas[]);
void ordenaLexic(int nEntradas, Article entradas[]);
void zeraEntradas(int nEntradas, Article entradas[]);
void imprimeRefer(int nEntradas, Article entradas[]);

int main() {
    
    /* Declaracao das variaveis utilizadas */
    int nEntradas;
    Article *entradas;
    
    /* Obtencao e alocacao de memoria referente ao tamanho fornecido */
    scanf ("%*[%] %d", &nEntradas);
    
    entradas = malloc(nEntradas * sizeof(Article));
    
    /* Na ordem, zera as estruturas, le a entrada, ordena-a e imprime */
    zeraEntradas(nEntradas, entradas);
    leEntradas(nEntradas, entradas);
    ordenaLexic(nEntradas, entradas);
    imprimeRefer(nEntradas, entradas);
    
    /* Libera para o sistema operacional o uso da memoria previamente alocada */
    free (entradas);
    
    return 0;
}

/* Funcao que le os dados de entrada e os armazena devidamente */
void leEntradas(int nEntradas, Article entradas[]){
    
    int i;
    char campo[8];
    
    /* Le os dados de cada estrutura */
    for (i = 0; i < nEntradas; i++){
        /* Le cada label e garante que este funcionara na proxima iteracao*/
        scanf ("%*[\n@article{] %[^,]s",entradas[i].label);
        while (getchar() != '\n'){};
        /* Le os dados de cada referencia conforme eles sao disponibilizados */
        do{
            scanf ("%s", campo);
            if (strcmp (campo, "author") == 0){
                scanf ("%*[author = {] %[^}]s %*[,]", entradas[i].author);
            }else if (strcmp (campo, "title") == 0){
                scanf ("%*[title = {] %[^}]s %*[,]", entradas[i].title);
            }else if (strcmp (campo, "journal") == 0){
                scanf ("%*[journal = {] %[^}]s %*[,]", entradas[i].journal);
            }else if (strcmp (campo, "year") == 0){
                scanf ("%*[year = {] %[^}]s %*[,]", entradas[i].year);
            }else if (strcmp (campo, "volume") == 0){
                scanf ("%*[volume = {] %[^}]s %*[,]", entradas[i].volume);
            }else if (strcmp (campo, "number") == 0){
                scanf ("%*[number = {] %[^}]s %*[,]", entradas[i].number);
            }else if (strcmp (campo, "pages") == 0){
                scanf ("%*[pages = {] %[^}]s %*[,]", entradas[i].pages);
            }
        /* Mantem a leitura ate que a chave que contem tal referencia seja fechada */  
        }while (strcmp(campo, "}"));
    }
}

/* Parte do Insertion Sort, insere uma estrutura numa serie ordenada delas */
void insereValor(int inicio, Article entradas[]){
    
    int i;
    
    Article temp = entradas[inicio];
    
    for (i = inicio - 1; (i >= 0) && (strcmp(entradas[i].title, temp.title) > 0); i--)
        entradas[i + 1] = entradas[i];
    
    entradas[i + 1] = temp;
}

/* Ordena lexicalmente as estruturas pelo Insertion Sort */
void ordenaLexic(int nEntradas, Article entradas[]){
    
    int i;
    
    for (i = 1; i < nEntradas; i++)
        insereValor(i, entradas);
}

/* Coloca o caracter '\0' em todas linhas da referencia, eh usado para otimizar as operacoes realizadas */
void zeraEntradas(int nEntradas, Article entradas[]){
    
    /* Declara uma estrutura "zerada" */
    int i;
    Article zerado = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    
    /* Iguala todas a essa anterior */
    for (i = 0; i < nEntradas; i++)
        entradas[i] = zerado;
}

/* Imprime as referencias com os dados corretamente posicionados */
void imprimeRefer(int nEntradas, Article entradas[]){
    
    int i;
    
    /* Imprime os valores opcionais apenas se eles existirem */
    for (i = 0; i < nEntradas; i++){
        printf ("%s, %s, %s", entradas[i].title, entradas[i]. author, entradas[i].journal);
        if (entradas[i].volume[0] != '\0')
            printf (", %s", entradas[i].volume);
        if (entradas[i].number[0] != '\0')
            printf (", %s", entradas[i].number);
        if (entradas[i].pages[0] != '\0')
            printf (", %s", entradas[i].pages);
        if (entradas[i].year[0] != '\0')
            printf (", %s", entradas[i].year);
        printf (".\n\n");
    }
}
