/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 09a - Oliver Queen is alive! */

#include <stdio.h>
#define MAX 30

int main() {
    
    /* Declaracao das variaveis e matriz utilizada */
    int i, j, passos = 0, direcao = 0, flag_end = 0;
    int max_dim, tempo;
    int mapa[MAX][MAX];
    
    /* Obtencao dos dados de tempo, dimensao e terreno da sala */
    scanf ("%d %d", &max_dim, &tempo);
    
    for (i = 0; i < max_dim; i++)
        for (j = 0; j < max_dim; j++)
            scanf ("%d", &mapa[i][j]);
    
    /* Inicializacao da posicao */    
    i = 0;
    j = 0;
    
    /* Simula a missao ate encontrar um ponto de parada */
    while (flag_end == 0){
        
    /* Dependendo da cor da casa, vira a direita, esquerda ou nao vira */
        if (mapa[i][j] == 1)
            (direcao == 3) ? (direcao = 0) : (direcao++);
        
        else if (mapa[i][j] == 2)
            (direcao == 0) ? (direcao = 3) : (direcao--);
    
    /* Muda a cor da casa de acordo com a cor atual */
        mapa[i][j] = (mapa[i][j] + 1) % 3;
        
    /* Anda na direcao apontada pela variavel 'direcao':
     * 0 = leste - 1 = norte - 2 = oeste - 3 = sul */    
        i += (direcao == 3) - (direcao == 1);
        j += (direcao == 0) - (direcao == 2);
    
    /* Incrementa a quantidade de passos a cada movimento realizado */   
        passos++;
    
    /* Verifica se a simulacao acabou, caso sim, indica o motivo em 'flag_end'*/
        if (mapa[i][j] == 4)
            flag_end = 1;
        
        else if (i < 0 || j < 0 || i > (max_dim-1) || j > (max_dim-1) ||
                 mapa[i][j] == 3)
            flag_end = 2;
        
        else if (passos == tempo-1)
            flag_end = 3;
    }
    
    /* Imprime na tela o resultado da simulacao em 'flag_end' */
    if (flag_end == 1)
        printf ("Oliver destroi o dispositivo em %d segundos\n", passos);
    
    else if (flag_end == 2)
        printf ("Oliver morre\n");
    
    else if (flag_end == 3)
        printf ("Oliver nao chega ao dispositivo a tempo\n");
               
    return 0;
}