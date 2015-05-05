#include <stdio.h>
#define MAX 10

int main(){
    
    int i, aponta, menor, tam;
    int vetor[MAX][2];
    
    scanf("%d", &tam);
    
    for (i = 0; i < tam; i++)
        scanf ("%d", &vetor[i][1]);
    
    for (aponta = 0; aponta < tam; aponta++){
        for (i = 0, menor = vetor[aponta][1]; i < tam; i++)
            if (vetor[i][1] < menor){
                menor = vetor[i][1];
            }
        vetor[aponta][2] = menor;
    }
    
    for (i = 0; i < tam; i++)
        printf ("%d ", vetor[i][2]);
        
    return 0;
}