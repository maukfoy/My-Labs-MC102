/* Laboratório 08b: Processamento de imagens
 * Autor: Filipe de Oliveira Costa.
 * E-mail: fcosta@ic.unicamp.br
 */

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *Px, double *Py) {
    char nome_formato[3];
    char c;
    int i,j;

    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;

    /* Le o '#', que indica um comentario, e os numeros indicando
    * o filtro e o parametro, se houver */
    scanf("%[#]c", &c);
    scanf("%d", F);
    if (*F == 4) {
        scanf("%lf %lf", Px, Py);
    } 
 
    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);
 
    /* Le o valor de cada pixel da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }

    return 1;
}

/* Escreve a imagem em formato pgm na saida padrao */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");
    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pixels da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

/* Negativo */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;
    for (i = 0; i < H; i++ ) {
        for (j = 0; j < W; j++) {
            /* Invertendo valores dos pixels */
            img[i][j] = (MaxV - img[i][j]);
        }
    }
}

/* Rotacao de 180 graus */
void rotacao180(int img[][MAX_TAM], int W, int H) {
    int i, j;
    int aux;
    for (i = 0; i < H/2; i++ ) {
        for (j = 0; j < W; j++ ) {
            /* Troca P (i, j) com seu correspondente (H - i - 1,  W - j - 1) */
            aux = img[i][j];
            img[i][j] = img[H - i - 1][W - j - 1];
            img[H - i - 1][W - j - 1] = aux;
        }
    }
}

/* Deteccao de bordas */
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
    int aux[MAX_TAM][MAX_TAM]; 
    int i, j, fi, fj, soma;
    int filtro[3][3];

    /* Filtro */
    filtro[0][0] = -1;
    filtro[0][1] = -4;
    filtro[0][2] = -1;
    filtro[1][0] = -4;
    filtro[1][1] = 20;
    filtro[1][2] = -4;
    filtro[2][0] = -1;
    filtro[2][1] = -4;
    filtro[2][2] = -1;
 
    for (i = 1; i < H - 1; i++) {
        for (j = 1; j < W - 1; j++) {
            soma = 0;

            /* Filtrando o ponto (i,j) e seus vizinhos */
            for (fi = 0; fi <= 2; fi++)
                for (fj = 0; fj <= 2; fj++)
                    soma += (img[i + fi - 1][j + fj - 1] * filtro[fi][fj]);

            /* O pixel (i,j) passa ter a intensidade do filtro de realce */
            aux[i][j] = soma;
            
            /* Verificando se o valor do pixel está no intervalo [0..MaxV] */
            if (aux[i][j] > MaxV)
                aux[i][j] = MaxV;
            if (aux[i][j] < 0)
                aux[i][j] = 0; 
        }
    }

    /* Imagem Final */
    for (i = 1; i < H - 1; i++) { 
        for (j = 1; j < W - 1; j++) { 
            img[i][j] = aux[i][j];
        }
    }
}

/* Cisalhamento */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) { 
    int aux[MAX_TAM][MAX_TAM];
    int i, j;
    int novoI, novoJ;
 
    /* Inicializando matrix auxiliar */
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            aux[i][j] = 0;
        }
    }
 
    /* Cisalhamento */
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            /* Mudando posicao dos pixels */
            /* i = LINHA (EIXO Y) */
            novoI = (int) (i + Py * j);
            /* j = COLUNA (EIXO x) */
            novoJ = (int) (j + Px * i);
            if ((novoI < H) && (novoJ < W))
                aux[novoI][novoJ] = img[i][j];
        }
    }

    /* Imagem final */
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) { 
            img[i][j] = aux[i][j];
        }
    }
}

int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM]; 
    /* Atributos da imagem */
    int W, H, MaxV;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parametro a ser passado para o cisalhamento */
    double Px, Py;

    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &Px, &Py) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }
 
    /* Seleciona o filtro */
    switch (F) {
        case 1:
            negativo(img, W, H, MaxV);
            break;
        case 2:
            rotacao180(img, W, H);
            break;
        case 3:
            detectaBorda(img, W, H, MaxV);
            break;
        case 4:
            cisalhamento(img, W, H, Px, Py);
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}