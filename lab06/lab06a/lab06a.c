/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 06a - Fruit Crush Saga - Part I */

#include <stdio.h>
#define MAX 51

int main() {
    
    /* Declaraca as variaveis */
    
    int i, j, fruta_escolhida, direcao, score = -3;
    int m_linhas, n_colunas, i_joglinha, j_jogcoluna;
    char tabuleiro[MAX][MAX];
    
    /* Obtem valores das variaveis a partir da entrada padrao */
    
    scanf ("%d %d %d %d", &m_linhas, &n_colunas, &i_joglinha, &j_jogcoluna);
    
    for (i = 0; i < m_linhas; i++)
           scanf ("%s", tabuleiro[i]);
    
    /* Prepara variaveis auxiliares:
     * A posicao da jogada feita eh decrementada para casar com sua
     * posicao real na matriz */
    
    i_joglinha--;
    j_jogcoluna--;
    fruta_escolhida = tabuleiro[i_joglinha][j_jogcoluna];
    
    /* Olha as posicoes adjacentes a posicao escolhida e altera seu valor
     * no tabuleiro para X caso seja uma fruta igual a da posicao inicial */
   
    for (direcao = 0; direcao <= 3; direcao++){
        i = i_joglinha;
        j = j_jogcoluna;
        do{ 
            tabuleiro[i][j] = 'X';
            
            /* A variavel score eh inicializada em -3 pois ela eh incrementada
             * sempre que a contagem se inicia da posicao escolhida e prossegue
             * em uma direcao, como sao 4 as direcoes adjacentes, o minimo de 
             * incrementos que ela sofrera serao 4, mesmo sem nenhuma fruta
             * igual adjacente, dessa forma, ao final da contagem, score estara
             * sempre maior ou igual a zero */
            
            score++;
            switch (direcao){
                case 0:
                    i--;
                    break;
                case 1:
                    j--;
                    break;
                case 2:
                    i++;
                    break;
                case 3:
                    j++;
                    break;
            }
        }while (tabuleiro[i][j] == fruta_escolhida);
    }
    
    /* Imprime na tela a pontuacao e o estado da matriz apos a jogada */
    
    printf ("Score: %d\n", score*score);
    
    for (i = 0; i < m_linhas; i++)
            printf ("%s\n", tabuleiro[i]);
    
    return 0;
}