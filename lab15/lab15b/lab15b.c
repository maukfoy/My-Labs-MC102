/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 15b - DON'T PANIC - Part II */

#include <stdio.h>
#include <stdlib.h>

/* Maximo de 13 panquecas e mais 2 posicoes auxiliares */
#define MAX 15

/* Prototipo das funcoes utilizadas no programa e breve resumo de seu uso */

/* Le os dados da entrada */
void le_dados(int *tam_perm, int permutacao[]);

/* Realiza uma transposicao de prefixo (a,b) */
void transp_prefixo(int tam_perm, int permutacao[], int a, int b);

/* Retorna o indice do proximo breakpoint a partir de 'inicio' */
int acha_bp(int tam_perm, int permutacao[], int inicio);

/* Retorna quantos breakpoints seriam removidos com a transposicao (a,b) */
int bp_removidos(int permutacao[], int a, int b);

/* Define a melhor transposicao segundo as regras do algoritmo */
void define_transposicao(int tam_perm, int permutacao[], int *a, int *b);

/* Retorna o limitante inferior de uma permutacao */
int limit_inferior(int tam_perm, int permutacao[]);

/* Copia um vetor 'origem' em outro 'destino' */
void copia_vetor(int tam_perm, int origem[], int destino[]);

/* Armazena em *pesoMin o menor peso possivel de se ordenar uma permutacao */
void otimizacao_peso(int tam_perm, int permutacao[], int supLimit,
                     int peso_entrada, int *pesoMin);

int main(){
    
    /* Declaracao das variaveis utilizadas */
    int tam_perm;
    int a, b, infLimit = 0, supLimit = 0, pesoMin = 0;
    int permutacao[MAX], clone_perm[MAX];
    
    /* Le os dados da entrada e prepara as posicoes auxiliares na permutacao */
    le_dados(&tam_perm, permutacao);
    
    /* Copia a permutacao para ser usada em outro algoritmo depois */
    copia_vetor(tam_perm, permutacao, clone_perm);
    
    /* Encontra o limitante inferior em 'infLimit' */
    infLimit = limit_inferior(tam_perm, permutacao);
    
    /* Algoritmo da Parte I, encontra o limitante superior em 'supLimit' */
    /* Repete o loop ateh nao haverem mais breakpoints */
    while (acha_bp(tam_perm, permutacao, 1) < tam_perm+1) {
        define_transposicao(tam_perm, permutacao, &a, &b);
        transp_prefixo(tam_perm, permutacao, a, b);
        supLimit += b - 1;
    }
    
    /* Define o peso minimo como o limite superior, se um peso menor for
     * encontrado, esse valor eh atualizado */
    pesoMin = supLimit;
    
    /* Algoritmo que encontra o peso minimo possivel de ordenacao */
    otimizacao_peso(tam_perm, clone_perm, supLimit, 0, &pesoMin);
    
    /* Impressao do vetor ordenado e do peso das transposicoes feitas */
    printf ("Limitante inferior: %d\n", infLimit);
    printf ("Peso: %d\n", pesoMin);
    printf ("Limitante superior: %d\n", supLimit);
    
    return 0;
}

/* Le a permutacao e o tamanho dela da entrada */
void le_dados(int *tam_perm, int permutacao[]){
    
    int i;
    
    /* Leitura dos dados referentes as panquecas */
    scanf ("%d", tam_perm);
    
    for (i = 1; i <= *tam_perm; i++)
        scanf ("%d", &permutacao[i]);
    
    /* Definicao das posicoes auxiliares para os calculos */
    permutacao[0] = 0;
    permutacao[*tam_perm + 1] = *tam_perm + 1;
}

/* Realiza uma transposicao de prefixo (a,b) */
void transp_prefixo(int tam_perm, int permutacao[], int a, int b){
    
    int i, j, *temp;
    
    temp = malloc(b * sizeof(int));
    
    /* Copia a segunda strip em 'temp' */
    for (i = a, j = 0; i < b; i++, j++)
        temp[j] = permutacao[i];
    
    /* Copia a primeira strip em 'temp' */
    for (i = 1, j = (b-a); i < a; i++, j++)
        temp[j] = permutacao[i];
    
    /* Copia as strips transpostas na permutacao */
    for (i = 1, j = 0; i < b; i++, j++)
        permutacao[i] = temp[j];
    
    free(temp);
}

/* Retorna o ponto onde a ordenacao eh quebrada a partir da posicao 'inicio' */
int acha_bp(int tam_perm, int permutacao[], int inicio){
    
    int i = inicio + 1;
    
    while (permutacao[i] - permutacao[i-1] == 1 && i < (tam_perm + 1))
        i++;
    return i;
}

/* Retorna quantos breakpoints sao removidos numa transposicao entre a e b */
int bp_removidos(int permutacao[], int a, int b){
    
    int removidos = 0;
    
    /* Testa cada possivel remocao de breakpoint */
    if (permutacao[b] - permutacao[a-1] == 1)removidos++;
    if (permutacao[1] - permutacao[b-1] == 1)removidos++;
    return removidos;
}

/* Retorna em 'a' e 'b' a melhor transposicao de menor peso possivel */
void define_transposicao(int tam_perm, int permutacao[], int *a, int *b){
    
    int i, a_bp, b_bp, removidos = 0;
    
    /* Encontra o final da primeira strip e fixa como ponto inicial da
     * transposicao */
    a_bp = acha_bp(tam_perm, permutacao, 1);
    b_bp = a_bp;
    
    /* Altera o segundo ponto da transposicao ate que a mesma possa remover
     * breakpoints */
    while (removidos == 0){
        b_bp = acha_bp(tam_perm, permutacao, b_bp);
        removidos = bp_removidos(permutacao, a_bp, b_bp);
    }
    
    /* Tenta encontrar um ponto inicial para a transposicao remover dois
     * breakpoints.
     * Armazena nas variaveis 'a' e 'b' os pontos da transposicao */
    switch (removidos){
        case 1:
            for (i = a_bp; i < b_bp; i = acha_bp(tam_perm, permutacao, i))
                if (bp_removidos(permutacao, i, b_bp) == 2){
                    *a = i;
                    *b = b_bp;
                    return;
                }
        case 2:
            *a = a_bp;
            *b = b_bp;
            return;
    }
}

/* Encontra o valor do limitante inferior da permutacao */
int limit_inferior(int tam_perm, int permutacao[]){
    
    int i, limitante = 0;
    
    for (i = 1; i <= tam_perm; i++)
        if (i != permutacao[i] && permutacao[i] > limitante)
            limitante = permutacao[i];
    
    return limitante;
}

/* Copia o vetor 'origem' no vetor 'destino' de mesmo tamanho */
void copia_vetor(int tam_perm, int origem[], int destino[]){
    
    int i;
    
    for (i = 0; i <= (tam_perm + 1); i++)
        destino[i] = origem[i];
}

/* Encontra o menor peso possivel para ordenacao por transposicao de prefixo */
void otimizacao_peso(int tam_perm, int permutacao[], int supLimit,
                     int peso_entrada, int *pesoMin){
    
    /* Declaracao das variaveis utilizadas */
    int a, b, peso, temp[MAX];
    
    /* Testa todas transposicoes (a,b) possiveis */
    for (a = 2; a <= tam_perm; a++) {
        for (b = a + 1; b <= tam_perm + 1; b++) {            
            /* Reinicializa o peso e testa cada transposicao */
            peso = peso_entrada;
            copia_vetor(tam_perm, permutacao, temp);
            transp_prefixo(tam_perm, temp, a, b);
            peso += b - 1;
            
            /* Se a permutacao estiver ordenada E o peso da ordenacao for 
             * menor que o limitante superior, o valor do peso minimo eh
             * atualizado para esse novo peso encontrado */
            if ((limit_inferior(tam_perm, temp) == 0) && peso < *pesoMin)
                *pesoMin = peso;
            
            /* Se nao estiver ordenado mas a solucao ainda for uma possivel
             * candidata, ou seja, menor que o limitante, invoca essa mesma
             * funcao recursivamente e testa esse ramo de possibilidades */
            else if ((peso + limit_inferior(tam_perm, temp)) < supLimit)
                otimizacao_peso(tam_perm, temp, supLimit, peso, pesoMin);
        }
    }
}
