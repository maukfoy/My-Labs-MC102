#include <stdio.h>
#include <stdlib.h>

void permutacao(int n, int temp[], int size);

void imprime_vetor(int vetor[], int n){
    
    int i;
    
    for (i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    
    printf("\n");
    
}

int main() {
    
    int n, *temp;
    
    printf("Entre com o valor de n: ");
    scanf("%d", &n);
    
    temp = malloc(n * sizeof(int));
    
    permutacao(n, temp, 0);
    
    free(temp);
    
    return 0;
}

void permutacao(int n, int temp[], int size) {
    
    int i, j, used;
    
    if (size == n)
        imprime_vetor(temp, n);
    
    else
        for (i = 1; i <= n; i++) {
            used = 0;
            
            for (j = 0; (j < size) && !used; j++)
                if (temp[j] == i)
                    used = 1;
                
            if (!used) {
                temp[size] = i;
                permutacao(n, temp, size + 1);
            }
        }
}
