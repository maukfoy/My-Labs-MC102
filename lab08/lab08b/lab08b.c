/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 08b - Processamento de imagens */

/* lab12: Processamento de imagens
 * Autor: Filipe de Oliveira Costa.
 * E-mail: filipe.costa@ic.unicamp.br
 */

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario.
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO                       */
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

/* Escreve a imagem em formato pgm na saida padrao 
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO               */
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

/* negativo: Recebe uma imagem de entrada e gera o negativo da mesma */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
    /* Declaracao das variaveis */
	int i, j;
    
	/* A intensidade de cada pixel da imagem é invertida */
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++)
            img[i][j] = MaxV - img[i][j];
}

/* rotacao180: Rotaciona uma imagem de entrada em 180 graus */
void rotacao180(int img[][MAX_TAM], int W, int H) {
    /* Declaracao das variaveis */
	int i, j, temp;
    
	/* Inverte a imagem em relacao a vertical */
    for (i = 0; i < H; i++)
        for (j = 0; j < (W/2); j++){
            temp = img[i][j];
            img[i][j] = img[i][W-j-1];
            img[i][W-j-1] = temp;
        }
    
	/* Inverte a imagem em relacao a horizontal */
	for (i = 0; i < (H/2); i++)
        for (j = 0; j < W; j++){
            temp = img[i][j];
            img[i][j] = img[H-i-1][j];
            img[H-i-1][j] = temp;
        }
}

/* detectaBorda: Aplica aos pixels da imagem o algoritmo de deteccao de borda*/
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
    /* Declaracao das variaveis e matriz auxiliar */
	int i, j;
    int aux[MAX_TAM][MAX_TAM];
    
	/* Copia a imagem de entrada para usa-la como referencia */
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++)
            aux[i][j] = img[i][j];
    
	/* Aplica aos pixels internos o algoritmo, alterando suas intensidades */	
    for (i = 1; i < (H-1); i++){
        for (j = 1; j < (W-1); j++){
            img[i][j] = - aux[i-1][j-1] - aux[i-1][j+1]
                        - aux[i+1][j-1] - aux[i+1][j+1] + 
                   4 * (- aux[i+1][j]   - aux[i-1][j]
                        - aux[i][j+1]   - aux[i][j-1]) + 
                        20 * aux[i][j];
            if (img[i][j] > MaxV)
                img[i][j] = MaxV;
            else if (img[i][j] < 0)
                img[i][j] = 0;
        }
    }
}

/* cisalhamento: Deforma linearmente as imagens */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) {
    /* Declaracao das variaveis e matriz auxiliar */
	int i, j, x_linha, y_linha;
    int aux[MAX_TAM][MAX_TAM];
    
	/* Copia a imagem de entrada para uma auxiliar e prepara a saida */
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++) {
            aux[i][j] = img[i][j];
            img[i][j] = 0;
        }
    
	/* Desloca os pixels de acordo com os valores de cisalhamento fornecidos */	
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++){
            y_linha = i + (Py * j);
            x_linha = j + (Px * i);
            if ((y_linha <= H) && (x_linha <= W))
                img[y_linha][x_linha] = aux[i][j];
        }
}


/* VOCE NAO DEVE ALTERAR A FUNCAO PRINCIPAL */
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
