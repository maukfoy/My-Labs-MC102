#include <stdio.h>

#define NDIG 9
#define OPER 3

void geraArranjo(int permutacao[], int indice) {
    
    int i;
    
    if (indice == NDIG){
        for (i = 0; i < NDIG; i++)
            printf("%d ", permutacao[i]);
        printf("\n");
    }
    
    else{
        for (i = 0; i < OPER; i++){
            permutacao[indice] = i;
            geraArranjo(permutacao, indice + 1);
        }
    }
}

int main(){
    
    int vetor[NDIG];
    
    geraArranjo(vetor, 0);
    
    return 0;
}