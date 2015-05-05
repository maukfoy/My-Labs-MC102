/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 10b - DON'T PANIC - Part I */

#include <stdio.h>
#include <stdlib.h>
#define MAX 102

/* Declaracao por prototipos das funcoes utilizadas: */
void le_dados(int *tam_perm, int permutacao[]);
void transp_prefixo(int tam_perm, int permutacao[], int a, int b);
void imprime_vetor(int tam_vet, int vetor[]);
int acha_bp(int tam_perm, int permutacao[], int inicio);
int bp_removidos(int permutacao[], int a, int b);
void define_transposicao(int tam_perm, int permutacao[], int *a, int *b);

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

/* Imprime o vetor das panquecas na tela */
void imprime_vetor(int tam_vet, int vetor[]){
    
    int i;
    
    /* Condicoes para impressao de '(' e ')' */
    printf("(");
    for (i = 1; i <= tam_vet; i++)
        (i == tam_vet) ? printf("%d)", vetor[i]) : printf("%d ", vetor[i]);
    printf("\n");
}

/* Retorna o ponto onde a ordenacao eh quebrada a partir da posicao 'inicio' */
int acha_bp(int tam_perm, int permutacao[], int inicio){
    
    int i;
    
    for (i = inicio+1; i <= tam_perm; i++)
        if (permutacao[i] - permutacao[i-1] != 1)
            return i;
    return i;
}

/* Retorna quantos breakpoints sao removidos numa transposicao entre a e b */
int bp_removidos(int permutacao[], int a, int b){
    
    int removidos = 0;
    
    if (permutacao[b] - permutacao[a-1] == 1)removidos++;
    if (permutacao[1] - permutacao[b-1] == 1)removidos++;
    return removidos;
}

/* Retorna em 'a' e 'b' a melhor transposicao de menor peso possivel */
void define_transposicao(int tam_perm, int permutacao[], int *a, int *b){
    
    int i, a_bp, b_bp, removidos = 0;
    
    /* Encontra o final da primeira strip e fixa como ponto inicial da
transposicao */
    a_bp = acha_bp(tam_perm, permutacao, 1);
    b_bp = a_bp;
    
    /* Altera o segundo ponto da transposicao ate que a mesma possa remover
breakpoints */
    while (removidos == 0){
        b_bp = acha_bp(tam_perm, permutacao, b_bp);
        removidos = bp_removidos(permutacao, a_bp, b_bp);
    }
    
    /* Tenta encontrar um ponto inicial para a transposicao remover dois
breakpoints.
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

int main(){

    /* Declaracao das variaveis utilizadas */
    int tam_perm, a, b, peso = 0, permutacao[MAX];
    
    /* Le os dados da entrada e prepara as posicoes auxiliares na permutacao */
    le_dados(&tam_perm, permutacao);
    
    /* Loop principal, se repete ate nao haverem breakpoints no vetor */
    while (acha_bp(tam_perm, permutacao, 1) < tam_perm+1) {
        define_transposicao(tam_perm, permutacao, &a, &b);
        imprime_vetor(tam_perm, permutacao);
        transp_prefixo(tam_perm, permutacao, a, b);
        peso += b-1;
    }
    
    /* Impressao do vetor ordenado e do peso das transposicoes feitas */
    imprime_vetor(tam_perm, permutacao);
    printf ("Peso: %d\n", peso);
    
    return 0;
}
