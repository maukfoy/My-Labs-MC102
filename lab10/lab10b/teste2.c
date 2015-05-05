/* teste */

#include <stdio.h>
#define MAX 102

void troca_valores(int *a, int *b){
    
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux; 
}

void transp_prefixo(int tam_perm, int permutacao[], int a, int b){
    
    int i, j;

    for (i = a - 1; i > 0; i--, b--)
        for (j = i; j < b - 1; j++)
            troca_valores(&permutacao[j], &permutacao[j+1]);        
}

void imprime_vetor(int tam_vet, int vetor[]){
    
    int i;
    
    printf("(");
    for (i = 1; i <= tam_vet; i++)
        (i == tam_vet) ? printf("%d)", vetor[i]) : printf("%d ", vetor[i]);
    printf("\n");
}

int acha_bp(int tam_perm, int permutacao[], int inicio){
    
    int i;
    
    for (i = inicio+1; i <= tam_perm; i++)
        if (permutacao[i] - permutacao[i-1] != 1)
            return i;    
}

int bp_removidos(int permutacao[], int a, int b){
    
    int removidos = 0;
    
    if (permutacao[b] - permutacao[a-1] == 1)removidos++;
    if (permutacao[1] - permutacao[b-1] == 1)removidos++;
    return removidos;
}

void define_transposicao(int tam_perm, int permutacao[], int *a, int *b){
    
    int i, a_bp, b_bp, removidos = 0;
    
    a_bp = acha_bp(tam_perm, permutacao, 1);
    b_bp = acha_bp(tam_perm, permutacao, a_bp);
    while (removidos == 0){
        if (bp_removidos(permutacao, a_bp, b_bp) >= 1){
            removidos = bp_removidos(permutacao, a_bp, b_bp);
        }
        else {
            b_bp = acha_bp(tam_perm, permutacao, b_bp);
        }
    }
    switch (removidos){
        case 1:
            *a = a_bp;
            *b = b_bp;
            for (i = a_bp; i < b_bp; i = acha_bp(tam_perm, permutacao, i)){
                if (bp_removidos(permutacao, i, b_bp) == 2){
                    *a = i;
                    *b = b_bp;
                    return;
                }
            }
            return;
            break;
        case 2:
            *a = a_bp;
            *b = b_bp;
            return;
    }
}

int main() {

    int tam_perm;
    int i, a, b, inicio, peso = 0;
    int permutacao[MAX];
    
    scanf ("%d", &tam_perm);
    
    for (i = 1; i <= tam_perm; i++)
        scanf ("%d", &permutacao[i]);
    
    permutacao[0] = 0;
    permutacao[tam_perm + 1] = tam_perm + 1;
    
    while (acha_bp(tam_perm, permutacao, 1) < tam_perm+1) {
        define_transposicao(tam_perm, permutacao, &a, &b);
        imprime_vetor(tam_perm, permutacao);
        transp_prefixo(tam_perm, permutacao, a, b);
        peso += b-1;
    }
    
    imprime_vetor(tam_perm, permutacao);
    printf ("Peso: %d\n", peso);
    return 0;
}