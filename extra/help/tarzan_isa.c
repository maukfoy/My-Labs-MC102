#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    int *x, *y, N, D, i, falha = 1, j;

    scanf("%d %d", &N, &D);

    x = malloc(N * sizeof(int));
    y = malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
        scanf("%d %d", &x[i], &y[i]);

    for (i = 0; i < N && falha; i++) {
        falha = 0;
        for (j = 0; j < N && (falha == 0); j++) {
            if ((sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) <= D) && (i !=
j)) {
                /* Fala que essa arvore nao falha, ta ok */
                falha = 1;
            }
        }
    }

    if (falha)
        printf("S\n");
    else
        printf("N\n");

    free(x);
    free(y);
    
    return 0;
}