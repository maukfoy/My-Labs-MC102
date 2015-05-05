/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 09b - Concurso Publico para Professor da UNICAMP */

#include <stdio.h>
#define MAX 30
#define MEM 5

/* Prototipos das funcoes utilizadas */
void calcula_media(int j, int num_cand, double medias[MAX], double notas[][MAX]);
void det_pref(int i, int num_cand, int pref[][MAX], double notas[][MAX]);
void remove_cand(int clas_cand, int num_cand, int pref[][MAX]);
int classifica(int num_cand, int pref[][MAX], double medias[MAX]);

int main() {
    
    /* Declaracao das variaveis utilizadas */
    int i, j, num_cand, pref[MEM][MAX];
    double medias[MAX], notas[MEM][MAX];
    
    /* Obtencao do numero de candidatos e suas notas */
    scanf("%d", &num_cand);
    
    for (i = 0; i < MEM; i++)
        for (j = 0 ; j < num_cand; j++)
            scanf("%lf", &notas[i][j]);
        
    /* Calcula media de cada candidato */
    for (j = 0; j < num_cand; j++)    
        calcula_media(j, num_cand, medias, notas);
    
    /* Calcula media de cada candidato */
    for (i = 0; i < MEM; i++)
        det_pref(i, num_cand, pref, notas);
    
    /* Imprime as medias com uma casa de precisao */
    printf ("Nota Media:");
    for (j = 0 ; j < num_cand; j++)
        printf(" %.1f", medias[j]);
    
    /* Imprime a preferencia dos membros da comissao */
    printf ("\n\nPreferencia:");
    for (i = 0; i < MEM; i++){
        printf ("\nMembro %d:", i + 1);
        for (j = 0 ; j < num_cand; j++)
            printf(" %d", pref[i][j]);
    }
    
    /* Imprime a classificacao dos candidatos */
    printf ("\n\nClassificacao:");
    for (j = 0; j < num_cand; j++)
        printf (" %d", classifica(num_cand, pref, medias));
    
    printf("\n");
    
    return 0;
}

/* Define o candidato classificado com base nas preferencias recebidas */
int classifica(int num_cand, int pref[][MAX], double medias[MAX]){
    
    int j, maior, pos_maior, pos_emp, flag_emp, mult_emp, classificado = -1, votos[MAX];
    
    /* Zera o vetor de votos */
    for (j = 0; j < MAX; j++)
        votos[j] = 0;
    
    /* Indica quantos votos cada candidato obteve */
    for (j = 0; j < MEM; j++)
        votos[pref[j][0]-1]++;
   
    /* Laco que se repete ate um candidato ser classificado */
    while (classificado == -1){
    /* Encontra o candidato com o maior numero de votos */    
        maior = votos[0];
        for (j = 0; j < num_cand; j++)
            if (votos[j] >= maior){
                maior = votos[j];
                pos_maior = j;
            }
            
    /* Verifica se ha empate e armazena a posicao do empate, tratados em pares*/
            flag_emp = 0;
            for (j = 0; j < num_cand && flag_emp == 0; j++)
                if (votos[j] == maior && j != pos_maior){
                    flag_emp = 1;
                    pos_emp = j;
                }
                
    /* Se há empate considera as medias e se necessario, a inscricao do candidato */
            if (flag_emp == 1){
                if (medias[pos_maior] > medias[pos_emp])
                    votos[pos_emp] = 0;
                else if (medias[pos_maior] < medias[pos_emp])
                    votos[pos_maior] = 0;
    /* Se for necessario considerar a inscricao, verifica se nao ha mais empates possiveis */
                else if (medias[pos_maior] == medias[pos_emp]){
                    mult_emp = 0;
                    for (j = 0; j < num_cand; j++)
                        if (votos[j] == 1 && j != pos_maior && j != pos_emp){
                            mult_emp = 1;
                        }
                        if (mult_emp == 1){
                            votos[pos_maior] = 0;
                        }
                        else{
                            if (pos_maior < pos_emp)
                                classificado = (pos_maior + 1);
                            else
                                classificado = (pos_emp + 1);
                        }
                    }
            }
            else
                classificado = (pos_maior + 1);
    }
    
    /* Retorna o candidato classificado da lista e o remove da lista de preferencias */
    remove_cand(classificado, num_cand, pref);
    return classificado;
}

/* Remove o candidato classificado da lista de preferencias */
void remove_cand(int classificado, int num_cand, int pref[][MAX]){
    
    int i, j, k;
    
    /* Encontra um valor e o remove da matriz, deslocando as casas a direita para a esquerda */
    for (i = 0; i < MEM; i++)
        for (j = 0; j < (num_cand-1); j++)
            if (pref[i][j] == classificado)
                for (k = j; k < num_cand-1; k++)
                    pref[i][k] = pref[i][k + 1];
}

/* Calcula a media das notas de cada candidato */
void calcula_media(int j, int num_cand, double medias[MAX], double notas[][MAX]){
    
    int julg;
    double soma = 0;
    
    /* Soma as notas */
    for (julg = 0; julg < MEM; julg++)
        soma += notas[julg][j];
    
    /* Calcula a media aritmetica das notas */
    medias[j] = soma/MEM;
}

/* Determina a preferencia de cada membro com base nas notas atrbuidas */
void det_pref(int i, int num_cand, int pref[][MAX], double notas[][MAX]){
    
    int j, k, cand_maior;
    double maior_nota;
    
    /* Ordena os candidatos pelas suas notas de cada membro da comissao */
    for (k = 0; k < num_cand; k++){
        maior_nota = -1;
        for (j = 0 ; j < num_cand; j++)
            if (notas[i][j] > maior_nota){
                maior_nota = notas[i][j];
                cand_maior = j;
            }
        pref[i][k] = cand_maior + 1;
        notas[i][cand_maior] = -1;
    }
}

/* OBS: O tamanho do programa se deve ao fato de ser facilmente expansivel para 
 * mais membros na comissao, bastando alterar o valor definido por 'MEM' apenas */