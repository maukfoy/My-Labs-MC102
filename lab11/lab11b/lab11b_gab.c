/***********************************************************
 * Created: Sab 19 Abr 2014 11:00:08 BRT
 *
 * Author: Carla N. Lintzmayer, carlanl@ic.unicamp.br
 * Laboratorio 11b: BibTeX
 *
 ***********************************************************/
 
#include <stdio.h>
#include <string.h>

#define MAX_ENTRADAS 100
#define MAX_CONTEUDO 500
#define MAX_CAMPO 7

struct entrada {
    /* Campos obrigatorios: */
    char author[501], title[501], journal[101];
    char year[51];
    /* Campos opcionais: */
    char volume[51], number[51], pages[21];
};
typedef struct entrada entrada_t;

/* Prototipos de funcoes: apenas as utilizadas pela main() */
void le_entrada(entrada_t *entrada);
void ordena_bibliografia(entrada_t entrada[], int n);
void imprime_entrada(entrada_t entrada);

int main(void) {
    entrada_t entrada[MAX_ENTRADAS];
    int i, qtd_entradas;
    char lixo;

    /* Leitura da quantidade de entradas e de cada uma delas: um % seguido de um
     * espaco, um numero e duas quebras de linha */
    scanf("%c %d\n\n", &lixo, &qtd_entradas);
    for (i = 0; i < qtd_entradas; i++)
        le_entrada(&entrada[i]);

    ordena_bibliografia(entrada, qtd_entradas);

    /* Impressao da saida: referencias bibliograficas ordenadas */
    for (i = 0; i < qtd_entradas; i++)
        imprime_entrada(entrada[i]);

    return 0;
}

/* Faz leitura de um conteudo: salva em "cont" qualquer caractere ate que um 
 * '}' seja encontrado */
void le_conteudo(char cont[]) {
    int i = 0;

    do {
        scanf("%c", &cont[i++]);
    } while (cont[i-1] != '}');

    cont[i-1] = '\0';
}

/* Faz leitura do conteudo dos campos de uma unica entrada */
void le_entrada(entrada_t *entrada) {
    char campo[MAX_CAMPO + 1], conteudo[MAX_CONTEUDO + 1], lixo, c;

    /* Inicializando campos opcionais -- se nao forem lidos, ficarao vazios */
    entrada->volume[0] = '\0';
    entrada->number[0] = '\0';
    entrada->pages[0] = '\0';

    /* Le e ignora uma linha da forma "article{label,\n"
     * O %s le ate a virgula e o \n eh lido pelo %c */
    scanf("%s%c", conteudo, &lixo);

    /* Laco para ler linhas da forma " campo = {conteudo},\n"
     * Para quando encontra uma linha contendo apenas '}'
     * Como cada linha comeca com um espaco em branco, o condicional do while se
     * encarrega de desconsidera-lo: ou vai ser um espaco ou vai ser um '}' */
    scanf("%c", &c);
    while (c != '}') {
        scanf("%s = {", campo);
        le_conteudo(conteudo);

        /* Le a virgula e o \n que restam apos um '}' */
        scanf("%c", &lixo);
        scanf("%c", &lixo);

        /* Descobre o tipo do campo e atribui a ele o conteudo lido */
        if (!strcmp(campo, "author"))
            strcpy(entrada->author, conteudo);
        else if (!strcmp(campo, "title"))
            strcpy(entrada->title, conteudo);
        else if (!strcmp(campo, "journal"))
            strcpy(entrada->journal, conteudo);
        else if (!strcmp(campo, "year"))
            strcpy(entrada->year, conteudo);
        else if (!strcmp(campo, "volume"))
            strcpy(entrada->volume, conteudo);
        else if (!strcmp(campo, "number"))
            strcpy(entrada->number, conteudo);
        else if (!strcmp(campo, "pages"))
            strcpy(entrada->pages, conteudo);

        /* Faz leitura do primeiro caractere da proxima linha, que pode ser um
         * espaco em branco ou o fim da entrada (um }) */
        scanf("%c", &c);
    }

    /* Le os dois '\n' que existem apos uma entrada:
     * um depois do } e um entre essa entrada e a proxima */
    scanf("%c", &lixo);
    scanf("%c", &lixo);
}

/* Faz a impressao de uma estrutura entrada_t */
void imprime_entrada(entrada_t entrada) {
    printf("%s, %s, %s, ", entrada.title, entrada.author, entrada.journal);
    if (entrada.volume[0] != '\0')
        printf("%s, ", entrada.volume);
    if (entrada.number[0] != '\0')
        printf("%s, ", entrada.number);
    if (entrada.pages[0] != '\0')
        printf("%s, ", entrada.pages);
    printf("%s.\n\n", entrada.year);
}

/* Ordena o vetor de entradas pelo campo title com insertion sort */
void ordena_bibliografia(entrada_t entrada[], int n) {
    int i, j;
    entrada_t aux;

    for (i = 1; i < n; i++) {
        aux = entrada[i];

        for (j = i-1; j >= 0 && strcmp(entrada[j].title, aux.title) > 0; j--)
            entrada[j+1] = entrada[j];

        entrada[j+1] = aux;
    }
}
