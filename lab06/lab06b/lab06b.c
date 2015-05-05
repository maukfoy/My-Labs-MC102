/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 06b - Fruit Crush Saga - Part II */

#include <stdio.h>
#define MAX 51

int main() {
    
    /* Declaracao das variaveis utilizadas */
    int i, j, aponta, jogada, fruta_escolhida, direcao, score, final_score = 0;
    int m_linhas, n_colunas, i_joglinha, j_jogcoluna, q_jogadas;
    char tabuleiro[MAX][MAX];
    
    /* Obtem os a quantidade de jogadas e o tamanho e composicao do tabuleiro */
    scanf ("%d %d %d", &m_linhas, &n_colunas, &q_jogadas);
    
    for (i = 0; i < m_linhas; i++)
           scanf ("%s", tabuleiro[i]);
    
    /* Laco que se repetira tantas vezes quantas jogadas forem feitas   */
    for (jogada = 0; jogada < q_jogadas; jogada++){
        
    /* Obtem as coordenadas da jogada e prepara tais variaveis para uso */
        scanf("%d %d", &i_joglinha, &j_jogcoluna);            
        i_joglinha--;
        j_jogcoluna--;
        
    /* Verifica se ha fruta na casa selecionada para realizar jogada */
        if (tabuleiro[i_joglinha][j_jogcoluna] != '.'){
    
    /* 'score' eh inicializada em -3 pois a posicao inicial eh contada
     * 4 vezes, sendo 3 delas redundantes */         
            fruta_escolhida = tabuleiro[i_joglinha][j_jogcoluna];
            score = -3;
            
    /* Marca com X as frutas a serem retiradas do tabuleiro */
            for (direcao = 0; direcao <= 3; direcao++){
                i = i_joglinha;
                j = j_jogcoluna;
                do {
                    tabuleiro[i][j] = 'X';
                    score++;
    /* Modifica 'i' e 'j' de acordo com a direcao */
                    i += (direcao == 2) - (direcao == 0);
                    j += (direcao == 3) - (direcao == 1);
                    
    /* Continua marcando com X caso a proxima fruta seja igual a fruta escolhida
     * e esteja dentro das dimensoes da matriz */
                }while ((tabuleiro[i][j] == fruta_escolhida) && (i >= 0) && 
                        (j >= 0) && (i < m_linhas) && (j < n_colunas));
            }
            
    /* Retira as frutas marcadas e desce as frutas acima de suas posicoes */ 
            for (j = 0; j < n_colunas; j++)
                for (i = 0; i < m_linhas; i++)
                    if (tabuleiro[i][j] == 'X'){
                        for (aponta = i; aponta > 0; aponta--)
                            tabuleiro[aponta][j] = tabuleiro[aponta-1][j];  
                        tabuleiro[0][j] = '.';
                    }
                    
    /* Contabiliza a pontuacao da jogada e a pontuacao final ate o momento */
            score *= score;
            final_score += score;
        }
    }
    
    /* Imprime na tela o estado e a pontuacao final do tabuleiro */
    printf ("Score: %d\n", final_score);
    
    for (i = 0; i < m_linhas; i++)
            printf ("%s\n", tabuleiro[i]);
    
    return 0;
}