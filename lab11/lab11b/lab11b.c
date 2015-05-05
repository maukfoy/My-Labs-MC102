/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 11b - BibTeX */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaracao da estrutura de dados de cada referencia */
struct Article {
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
    char campo[8], *aponta;
    
    /* Le os dados de cada estrutura */
    for (i = 0; i < nEntradas; i++){
        /* Descarta cada label lido */
        scanf ("%*[^,]");
        do{
            /* Le o campo que a informacao seguinte sera inserido */
            scanf ("%s", campo);
            /* Armazena em 'aponta' o endereco do campo correspondente */
            if (strcmp (campo, "author") == 0){
                aponta = entradas[i].author;
            }else if (strcmp (campo, "title") == 0){
                aponta = entradas[i].title;
            }else if (strcmp (campo, "journal") == 0){
                aponta = entradas[i].journal;
            }else if (strcmp (campo, "year") == 0){
                aponta = entradas[i].year;
            }else if (strcmp (campo, "volume") == 0){
                aponta = entradas[i].volume;
            }else if (strcmp (campo, "number") == 0){
                aponta = entradas[i].number;
            }else if (strcmp (campo, "pages") == 0){
                aponta = entradas[i].pages;
            }
            /* Le a informacao seguinte no campo cujo endereco esta em 'aponta' */
            scanf ("%*[= {] %[^}]s %*[,]", aponta);
        /* Mantem a leitura ate que a referencia seja fechada com '}' */  
        }while (strcmp(campo, "}"));
    }
}

/* Parte do Insertion Sort, insere uma estrutura numa serie ordenada delas */
void insereValor(int inicio, Article entradas[]){
    
    int i;
    
    Article temp = entradas[inicio];
    
    /* Desloca todas posicoes maiores lexicalmente para a direita */
    for (i = inicio - 1; (i >= 0) && (strcmp(entradas[i].title, temp.title) > 0); i--)
        entradas[i + 1] = entradas[i];
    
    /* Insere a referencia na posicao correta */
    entradas[i + 1] = temp;
}

/* Ordena lexicalmente as estruturas pelo Insertion Sort */
void ordenaLexic(int nEntradas, Article entradas[]){
    
    int i;
    
    /* Ordena um vetor de referencias lexicalmente */
    for (i = 1; i < nEntradas; i++)
        insereValor(i, entradas);
}

/* Coloca o caracter '\0' em todas linhas da referencia, eh usado para otimizar as operacoes realizadas */
void zeraEntradas(int nEntradas, Article entradas[]){
    
    /* Declara uma estrutura "zerada" */
    int i;
    Article zerado = {"\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    
    /* Iguala todas entradas a zerada */
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
        printf (", %s.\n\n", entradas[i].year);
    }
}
