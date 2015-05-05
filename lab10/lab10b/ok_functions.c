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
    
    int i, j, k;

    for (i = a - 1, k = b; i > 0; i--, k--)
        for (j = i; j < k - 1; j++)
            troca_valores(&permutacao[j], &permutacao[j+1]);        
}

void imprime_vetor(int tam_vet, int vetor[]){
    
    int i;
    
    printf("(");
    for (i = 1; i <= tam_vet; i++)
        (i == tam_vet) ? printf("%d)", vetor[i]) : printf("%d ", vetor[i]);
    printf("\n");
}

int main() {

    int tam_perm;
    int i, a, b, peso;
    int permutacao[MAX];
    
    scanf ("%d", &tam_perm);
    
    for (i = 1; i <= tam_perm; i++)
        scanf ("%d", &permutacao[i]);
    
    permutacao[0] = 0;
    permutacao[tam_perm + 1] = tam_perm + 1;
    
    do{
        printf ("a: ");
        scanf ("%d", &a);
        printf ("b: ");
        scanf ("%d", &b);
        imprime_vetor(tam_perm, permutacao);
        transp_prefixo(tam_perm, permutacao, a, b);
        imprime_vetor(tam_perm, permutacao);
    } while (a != -1 || b != -1);
}