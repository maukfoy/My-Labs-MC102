/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 14b - Liber8 */

#include <stdio.h>
#include <stdlib.h>

/* Simula as explosoes das bombas e indica os locais afetados com 'x' e as bombas com 'B' */
void simulaExplosao(int nLinhas, int nColunas, int linBomba, 
                    int colBomba, char **mapa){
    
    /* Encontra o raio da explosao da bomba na posicao indicada*/
    int i, j, raioBomba = mapa[linBomba][colBomba] - '0';
    
    /* Indica o local da bomba com 'B' */
    mapa[linBomba][colBomba] = 'B';
    
    /* Marca a area afetada pela explosao dentro do mapa 'x', se houver 
     * alguma bomba nessa area, simula sua explosao tambem no mapa */
    for (i = linBomba - raioBomba; i <=  linBomba + raioBomba; i++)
        for (j = colBomba - raioBomba; j <= colBomba + raioBomba; j++)
            if (i >= 0 && i < nLinhas && j >= 0 && j < nColunas){
                if (mapa[i][j] == '.')
                    mapa[i][j] = 'x';
                
                else if (mapa[i][j] >= '0' && mapa[i][j] <= '9')
                    simulaExplosao(nLinhas, nColunas, i, j, mapa);
            }

    return;
}

/* Le estado do mapa antes das explosoes da entrada */
void leMapa(int nLinhas, char **mapa){
    
    int i;
    
    for (i = 0; i < nLinhas; i++)
        scanf("%s", mapa[i]);
    
    return;
}

/* Aloca uma matriz que armazena as informacoes do mapa 
 * antes e depois das explosoes das bombas do Liber8 */
char **alocaMapa(int nLinhas, int nColunas){
    
    int i;
    char **mapa;
    
    /* Aloca um vetor de ponteiros para caracteres */
    mapa = malloc(nLinhas * sizeof(char *));
    
    /* Aloca um vetor em cada ponteiro do anterior, constituindo uma matriz */
    for (i = 0; i < nLinhas; i++)
        mapa[i] = malloc(nColunas + 1 * sizeof(char));
    
    /* Retorna o endereco do ponteiro diretor da matriz */
    return mapa;
}

/* Funcao que imprime o estado do mapa no momento que eh invocada */
void imprimeMapa(int nLinhas, char **mapa){
    
    int i;
    
    for (i = 0; i < nLinhas; i++)
        printf("%s\n", mapa[i]);
    
    return;
}

void liberaMapa(int nLinhas, char **mapa){
    
    int i;
    
    for (i = 0; i < nLinhas; i++)
        free(mapa[i]);
    
    free(mapa);
    
    return;
}

int main() {
    
    int nLinhas, nColunas, linBomba, colBomba;
    char **mapa;
    
    /* Obtem os dados do mapa e coordenadas da primeira bomba */
    scanf("%d %d %d %d", &nLinhas, &nColunas, &linBomba, &colBomba);
    
    /* Aloca a matriz que armazenara o mapa */
    mapa = alocaMapa(nLinhas, nColunas);
    
    /* Le o mapa da entrada */
    leMapa(nLinhas, mapa);
    
    /* Simula as explosoes */
    simulaExplosao(nLinhas, nColunas, linBomba - 1, colBomba - 1, mapa);
    
    /* Imprime o estado do mapa apos a simulacao */
    imprimeMapa(nLinhas, mapa);
    
    /* Libera a memoria alocada para o mapa */
    liberaMapa(nLinhas, mapa);
    
    return 0;
}
