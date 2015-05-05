#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void nRainhas(int rainhas[], int n, int size);
int valida(int rainhas[], int k);

void imprime_vetor(int vetor[], int n) {

    int i;
    
    for (i = 0; i <= n - 1; i++)
        printf("%d ", vetor[i]);
    
    printf("\n");
}

int main() {
   
    int n, *rainhas;
    
    printf("Numero de rainhas: ");
    scanf("%d", &n);
    rainhas = malloc(n * sizeof(int));
    
    /* Inicialmente nenhuma das n rainhas esta posicionada */
    nRainhas(rainhas, n, 0);
    
    free(rainhas);

    return 0;
}

void nRainhas(int rainhas[], int n, int size) {
   
    int i;
    
    if (size == n)
        imprime_vetor(rainhas, n);
    else
        for (i = 1; i <= n; i++) {
            rainhas[size] = i;
            if (valida(rainhas, size))
                nRainhas(rainhas, n, size + 1);
        }
}

int valida(int rainhas[], int k) {

    int i;
    
    for (i = 0; i < k; i++)
    /* Se duas rainhas estao na mesma coluna... */
        if ((rainhas[i] == rainhas[k]) ||
    /* ... ou estao na mesma diagonal ... */
            (abs(rainhas[i] - rainhas[k]) == (k - i)))
    /* ... entao a solucao eh invalida */
            return 0;
    /* Solucao valida */
    return 1;
}