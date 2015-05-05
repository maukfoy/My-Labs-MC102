/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 07b - Modern Word Search */

#include <stdio.h>
#define LMAX 50
#define CMAX 51
#define PMAX 26

/* OBS: As funcoes testa_vogal e verifica poderiam nao ser usadas para fins de 
 * otimizacao de codigo, no entanto, seu uso torna o codigo mais inteligivel */
int testa_vogal (int letra);
int verifica (int i, int j, char palavra[], char caca[LMAX][CMAX], char final_caca[LMAX][CMAX]);

int main () {
    
/* Declara as variaveis da funcao 'main' */
    int i, j, ocorrencias = 0;
    int n_linhas, m_colunas;
    char palavra[PMAX], caca[LMAX][CMAX], final_caca[LMAX][CMAX];
    
/* Obtem as informacoes e a propria matriz do caca palavras e a palavra a ser procurada */
    scanf ("%d %d %s", &n_linhas, &m_colunas, palavra);
    
/* Escreve "." em todas posicoes uteis da matriz de saida */
    for (i = 0; i < n_linhas; i++){
        scanf ("%s", caca[i]);
        for (j = 0; j < m_colunas; j++)
            final_caca[i][j] = '.';
    }

/* Verifica se cada caracter da matriz corresponde ao primeiro da palavra, se sim, invoca
 * a funcao que verifica a correspondencia completa da palavra */
    for (i = 0; i < n_linhas; i++)
        for (j = 0; j < m_colunas; j++)
            if ((caca[i][j] == palavra[0]) || (caca[i][j] == '_')  ||
                ((caca[i][j] == '#') && (testa_vogal(palavra[0]))) ||
                ((caca[i][j] == '%') && !(testa_vogal(palavra[0]))))
                ocorrencias += verifica (i, j, palavra, caca, final_caca);

/* Imprime a palavra procurada, a quantidade de ocorrencias e a matriz final com as ocorrencias */
    printf ("%s %d\n", palavra, ocorrencias);
    for (i = 0; i < n_linhas; i++, printf("\n"))
        for (j = 0; j < m_colunas; j++)
            printf ("%c", final_caca[i][j]);
        
    return 0;
}

/* Funcao retorna 1 se a entrada for vogal e 0 se nao for */
int testa_vogal (int letra) {
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}
   
/* Funcao retorna a quantidade de ocorrencias da palavra a partir de uma coordenada
 * da matriz nas 3 possiveis direcoes. Escreve as ocorrencias na matriz de saida,
 * deixando o resto com "." */
int verifica (int i, int j, char palavra[], char caca[LMAX][CMAX], char final_caca[LMAX][CMAX]){
        
        int k, i_comp, j_comp, direcao, match, ocorrencias = 0;
        char letra;
        
        for (direcao = 0; direcao <= 2; direcao++){
            match = 1;
            i_comp = 0;
            j_comp = 0;
            for (k = 0; (palavra[k] != '\0') && (match == 1); k++){
                letra = caca[i + i_comp][j + j_comp];
    /* Verifica se cada caracter corresponde aos da palavra a ser procurada, se nao
         * corresponder, a flag 'match' eh usada para indicar isso */
                if ((letra != '_') &&
                    !(((letra == '#') && (testa_vogal(palavra[k])))   ||
                    ((letra == '%') && !(testa_vogal(palavra[k])))) &&
                    (letra != palavra[k]))
                    match = 0;
    /* Incrementa as variaveis que apontam para os locais da matriz */
                    i_comp += (direcao == 0) + (direcao == 2);
                    j_comp += (direcao == 1) + (direcao == 2);
        }
    /* Se o motivo da parada foi a correspondencia entre palavra e parte da matriz,
     * os caracteres correspondentes sao copiados na matriz de saida */
        if ((palavra[k] == '\0') && (match == 1)){
            ocorrencias++;
            i_comp = 0;
            j_comp = 0;
    /* Copia os caracteres e incrementa condicionalmente as variaveis 
     * que apontam para a matriz */
            for (k = 0; palavra[k] != '\0'; k++){
                final_caca[i + i_comp][j + j_comp] = caca[i + i_comp][j + j_comp];
                i_comp += (direcao == 0) + (direcao == 2);
                j_comp += (direcao == 1) + (direcao == 2);
            }
        }
    }
    return ocorrencias;
}