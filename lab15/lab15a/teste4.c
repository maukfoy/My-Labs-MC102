#include <stdio.h>
#include <stdlib.h>

void arranjo_repeticao(int n, int r, int x[], int k) {
    
    int i;
    
    if (k == r){
        for (i = 0; i < r; i++)
            printf("%d ", x[i] + 1);
        printf("\n");
    }
    
    else{
        for (i = 0; i < n; i++){
            x[k] = i;
            arranjo_repeticao(n, r, x, k + 1);
        }
    }
}
int main(){
    
    int n, r, *x;
    
    printf("Entre com o valor de n: ");
    scanf("%d", &n);
    
    printf("Entre com o valor de r: ");
    scanf("%d", &r);
    
    x = malloc(r * sizeof(int));
    
    arranjo_repeticao(n, r, x, 0);
    
    free(x);
    
    return 0;
}