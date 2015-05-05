/***********************************************************
 * Created: Sab 19 Abr 2014 11:00:08 BRT
 *
 * Author: Carla N. Lintzmayer, carlanl@ic.unicamp.br
 * Laboratorio 12a: CUT++
 *
 ***********************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMEARQ 101
#define MAX_CELULA 501
#define DELIMITADOR ','

/* Prototipo das funcoes utilizadas pela main */
void gera_csv_reduzido(char fnamein[], char fnameout[]);

int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];

    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    return 0;
}

/* Gera arquivo csv a partir de um arquivo de entrada, contendo apenas as 
 * colunas requeridas */
void gera_csv_reduzido(char fnamein[], char fnameout[]) {
    FILE *fin, *fout;
    char c, **linha;
    int total_colunas = 0, *colunas_requeridas;
    int i, coluna, num_colunas_requeridas;

    fin = fopen(fnamein, "r");
    fout = fopen(fnameout, "w");

    /* Primeiro descobre a quantidade total de colunas que cada linha possui */
    do {
        do {
            fscanf(fin, "%c", &c);
        } while (c != DELIMITADOR && c != '\n');
        total_colunas++;
    } while (c != '\n');

    /* Alocando o tamanho de uma linha */
    linha = malloc(sizeof(char*) * total_colunas);
    for (i = 0; i < total_colunas; i++)
        linha[i] = malloc(sizeof(char) * MAX_CELULA);

    /* Lendo a quantidade de colunas que deverao ser mantidas, alocando espaco
     * para armazena-las e lendo quais sao essas colunas */
    scanf("%d", &num_colunas_requeridas);
    colunas_requeridas = malloc(sizeof(int) * num_colunas_requeridas);
    for (i = 0; i < num_colunas_requeridas; i++) {
        scanf("%d", &colunas_requeridas[i]);
        colunas_requeridas[i]--;
    }

    /* Voltando o ponteiro de leitura do arquivo de entrada para comecar a
     * impressao no arquivo final */
    rewind(fin);

    /* Para cada linha do arquivo de entrada: ler todas as colunas, salvando-as
     * e imprimir no arquivo de saida apenas as colunas requeridas */
    coluna = 0;
    while (fscanf(fin, "%c", &c) != EOF) {
        /* Le o conteudo de cada celula de uma certa linha */
        i = 0;
        while (c != DELIMITADOR && c != '\n') {
            linha[coluna][i++] = c;
            fscanf(fin, "%c", &c);
        }
        linha[coluna][i] = '\0';
        coluna++;

        /* Ao fim da linha, reiniciar indice que mantem as celulas (coluna) e
         * imprimir no arquivo de saida as colunas requeridas, na ordem dada */
        if (c == '\n') {
            coluna = 0;

            for (i = 0; i < num_colunas_requeridas-1; i++)
                fprintf(fout, "%s,", linha[colunas_requeridas[i]]);
            fprintf(fout, "%s\n", linha[colunas_requeridas[i]]);
        }
    }

    /* Liberando espaco da memoria */
    free(colunas_requeridas);
    for (i = 0; i < total_colunas; i++)
        free(linha[i]);
    free(linha);

    fclose(fin);
    fclose(fout);
}
