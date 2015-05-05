/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 07a - The Voice - Blind Auditions */

#include <stdio.h>
#define MAX 100
#define TIMES 4

int main() {
    
    /* Declaracao das variaveis utilizadas */
    
    int i, j, part, jurado, time, vazio; 
    int n_part; 
    int esc_jurados[MAX][TIMES], pref_part[MAX][TIMES];
    
    /* Obtencao do numero e preferencia dos candidatos e escolha dos jurados
     * A preferencia e a escolha dos jurados sao armazenados em matrizes distintas */
    
    scanf ("%d", &n_part);
    
    for (i = 0; i < n_part; i++){
        for (j = 0; j < (TIMES); j++)
            scanf ("%d", &esc_jurados[i][j]);
        for (j = 0; j < (TIMES); j++)
            scanf ("%d", &pref_part[i][j]);
    }
    
    /* Coloca em 0 todas preferencias nao correspondidas pelos respectivos jurados.
     * Portanto, apos isso, o time do participante sera o primeiro valor diferente
     * de 0 em sua tabela de preferencias */
    
    for (part = 0; part < n_part; part++)
        for (jurado = 0; jurado < (TIMES); jurado++)
            if (esc_jurados[part][jurado] == 0)
                for (j = 0; j < (TIMES); j++)
                    if (pref_part[part][j] == (jurado + 1))
                        pref_part[part][j] = 0;                    

    /* Imprime na tela os participantes pertencentes a cada time, ou 'Nenhum participante'
     * caso o time nao possua participantes, cada time eh inicialmente vazio */                
                    
    for (time = 1; time <= (TIMES); time++){
        vazio = 1;
        printf ("Time %d:", time);
        for (part = 0; part < n_part; part++)
    /* Verifica cada linha para que cada participante perteca a apenas um time */
            for (j = 0; (j < TIMES) && ((pref_part[part][j] == 0) ||
                (pref_part[part][j] == time)); j++)
                if (pref_part[part][j] == time){
                    printf (" %d", part+1);
                    vazio = 0;
                    for (i = j; i < TIMES; i++)
                        pref_part[part][i] = 0;
                }
        if (vazio) printf (" Nenhum participante");
        printf ("\n");
    }
        
    return 0;
}