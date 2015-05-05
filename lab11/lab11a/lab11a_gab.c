/* Laboratorio 11a: Copa do Mundo
 * Autor: Filipe de Oliveira Costa.
 * E-mail: filipe.costa@ic.unicamp.br
 */

#include <stdio.h>
#include <string.h>

/* Tamanho maximo de um nome de time */
#define MAXNOMETIME 16
/* Numero de times */
#define MAXTIMES 32
/* Numero de grupos */
#define NGRUPOS 8
/* Numero de times por grupo */
#define NTIMES 4
/* Total de partidas da primeira fase */
#define TOTALJOGOS 48

struct Time {
    char nome[MAXNOMETIME];
    int pontos;
    int gols_feitos;
    int gols_sofridos;
};

typedef struct Time Time;

struct Grupo {
    /* Numero de times */
    int num_times;
    Time times[NTIMES];
};

typedef struct Grupo Grupo;

/* Atualiza os atributos de um grupo */
void atualizaGrupo(Grupo *G, char nome_time[], 
                   int gols_feitos, int gols_sofridos) {
    int i;
    /* Indice do time: -1 caso o time ainda nao esteja na tabela dos grupos */
    int id = -1;
    int pontos = 0;
    
    /* Tenta encontrar a posicao (id) do time */
    for (i = 0; i < G->num_times && id == -1; i++) {
        if (strcmp(nome_time, G->times[i].nome) == 0)
            id = i;
    }

    /* Calcula numero de pontos e verifica se ocorreu vitoria do time */
    if (gols_feitos > gols_sofridos)
        pontos = 3;
    else if (gols_feitos == gols_sofridos)
        pontos = 1;

    /* Verifica se o time ja esta na tabela */
    if (id == -1) {
        /* Adiciona o time */
        id = G->num_times;
        G->num_times++;
        strcpy(G->times[id].nome, nome_time);
    }

    /* Atualiza os atributos do time */
    G->times[id].gols_feitos += gols_feitos;
    G->times[id].gols_sofridos += gols_sofridos;
    G->times[id].pontos += pontos;
}

/* Determina qual dos dois times eh o maior,
 * ou seja, qual eh o mais bem classificado.
 */ 
int eh_maior(Time t1, Time t2) {
    int saldo_gols_t1 = t1.gols_feitos - t1.gols_sofridos;
    int saldo_gols_t2 = t2.gols_feitos - t2.gols_sofridos;

    if (t1.pontos > t2.pontos)
        return 1;
    else if (t1.pontos == t2.pontos) {
        if (saldo_gols_t1 > saldo_gols_t2)
            return 1;
        else if (saldo_gols_t1 == saldo_gols_t2) {
            if (t1.gols_feitos > t2.gols_feitos)
                return 1;
            else if (t1.gols_feitos == t2.gols_feitos) {
                if (strcmp(t1.nome, t2.nome) < 0)
                    return 1;
            }
        }
    }
    return 0;
}

void troca(Time *t1, Time *t2) {
    Time aux;
    aux = *t1;
    *t1 = *t2;
    *t2 = aux; 
}

/* Ordena o vetor dos times por selection sort */
void ordenaGrupos(Grupo *G) {
    int i, j, id_max_time;

    for (i = 0; i < G->num_times; i++) {
        id_max_time = i;
        for (j = i + 1; j < G->num_times; j++) {
            if (eh_maior(G->times[j], G->times[id_max_time])) {
                id_max_time = j;
            }
        }
        troca(&G->times[i], &G->times[id_max_time]);
    }
}

int main() {
    /* Numero de jogos */
    int i, j;
    /* Tabela de classificacao: armazena os atributos dos times */
    Grupo G[NGRUPOS];
    /* Resultados de um jogo */
    int id_grupo;
    char nome_time1[MAXNOMETIME], nome_time2[MAXNOMETIME];
    int gols1, gols2;
    
    /* Inicializa os grupos e a tabela de classificacao */
    for (i = 0; i < NGRUPOS; i++) {
        G[i].num_times = 0;
        for (j = 0; j < NTIMES; j++) { 
            G[i].times[j].nome[0] = '\0';
            G[i].times[j].pontos = 0;
            G[i].times[j].gols_feitos = 0;
            G[i].times[j].gols_sofridos = 0;
        }
    }
    
    /* Atualiza os atributos dos times em cada grupo */ 
    id_grupo = 0;
    for (i = 0; i < TOTALJOGOS; i++) {
        if ((i % 6) == 0)
            id_grupo++;
        scanf("%s %d x %d %s", nome_time1, &gols1, &gols2, nome_time2);
        atualizaGrupo(&G[id_grupo - 1], nome_time1, gols1, gols2);
        atualizaGrupo(&G[id_grupo - 1], nome_time2, gols2, gols1);
    }
    
    /* Ordena os times dentro de cada grupo de acordo com sua classificacao */
    for (i = 0; i < NGRUPOS; i++)
        ordenaGrupos(&G[i]); 
    
    /* Saida: Impressao da classificacao geral apos a primeira fase */
    for (i = 0; i < NGRUPOS; i++) {
        printf("Grupo %c:\n", 'A' + i);
        for (j = 0; j < NTIMES; j++) {
            printf("%-15s %3d %3d %3d %3d\n", G[i].times[j].nome,
                G[i].times[j].pontos,
                G[i].times[j].gols_feitos,
                G[i].times[j].gols_sofridos,
                G[i].times[j].gols_feitos - G[i].times[j].gols_sofridos);
        }
        printf("\n");
    }

    /* Saida: Partidas das oitavas de final, da seguinte forma:
     * 1o Grupo 1 x 2o Grupo 2
     * 1o Grupo 2 x 2o Grupo 1
     * 1o Grupo 3 x 2o Grupo 4
     * 1o Grupo 4 x 2o Grupo 3
     * 1o Grupo 5 x 2o Grupo 6
     * 1o Grupo 6 x 2o Grupo 5
     * 1o Grupo 7 x 2o Grupo 8
     * 1o Grupo 8 x 2o Grupo 7 */

    printf("Oitavas de final:\n");
    for (i = 0; i < NGRUPOS; i = i + 2) {
        printf("%15s x %s\n", G[i].times[0].nome, G[i + 1].times[1].nome);
        printf("%15s x %s\n", G[i + 1].times[0].nome, G[i].times[1].nome);
    }

    return 0;
}