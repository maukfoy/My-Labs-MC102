/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 11a - Copa do Mundo */

/* Biliotecas utilizadas */
#include <stdio.h>
#include <string.h>

/* Define a quantidade de jogos, times e grupos da competicao */
#define JOGOS 48
#define TIMES 32
#define GRUPOS 8

/* Define um registro Time com todos dados relevantes a cada time */
struct Time {
    char nome[16];
    int pontos;
    int golsFeitos;
    int golsSofridos;
    int saldoGols;
};

typedef struct Time Time;

/* Define um registro de uma string auxiliar */
struct String {
    char string[16];
};

typedef struct String String;

/* Le todos os dados da entrada e armazena para uso */
void le_dados(String times_scan[][2], int result_scan[][2]){
    
    int i;
    
    for (i = 0; i < JOGOS; i++)
        scanf("%s %d x %d %s", times_scan[i][0].string, &result_scan[i][0],
                               &result_scan[i][1], times_scan[i][1].string);
}

/* Inicializa todos as posicoes de cada Time zerados */
void reseta_times(Time grupos_times[][TIMES/GRUPOS]){
    
    /* Declara um Time zerado */
    Time zero = {"vazio", 0, 0, 0, 0};
    int i, j;
    
    /* Iguala todos times ao time zerado */
    for (i = 0; i < GRUPOS; i++)
        for (j = 0; j < (TIMES/GRUPOS); j++)
            grupos_times[i][j] = zero;
}

/* Organiza os dados de cada time de acordo com os dados lidos */
void organiza_dados(Time grupos_times[][TIMES/GRUPOS], String times_scan[][2],
                    int result_scan[][2]){
    
    int i, j, k, l, flag;
   
    for (i = 0; i < JOGOS; i++)
        for (j = 0; j < 2; j++){
            flag = 0;
            for (k = 0; k < GRUPOS && flag == 0; k++)
                for (l = 0; l < (TIMES/GRUPOS) && flag == 0; l++)
                    if (strcmp(times_scan[i][j].string, grupos_times[k][l].nome) == 0 || strcmp(grupos_times[k][l].nome, "vazio") == 0){
                        strcpy(grupos_times[k][l].nome, times_scan[i][j].string);
                        if (result_scan[i][j] > result_scan[i][(j == 0)])
                            grupos_times[k][l].pontos += 3;
                        else if (result_scan[i][j] == result_scan[i][(j == 0)])
                            grupos_times[k][l].pontos += 1;
                        grupos_times[k][l].golsFeitos += result_scan[i][j];
                        grupos_times[k][l].golsSofridos += result_scan[i][(j == 0)];
                        grupos_times[k][l].saldoGols =
                        (grupos_times[k][l].golsFeitos -
                         grupos_times[k][l].golsSofridos);
                        flag = 1;
                    }
        }
}

/* Imprime a tabela final e os jogos das oitavas de final */
void imprime_tabela(Time grupos_times[][TIMES/GRUPOS]){
    
    int i, j;
    
    /* Imprime os nomes dos grupos */
    for (i = 0; i < GRUPOS; i++){
        printf ("Grupo %c:\n", 'A'+i);
        
        /* Imprime os times e os dados relativos a cada um */
        for (j = 0; j < (TIMES/GRUPOS); j++)
            printf ("%-15s %3d %3d %3d %3d\n", grupos_times[i][j].nome,
                    grupos_times[i][j].pontos, grupos_times[i][j].golsFeitos,
                    grupos_times[i][j].golsSofridos, grupos_times[i][j].saldoGols);
        printf ("\n");
    }
    
    /* Imprime os jogos das oitavas de final */
    printf ("Oitavas de final:\n");
    
    for (i = 0; i < GRUPOS; i += 2){
        printf ("%15s x %s\n", grupos_times[i][0].nome, grupos_times[i+1][1].nome);
        printf ("%15s x %s\n", grupos_times[i+1][0].nome, grupos_times[i][1].nome);

    }
}

/* Troca os valores de dois struct tipo Times dados */
void troca_times(Time *a, Time *b){
    
    Time aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
}

/* Encontra o indice do proximo time na ordenacao */
int indice_max(Time grupo[TIMES/GRUPOS], int inicio){
    
    int i, max = inicio;
    
    for (i = inicio + 1; i < (TIMES/GRUPOS); i++)
        /* Criterio dos pontos */
        if (grupo[max].pontos < grupo[i].pontos)
            max = i;
        else if (grupo[max].pontos == grupo[i].pontos){
            /* Criterio do saldo de gols */
            if (grupo[max].saldoGols < grupo[i].saldoGols)
                max = i;
            else if (grupo[max].saldoGols == grupo[i].saldoGols){
                /* Criterio de gols feitos */
                if (grupo[max].golsFeitos < grupo[i].golsFeitos)
                    max = i;
                else if (grupo[max].golsFeitos == grupo[i].golsFeitos)
                    /* Criterio da ordem alfabetica */
                    if (strcmp(grupo[max].nome, grupo[i].nome) > 0)
                        max = i;
            }
        }
    return max;
}

/* Ordena os times segundo os criterios estabelecidos pelo Selection Sort */
void ordena_times(Time grupos_times[][TIMES/GRUPOS]){
    
    int i, j, max;
    
    /* Implementacao do Selection Sort */
    for (i = 0; i < GRUPOS; i++)
        for (j = 0; j < (TIMES/GRUPOS); j++){
            max = indice_max(grupos_times[i], j);
            troca_times(&grupos_times[i][j], &grupos_times[i][max]);
        }
}

/* Loop principal do programa */
int main(){
   
    /* Declaracao de variaveis */
    Time grupos_times[GRUPOS][TIMES/GRUPOS];
    String times_scan[JOGOS][2];
    int result_scan[JOGOS][2];
    
    /* Programa principal com funcoes auxiliares */
    le_dados(times_scan, result_scan);
    reseta_times(grupos_times);
    organiza_dados(grupos_times, times_scan, result_scan);
    ordena_times(grupos_times);
    imprime_tabela(grupos_times);
    
    return 0;
}
